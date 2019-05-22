#!/usr/bin/python3 -i
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
# Copyright (c) 2018-2019 Valve Corporation
# Copyright (c) 2018-2019 LunarG, Inc.
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

# The content of this file was derived from the Khronos Registry cgenerator.py
# and related Python files found in the KhronosGroup/Vulkan-Headers GitHub repository.

import os,re,sys,json
from generator import (GeneratorOptions, OutputGenerator, noneStr, regSortFeatures, write)
from vkconventions import VulkanConventions

# Turn a list of strings into a regexp string matching exactly those strings.
# From Khronos genvk.py
def _makeREstring(list, default = None):
    if (len(list) > 0) or (default is None):
        return '^(' + '|'.join(list) + ')$'
    else:
        return default

# Descriptive names for various regexp patterns used to select versions and extensions.
# From Khronos genvk.py
_defaultExtensions  = 'vulkan'
_extensions         = _features         = []
_removeExtensions   = _emitExtensions   = []

# Turn lists of names/patterns into matching regular expressions.
# From Khronos genvk.py
_addExtensionsPat     = _makeREstring(_extensions)
_removeExtensionsPat  = _makeREstring(_removeExtensions)
_emitExtensionsPat    = _makeREstring(_emitExtensions, '.*')
_featuresPat          = _makeREstring(_features, '.*')


# ValueInfo - Class to store parameter/struct member information.
#
# Members:
#   name - Parameter/struct member name of the value.
#   baseType - Undecorated typename of the value.
#   fullType - Fully qualified typename of the value.
#   pointerCount - Number of '*' characters in the type declaration.
#   arrayLength - The parameter that specifies the number of elements in an array, or None if the value is not an array.
#   arrayCapacity - The max size of a statically allocated array, or None for a dynamically allocated array.
#   platformBaseType - For platform specific type definitions, stores the original baseType declaration before platform to trace type substitution.
#   platformFullType - For platform specific type definitions, stores the original fullType declaration before platform to trace type substitution.
#   isPointer - True if the value is a pointer.
#   isArray - True if the member is an array.
#   isDynamic - True if the memory for the member is an array and it is dynamically allocated.
class ValueInfo():
    """Contains information descripting Vulkan API call parameters and struct members"""
    def __init__(self,
                 name,
                 baseType,
                 fullType,
                 pointerCount = 0,
                 arrayLength = None,
                 altArrayLength = None,
                 arrayCapacity = None,
                 platformBaseType = None,
                 platformFullType = None):
        self.name = name
        self.baseType = baseType
        self.fullType = fullType
        self.pointerCount = pointerCount
        self.arrayLength = arrayLength
        self.altArrayLength = altArrayLength
        self.arrayCapacity = arrayCapacity
        self.platformBaseType = platformBaseType
        self.platformFullType = platformFullType

        self.isPointer = True if pointerCount > 0 else False
        self.isArray = True if arrayLength else False
        self.isDynamic = True if not arrayCapacity else False


