#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
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

from base_generator import *
from reverse_alias_mapping import getReverseAliasMap
from vulkan_cpp_consumer_body_generator import CPP_CONSUMER_ADD_EXTENSION_PAT, CPP_CONSUMER_ADD_OPTIONAL_EXTENSION_PAT, \
    CPP_CONSUMER_REMOVE_EXTENSION_PAT, CPP_CONSUMER_VULKAN_VERSION_PAT, makeGen, makeGenCall, makeGenCastVar, makeGenCond, makeGenSwitch


class VulkanCppConsumerExtensionGeneratorOptions(BaseGeneratorOptions):
    """Options for generating pNext pointer cast cases"""

    def __init__(self,
                 blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
                 platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename=None,
                 directory='.',
                 prefixText='',
                 protectFile=False,
                 protectFeature=True,
                 versions=CPP_CONSUMER_VULKAN_VERSION_PAT,
                 addExtensions=CPP_CONSUMER_ADD_EXTENSION_PAT,
                 removeExtensions=CPP_CONSUMER_REMOVE_EXTENSION_PAT):
        BaseGeneratorOptions.__init__(self, blacklists=blacklists, platform_types=platform_types,
                                      filename=filename, directory=directory, prefixText=prefixText,
                                      protectFile=protectFile, protectFeature=protectFeature,
                                      versions=versions, defaultExtensions="dis",
                                      addExtensions=addExtensions,
                                      removeExtensions=removeExtensions)


# VulkanCppConsumerExtensionGenerator - subclass of BaseGenerator.
# Generates a C++ function responsible for generating extensions from pNext void pointers.
class VulkanCppConsumerExtensionGenerator(BaseGenerator):
    """Generates a function that casts an extension struct pointer to the proper type and then generates it into the output stream"""

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    def newline(self):
        write('', file=self.outFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        self.reverseAliasMap = getReverseAliasMap(self)
        self.is_header = genOpts.filename.endswith(".h")

        if self.is_header:
            self.writeout('#ifndef  GFXRECON_GENERATED_VULKAN_CPP_CONSUMER_EXTENSION_H')
            self.writeout('#define  GFXRECON_GENERATED_VULKAN_CPP_CONSUMER_EXTENSION_H')
            self.newline()

        if not self.is_header:
            self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
            self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "util/defines.h"')
        self.writeout('#include "vulkan/vulkan.h"')
        self.newline()
        self.writeout('#include <iostream>')
        self.writeout('#include <sstream>')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

    # Method override
    def endFile(self):

        if self.is_header:
            self.writeout('class VulkanCppConsumerBase;')
            self.writeout('std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer);')
        else:
            self.writeout(self.genExtensionGenFunction())

        self.newline()

        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')
        if self.is_header:
            self.newline()
            self.writeout('#endif')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def iterateFeatureExtStructs(self, feature):
        for value in feature['struct'].values():
            for structs in value.values():
                for extStruct in structs:
                    yield extStruct

    def genExtensionGenFunction(self):
        cases = []
        caseBodies = []

        for extension in self.featureDictionary:
            if not re.match(CPP_CONSUMER_ADD_EXTENSION_PAT, extension):
                continue
            feature = self.featureDictionary[extension]
            for extStruct in self.iterateFeatureExtStructs(feature):
                typeinfo = self.registry.typedict[extStruct]

                if 'alias' in typeinfo.elem.attrib:
                    typeinfo = self.registry.typedict[typeinfo.elem.attrib['alias']]

                sType = self.make_structure_type_enum(typeinfo, extStruct)
                if not sType:
                    continue
                cases.append(sType)
                caseBody = [
                    makeGenCastVar('reinterpret_cast', 'const %s*' % extStruct, 'castedStruct', 'structInfo', use_auto=True, indent=0),
                    makeGenCastVar('reinterpret_cast', 'Decoded_%s*' % extStruct, 'castedMetaInfo', 'metaInfo', use_auto=True, indent=0),
                    makeGen('pNextName = "&" + ' + makeGenCall('GenerateStruct_{extStruct}',
                                                               ['out',
                                                                'castedStruct',
                                                                'castedMetaInfo',
                                                                'consumer'],
                                                               locals(), indent=1), indent=0),
                    makeGen('break;', indent=0)
                ]
                caseBodies.append(caseBody)

        defaultBody = [makeGen('pNextName = "NULL";', indent=0),
                       makeGen('break;', indent=0)]
        function = [makeGen('std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer) {{', indent=0),
                    makeGen('std::string pNextName = "NULL";'),
                    makeGenCond('structInfo != nullptr && metaInfo != nullptr',
                                [makeGenCastVar('reinterpret_cast', 'const VkBaseInStructure*',
                                                'baseStruct', 'structInfo', indent=8),
                                 makeGenSwitch('baseStruct->sType', cases, caseBodies, defaultBody, indent=4)], [], locals(), indent=4),
                    makeGen('return pNextName;', indent=4),
                    makeGen('}}', indent=0)]

        return ''.join(function)