# BaseGeneratorOptions - subclass of GeneratorOptions.
#
# Adds options used by FrameworkGenerator objects during C++ language
# code generation.
#
# Additional members
#   blacklists - Path to JSON file listing apicalls and structs to ignore.
#   platformTypes - Path to JSON file listing platform (WIN32, X11, etc.)
#     specific types that are defined outside of the Vulkan header.
#
# Additional members (from Khronos Registry COptionsGenerator)
#   prefixText - list of strings to prefix generated header with
#     (usually a copyright statement + calling convention macros).
#   protectFile - True if multiple inclusion protection should be
#     generated (based on the filename) around the entire header.
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
class BaseGeneratorOptions(GeneratorOptions):
    """Options for Vulkan API parameter encoding and decoding C++ code generation"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 # Khronos CGeneratorOptions
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True,
                 conventions = VulkanConventions(),
                 apicall = 'VKAPI_ATTR ',
                 apientry = 'VKAPI_CALL ',
                 apientryp = 'VKAPI_PTR *',
                 indentFuncProto = True,
                 alignFuncParam = 48,
                 sortProcedure = regSortFeatures,
                 apiname = 'vulkan',
                 profile = None,
                 versions = _featuresPat,
                 emitversions = _featuresPat,
                 defaultExtensions = _defaultExtensions,
                 addExtensions = _addExtensionsPat,
                 removeExtensions = _removeExtensionsPat,
                 emitExtensions = _emitExtensionsPat):
        GeneratorOptions.__init__(self, conventions, filename, directory, apiname, profile,
                                  versions, emitversions, defaultExtensions,
                                  addExtensions, removeExtensions,
                                  emitExtensions, sortProcedure)
        self.blacklists = blacklists
        self.platformTypes = platformTypes
        # Khronos CGeneratorOptions
        self.prefixText      = prefixText
        self.protectFile     = protectFile
        self.protectFeature  = protectFeature
        self.apicall         = apicall
        self.apientry        = apientry                  # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.apientryp       = apientryp                 # NOTE: While not used in this file, apientry is expected to be defined here by the OutputGenerator base class.
        self.indentFuncProto = indentFuncProto
        self.alignFuncParam  = alignFuncParam


# BaseGenerator - subclass of OutputGenerator.
# Base class providing common operations used to generate C++-language code for framework
#   components that encode and decode Vulkan API parameters.
class BaseGenerator(OutputGenerator):
    """Base class for Vulkan API parameter encoding and decoding generators."""
    # These API calls should not be processed by the code generator.  They require special implementations.
    APICALL_BLACKLIST = []

    # These structures should not be processed by the code generator.  They require special implementations.
    STRUCT_BLACKLIST = []

    # Platform specific basic types that have been defined extarnally to the Vulkan header.
    PLATFORM_TYPES = {}

    # Platform specific structure types that have been defined extarnally to the Vulkan header.
    PLATFORM_STRUCTS = []

    # These types represent pointers to non-Vulkan objects that were written as 64-bit address IDs.
    EXTERNAL_OBJECT_TYPES = ['void', 'Void']

    # Dispatchable handle types.
    DISPATCHABLE_HANDLE_TYPES = ['VkInstance', 'VkPhysicalDevice', 'VkDevice', 'VkQueue', 'VkCommandBuffer']

    # Default C++ code indentation size.
    INDENT_SIZE = 4

    def __init__(self,
                 processCmds,
                 processStructs,
                 featureBreak = True,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        OutputGenerator.__init__(self, errFile, warnFile, diagFile)

        # Typenames
        self.structNames = set()                          # Set of Vulkan struct typenames
        self.handleNames = set()                          # Set of Vulkan handle typenames
        self.flagsNames = set()                           # Set of bitmask (flags) typenames
        self.enumNames = set()                            # Set of Vulkan enumeration typenames

        # Type processing options
        self.processCmds = processCmds                    # Populate the featureCmdParams map
        self.processStructs = processStructs              # Populate the featureStructMembers map
        self.featureBreak = featureBreak                  # Insert a line break between features

        # Command parameter and struct member data for the current feature
        if self.processStructs:
            self.featureStructMembers = dict()            # Map of struct names to lists of per-member ValueInfo
            self.featureStructAliases = dict()            # Map of struct names to aliases
        if self.processCmds:
            self.featureCmdParams = dict()                # Map of cmd names to lists of per-parameter ValueInfo

    #
    # Indicates that the current feature has C++ code to generate.
    # The subclass should override this method.
    def needFeatureGeneration(self):
        return False

    #
    # Performs C++ code generation for the feature.
    # The subclass should override this method.
    def generateFeature(self):
        pass

    # Method override
    def beginFile(self, genOpts):
        OutputGenerator.beginFile(self, genOpts)

        if genOpts.blacklists:
            self.__loadBlacklists(genOpts.blacklists)
        if genOpts.platformTypes:
            self.__loadPlatformTypes(genOpts.platformTypes)

            # Platform defined struct processing must be implemented manually,
            # so these structs will be added to the blacklist.
            self.STRUCT_BLACKLIST += self.PLATFORM_STRUCTS

        # User-supplied prefix text, if any (list of strings)
        if (genOpts.prefixText):
            for s in genOpts.prefixText:
                write(s, file=self.outFile)

        # Multiple inclusion protection & C++ wrappers.
        if (genOpts.protectFile and self.genOpts.filename):
            headerSym = 'GFXRECON_' + re.sub('\.h', '_H', os.path.basename(self.genOpts.filename)).upper()
            write('#ifndef ', headerSym, file=self.outFile)
            write('#define ', headerSym, file=self.outFile)
            self.newline()

    # Method override
    def endFile(self):
        # Finish C++ wrapper and multiple inclusion protection
        if (self.genOpts.protectFile and self.genOpts.filename):
            self.newline()
            write('#endif', file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFile(self)

    # Method override
    def beginFeature(self, interface, emit):
        # Start processing in superclass
        OutputGenerator.beginFeature(self, interface, emit)

        # Reset feature specific data sets
        if self.processStructs:
            self.featureStructMembers = dict()
            self.featureStructAliases = dict()
        if self.processCmds:
            self.featureCmdParams = dict()

        # Some generation cases require that extra feature protection be suppressed
        if self.genOpts.protectFeature:
            self.featureExtraProtect = self.__getFeatureProtect(interface)

    # Method override
    def endFeature(self):
        # Generate code for the feature
        if self.emit and self.needFeatureGeneration():
            if self.featureBreak:
                self.newline()

            if (self.featureExtraProtect is not None):
                write('#ifdef', self.featureExtraProtect, file=self.outFile)

            self.generateFeature()

            if (self.featureExtraProtect is not None):
                write('#endif /*', self.featureExtraProtect, '*/', file=self.outFile)

        # Finish processing in superclass
        OutputGenerator.endFeature(self)

    #
    # Type generation
    def genType(self, typeinfo, name, alias):
        OutputGenerator.genType(self, typeinfo, name, alias)
        typeElem = typeinfo.elem
        # If the type is a struct type, traverse the imbedded <member> tags
        # generating a structure. Otherwise, emit the tag text.
        category = typeElem.get('category')
        if (category == 'struct' or category == 'union'):
            self.structNames.add(name)
            # Skip code generation for union encode/decode functions.
            if category == 'struct':
                self.genStruct(typeinfo, name, alias)
        elif (category == 'handle'):
            self.handleNames.add(name)
        elif (category == 'bitmask'):
            self.flagsNames.add(name)

    #
    # Struct (e.g. C "struct" type) generation.
    # This is a special case of the <type> tag where the contents are
    # interpreted as a set of <member> tags instead of freeform C
    # C type declarations. The <member> tags are just like <param>
    # tags - they are a declaration of a struct or union member.
    def genStruct(self, typeinfo, typename, alias):
        OutputGenerator.genStruct(self, typeinfo, typename, alias)
        # For structs, we ignore the alias because it is a typedef.  Not ignoring the alias
        # would produce multiple definition errors for functions with struct parameters.
        if self.processStructs:
            if not alias:
                self.featureStructMembers[typename] = self.makeValueInfo(typeinfo.elem.findall('.//member'))
            else:
                self.featureStructAliases[typename] = alias

    #
    # Group (e.g. C "enum" type) generation.
    # These are concatenated together with other types.
    def genGroup(self, groupinfo, groupName, alias):
        OutputGenerator.genGroup(self, groupinfo, groupName, alias)
        self.enumNames.add(groupName)

    # Enumerant generation
    # <enum> tags may specify their values in several ways, but are usually
    # just integers.
    def genEnum(self, enuminfo, name, alias):
        OutputGenerator.genEnum(self, enuminfo, name, alias)

    #
    # Command generation
    def genCmd(self, cmdinfo, name, alias):
        OutputGenerator.genCmd(self, cmdinfo, name, alias)
        if self.processCmds:
            # Create the declaration for the function prototype
            proto = cmdinfo.elem.find('proto')
            protoDecl = self.genOpts.apicall + noneStr(proto.text)
            for elem in proto:
                text = noneStr(elem.text)
                tail = noneStr(elem.tail)
                if (elem.tag == 'name'):
                    if text.startswith('vk'):
                        text = text[2:]
                    protoDecl += self.makeProtoName(text, tail)
                else:
                    protoDecl += text + tail

            returnType = noneStr(proto.text) + noneStr(proto.find('type').text)

            # TODO: Define a class or namedtuple for the dictionary entry
            self.featureCmdParams[name] = (returnType, protoDecl, self.makeValueInfo(cmdinfo.elem.findall('param')))

    #
    # Generate a list of ValueInfo objects from a list of <param> or <member> tags
    #  params - list of <param> or <member> tags to process
    def makeValueInfo(self, params):
        values = []
        for param in params:
            # Get name
            elem = param.find('name')
            name = noneStr(elem.text) #+ noneStr(elem.tail)

            # Get type info
            elem = param.find('type')
            baseType = noneStr(elem.text)
            fullType = (noneStr(param.text) + baseType + noneStr(elem.tail)).strip()

            # Check for platform specific type definitions that need to be converted to a recognized trace format type.
            platformBaseType = None
            platformFullType = None
            if baseType in self.PLATFORM_TYPES:
                typeInfo = self.PLATFORM_TYPES[baseType]
                platformBaseType = baseType
                platformFullType = fullType
                fullType = fullType.replace(baseType, typeInfo['replaceWith'])
                baseType = typeInfo['baseType']

            # Get array length
            arrayLength = self.getArrayLen(param)
            altArrayLength =  param.attrib.get('altlen')
            arrayCapacity = None
            if self.isStaticArray(param):
                arrayCapacity = arrayLength
                arrayLength = self.getStaticArrayLen(name, params, arrayCapacity)

            values.append(ValueInfo(
                name = name,
                baseType = baseType,
                fullType = fullType,
                pointerCount = self.getPointerCount(fullType),
                arrayLength = arrayLength,
                altArrayLength = altArrayLength,
                arrayCapacity = arrayCapacity,
                platformBaseType = platformBaseType,
                platformFullType = platformFullType))

        return values

    #
    # Check for struct type
    def isStruct(self, baseType):
        if (baseType in self.structNames) or (baseType in self.PLATFORM_STRUCTS):
            return True
        return False

    #
    # Check for handle type
    def isHandle(self, baseType):
        if baseType in self.handleNames:
            return True
        return False

    #
    # Check for dispatchable handle type
    def isDispatchableHandle(self, baseType):
        if baseType in self.DISPATCHABLE_HANDLE_TYPES:
            return True
        return False

    #
    # Check for enum type
    def isEnum(self, baseType):
        if baseType in self.enumNames:
            return True
        return False

    #
    # Check for flags (bitmask) type
    def isFlags(self, baseType):
        if baseType in self.flagsNames:
            return True
        return False

    #
    # Check for function pointer type
    def isFunctionPtr(self, baseType):
        if baseType[:4] == 'PFN_':
            return True
        return False

    #
    # Determine if the value name specifies an array length
    def isArrayLen(self, name, values):
        for value in values:
            if name == value.arrayLength:
                return True
        return False

    #
    # Return the number of '*' in a type declaration
    def getPointerCount(self, fullType):
        return fullType.count('*')

    #
    # Determine if a pointer parameter is an input parameter
    def isInputPointer(self, value):
        if 'const' in value.fullType:
            # Vulkan seems to follow a pattern where input pointers will be const and output pointers will not be const.
            return True
        elif value.platformBaseType and value.baseType == 'void' and value.pointerCount == 1:
            # For some extensions, platform specific handles are mapped to the 'void*' type without a const qualifier,
            # but need to be treated as an input (eg. if HANDLE is mapped to void*, it should not be treated as an output).
            return True
        return False

    #
    # Determine if a parameter is an output parameter
    def isOutputParameter(self, value):
        # Check for an output pointer/array or an in-out pointer.
        if (value.isPointer or value.isArray) and not self.isInputPointer(value):
            return True
        return False

    #
    # Retrieve the length of an array defined by a <param> or <member> element
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
    # Check for a static array
    def isStaticArray(self, param):
        name = param.find('name')
        if (name.tail is not None) and ('[' in name.tail):
            return True
        return False

    #
    # Determine the length value of a static array (getArrayLen() returns the total capacity, not the actual length)
    def getStaticArrayLen(self, name, params, capacity):
        # The XML registry does not provide a direct method for determining if a parameter provides the length
        # of a static array, but the parameter naming follows a pattern of array name = 'values' and length
        # name = 'valueCount'.  We will search the parameter list for a length parameter using this pattern.
        lengthName = name[:-1] + 'Count'
        for param in params:
            if lengthName == noneStr(param.find('name').text):
                return lengthName

        # Not all static arrays have an associated length parameter. These will use capacity as length.
        return capacity

    #
    # Determines if a struct with the specified typename is blacklisted.
    def isStructBlackListed(self, typename):
        if typename in self.STRUCT_BLACKLIST:
            return True
        return False

    #
    # Determines if a struct with the specified typename is blacklisted.
    def isCmdBlackListed(self, name):
        if name in self.APICALL_BLACKLIST:
            return True
        return False

    #
    # Retrieves a filtered list of keys from self.featureStructMemebers with blacklisted items removed.
    def getFilteredStructNames(self):
        return [key for key in self.featureStructMembers if not self.isStructBlackListed(key)]

    #
    # Retrieves a filtered list of keys from self.featureCmdParams with blacklisted items removed.
    def getFilteredCmdNames(self):
        return [key for key in self.featureCmdParams if not self.isCmdBlackListed(key)]

    #
    # Determines if the specified struct type can reference pNext extension structs that contain handles.
    def checkStructPNextHandles(self, typename):
        validExtensionStructs = self.registry.validextensionstructs.get(typename)
        if validExtensionStructs:
            # Need to search the XML tree for pNext structures that have not been processed yet.
            for structName in validExtensionStructs:
                typeInfo = self.registry.lookupElementInfo(structName, self.registry.typedict)
                if typeInfo:
                    memberTypes = [member.text for member in typeInfo.elem.findall('.//member/type')]
                    if memberTypes:
                        for memberType in memberTypes:
                            found = self.registry.tree.find("types/type/[name='" + memberType + "'][@category='handle']")
                            if found:
                                return True
        return False

    #
    # Determines if the specified struct type contains members that have a handle type or are structs that contain handles.
    # Structs with member handles are added to a dictionary, where the key is teh structure type and the value is a list of the handle members.
    def checkStructMemberHandles(self, typename, structsWithHandles):
        handles = []
        for value in self.featureStructMembers[typename]:
            if self.isHandle(value.baseType):
                # The member is a handle.
                handles.append(value)
            elif self.isStruct(value.baseType) and (value.baseType in structsWithHandles):
                # The member is a struct that contains a handle.
                handles.append(value)
            elif 'pNext' in value.name:
                # The pNext chain may include a struct with handles.
                if self.checkStructPNextHandles(typename):
                    handles.append(value)
        if handles:
            structsWithHandles[typename] = handles
            return True
        return False

    #
    # Extract length value from latexmath expression.  Currently an inflexible solution that looks for specific
    # patterns that are found in vk.xml.  Will need to be updated when new patterns are introduced.
    def parseLateXMath(self, source):
        name = None

        # Extracts a parameter name from expressions similar to:
        #    'latexmath:[\lceil{\mathit{rasterizationSamples} \over 32}\rceil]'
        #    'latexmath:[\textrm{dataSize} \over 4]'
        match = re.match(r'latexmath.*\\(mathit|textrm)\s*\{\s*(\w+)\s*\}.*', source)
        if match:
            name = match.group(2)
        else:
            raise ValueError('Unrecognized latexmath expression: "' + source + '"')

        return name

    #
    # Indent all lines in a string.
    #  value - String to indent.
    #  spaces - Number of spaces to indent.
    def indent(self, value, spaces):
        prefix = ' ' * spaces
        return '\n'.join([prefix + v if v else v for v in value.split('\n')])

    #
    # Create a string containing a comma separated argument list from a list of ValueInfo values.
    #  values - List of ValueInfo objects providing the parameter names for the argument list.
    def makeArgList(self, values):
        return ', '.join([value.name for value in values])

    #
    # makeAlignedParamDecl - return an indented parameter declaration string with the parameter
    #  name aligned to the specified column.
    def makeAlignedParamDecl(self, paramType, paramName, indentColumn, alignColumn):
        paramDecl = ' ' * indentColumn
        paramDecl += paramType

        if alignColumn:
            paramDecl = paramDecl.ljust(alignColumn - 1)

        paramDecl += ' '
        paramDecl += paramName

        return paramDecl

    #
    # Convert a type name to a string to be used as part of an encoder/decoder function/method name.
    def makeInvocationTypeName(self, baseType):
        if self.isStruct(baseType):
            return baseType
        elif self.isHandle(baseType):
            return 'HandleId'
        elif self.isFlags(baseType):
            return 'Flags'
        elif self.isEnum(baseType):
            return 'Enum'
        elif baseType == 'wchar_t':
            return 'WString'
        elif baseType == 'char':
            return 'String'
        elif self.isFunctionPtr(baseType):
            return 'FunctionPtr'
        elif baseType == 'size_t':
            return 'SizeT'
        elif baseType == 'int':
            # Extensions use the int type when dealing with file descriptors
            return 'Int32'
        elif baseType.endswith('_t'):
            if baseType[0] == 'u':
                # For unsigned types, capitalize the first two characters.
                return baseType[0].upper() + baseType[1].upper() + baseType[2:-2]
            else:
                return baseType[:-2].title()
        elif baseType[0].islower():
            return baseType.title()

        return baseType

    #
    # Create a type to use for a decoded parameter, using the decoder wrapper types for pointers.
    def makeDecodedParamType(self, value):
        typeName = value.baseType

        # isPointer will be False for static arrays.
        if value.isPointer or value.isArray:
            count = value.pointerCount

            # We currently only expect the '*' count to be greater than one for the char** case
            if (count > 1) and (typeName != 'char') and (not typeName in self.EXTERNAL_OBJECT_TYPES):
                print("WARNING: Processing a multi-dimensional array that is not an array of strings ({})".format(typeName + ('*' * count)))

            if self.isStruct(typeName):
                typeName = 'StructPointerDecoder<Decoded_{}>'.format(typeName)
            elif typeName == 'wchar_t':
                if count > 1:
                    typeName = 'WStringArrayDecoder'
                else:
                    typeName = 'WStringDecoder'
            elif typeName == 'char':
                if count > 1:
                    typeName = 'StringArrayDecoder'
                else:
                    typeName = 'StringDecoder'
            elif typeName == 'void':
                if value.isArray:
                    # If this was an array (void*) it was encoded as an array of bytes.
                    typeName = 'PointerDecoder<uint8_t>'
                elif count > 1:
                    # If this was a pointer to a pointer to an unknown object (void**), it was encoded as a pointer to a 64-bit address value.
                    typeName = 'PointerDecoder<uint64_t>'
                else:
                    # If this was a pointer to an unknown object (void*), it was encoded as a 64-bit address value.
                    typeName = 'uint64_t'
            elif self.isHandle(typeName):
                typeName = 'HandlePointerDecoder<{}>'.format(typeName)
            else:
                typeName = 'PointerDecoder<{}>'.format(typeName)
        elif self.isFunctionPtr(typeName):
            # Function pointers are encoded as a 64-bit address value.
            typeName ='uint64_t'
        elif self.isStruct(typeName):
            typeName = 'Decoded_{}'.format(typeName)
        elif self.isHandle(typeName):
            typeName = 'format::HandleId'
        else:
            typeName = '{}'.format(typeName)

        return typeName

    #
    # makeConsumerDecl - return VulkanConsumer class member function declaration
    def makeConsumerFuncDecl(self, returnType, name, values):
        """Generate VulkanConsumer class member function declaration"""
        paramDecls = []

        if returnType != 'void':
            paramDecl = self.makeAlignedParamDecl(returnType, 'returnValue', self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        for value in values:
            paramType = self.makeDecodedParamType(value)

            # Pass pointer and struct wrappers by const reference
            if 'Decoder' in paramType or 'Decoded_' in paramType:
                paramType = 'const {}&'.format(paramType)

            paramDecl = self.makeAlignedParamDecl(paramType, value.name, self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if paramDecls:
            return 'void {}(\n{})'.format(name, ',\n'.join(paramDecls))

        return 'void {}()'.format(name)

    #
    # Generate the VkStructreType enumeration value for the specified structure type
    def makeStructureTypeEnum(self, typeinfo, typename):
        members = typeinfo.elem.findall('.//member')

        for member in members:
            membername = noneStr(member.find('name').text)

            # We only care about structures with an sType, which can be included in a pNext chain.
            if membername == 'sType':
                # Check for value in the XML element.
                values = member.attrib.get('values')

                if values:
                    return values
                else:
                    # If the value was not specified by the XML element, process the struct type to create it.
                    stype = re.sub('([a-z0-9])([A-Z])', r'\1_\2', typename)
                    stype = stype.replace('D3_D12', 'D3D12')
                    stype = stype.replace('Device_IDProp', 'Device_ID_Prop')
                    stype = stype.upper()
                    return re.sub('VK_', 'VK_STRUCTURE_TYPE_', stype)
        return None

    #
    # Generate a parameter encoder method call invocation.
    def makeEncoderMethodCall(self, value, values, prefix):
        args = [prefix + value.name]

        isStruct = False
        isString = False
        isFuncp = False

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            args = ['encoder'] + args
            isStruct = True
            methodCall = 'EncodeStruct'
        else:
            if typeName in ['String', 'WString']:
                isString = True
            elif typeName == 'FunctionPtr':
                isFuncp = True

            methodCall = 'encoder->Encode' + typeName

        if value.isArray and not (isString and not value.isDynamic):  # Make sure strings delcared as 'char s[N]' are not treated as string arrays
            # Some length parameters are specified as mathmatical expressions, which we need to parse to extract the parameter name from the expression.
            lengthName = value.arrayLength         # The parameter name that appears in the length expression
            lengthExpr = value.arrayLength         # The expression that produces the array length (needed for the latexmath case where param name != param expr)
            if 'latexmath' in value.arrayLength:
                lengthName = self.parseLateXMath(value.arrayLength)
                lengthExpr = value.altArrayLength

            methodCall += 'Array'

            # Build a list of parameter names and search for the array length value.
            lengthValue = None
            paramNames = []
            for v in values:
                if v.name == lengthName:
                    lengthValue = v
                paramNames.append(v.name)

            prefixedName = lengthExpr.replace(lengthName, prefix + lengthName)

            if lengthValue and lengthValue.isPointer:
                args.append('({name} != nullptr) ? (*{name}) : 0'.format(name=prefixedName))
            elif lengthName in paramNames:
                args.append(prefixedName)
            else:
                args.append(lengthExpr)     # Length is a constant value, not a parameter
        elif isStruct:
            if value.isPointer:
                methodCall += 'Ptr'
        elif not (isString or isFuncp):
            # Ignore string and function names, which do not use the Ptr/Value suffix
            if value.isPointer:
                methodCall += 'Ptr' * value.pointerCount
            else:
                methodCall += 'Value'

        return '{}({})'.format(methodCall, ', '.join(args))

    #
    # Return appropriate feature protect string from 'platform' tag on feature.
    # From Vulkan-ValidationLayers common_codegen.py
    def __getFeatureProtect(self, interface):
        # TODO: This should probably be in a JSON file.
        platform_dict = {
            'android' : 'VK_USE_PLATFORM_ANDROID_KHR',
            'fuchsia' : 'VK_USE_PLATFORM_FUCHSIA',
            'ios' : 'VK_USE_PLATFORM_IOS_MVK',
            'macos' : 'VK_USE_PLATFORM_MACOS_MVK',
            'mir' : 'VK_USE_PLATFORM_MIR_KHR',
            'vi' : 'VK_USE_PLATFORM_VI_NN',
            'wayland' : 'VK_USE_PLATFORM_WAYLAND_KHR',
            'win32' : 'VK_USE_PLATFORM_WIN32_KHR',
            'xcb' : 'VK_USE_PLATFORM_XCB_KHR',
            'xlib' : 'VK_USE_PLATFORM_XLIB_KHR',
            'xlib_xrandr' : 'VK_USE_PLATFORM_XLIB_XRANDR_EXT',
            'ggp' : 'VK_USE_PLATFORM_GGP'
        }

        platform = interface.get('platform')
        if platform and platform in platform_dict:
            return platform_dict[platform]
        return None

    def __loadBlacklists(self, filename):
        lists = json.loads(open(filename, 'r').read())
        self.APICALL_BLACKLIST += lists['functions']
        self.STRUCT_BLACKLIST += lists['structures']

    def __loadPlatformTypes(self, filename):
        platforms = json.loads(open(filename, 'r').read())
        for platform_name in platforms:
            platform = platforms[platform_name]
            platform_types = platform['types']

            for type in platform_types:
                self.PLATFORM_TYPES[type] = platform_types[type]

            platform_structs = platform['structs']
            if platform_structs:
                self.PLATFORM_STRUCTS += platform_structs
