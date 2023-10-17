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

import re
import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write
from vulkan_cpp_consumer_body_generator import \
    makeGen, makeGenCall, makeGenCond, makeGenCastVar, makeGenSwitch

class VulkanCppConsumerExtensionGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP structure generation"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )

1
class VulkanCppConsumerExtensionGenerator(BaseGenerator):
    """VulkanCppConsumerExtensionGenerator - subclass of BaseGenerator.
    Generates a C++ function responsible for generating extensions from pNext void pointers.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
     ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=True,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def writeout(self, *args, **kwargs):
        write(*args, **kwargs, file=self.outFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)
        self.is_header = genOpts.filename.endswith(".h")

        if self.is_header:
            self.writeout('#pragma once')
            self.newline()

        if not self.is_header:
            self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
            self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "util/defines.h"')
        self.includeVulkanHeaders(genOpts)
        self.newline()
        self.writeout('#include <iostream>')
        self.writeout('#include <sstream>')
        self.newline()
        self.writeout('GFXRECON_BEGIN_NAMESPACE(gfxrecon)')
        self.writeout('GFXRECON_BEGIN_NAMESPACE(decode)')
        self.newline()

        self.cases = []
        self.caseBodies = []

    # Method override
    def endFile(self):
        if self.is_header:
            self.writeout('class VulkanCppConsumerBase;')
            self.writeout('std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer);')
        else:
            defaultBody = [makeGen('pNextName = "NULL";', indent=0),
                        makeGen('break;', indent=0)]
            function = [makeGen('std::string GenerateExtension(std::ostream& out, const void* structInfo, void* metaInfo, VulkanCppConsumerBase& consumer) {{', indent=0),
                        makeGen('std::string pNextName = "NULL";'),
                        makeGenCond('structInfo != nullptr && metaInfo != nullptr',
                                    [makeGenCastVar('reinterpret_cast', 'const VkBaseInStructure*',
                                                    'baseStruct', 'structInfo', indent=8),
                                    makeGen('PNextNode* metaInfoPNext = reinterpret_cast<PNextNode*>(metaInfo);', indent=8),
                                    makeGenSwitch('baseStruct->sType', self.cases, self.caseBodies, defaultBody, indent=4)], [], locals(), indent=4),
                        makeGen('return pNextName;', indent=4),
                        makeGen('}}', indent=0)]
            body = ''.join(function)
            self.writeout(body)


        self.newline()
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if 'VK_VERSION_' in self.featureName:
            return False
        return True

    def generate_feature(self):
        structs = self.get_filtered_struct_names()
        structs.sort()

        # Insert the declaration of GenerateStruct functions.
        for structName in structs:
            if structName in self.feature_struct_aliases:
                continue

            typeinfo = self.registry.typedict[structName]

            sType = self.make_structure_type_enum(typeinfo, structName)
            if not sType:
                continue

            self.cases.append(sType)
            caseBody = [
                makeGenCastVar('reinterpret_cast', 'const %s*' % structName, 'castedStruct', 'structInfo', use_auto=True, indent=0),
                makeGenCastVar('reinterpret_cast', 'Decoded_%s*' % structName, 'castedMetaInfo', 'metaInfoPNext->GetMetaStructPointer()', use_auto=True, indent=0),
                makeGen('pNextName = "&" + ' + makeGenCall('GenerateStruct_{structName}',
                                                            ['out',
                                                            'castedStruct',
                                                            'castedMetaInfo',
                                                            'consumer'],
                                                            locals(), indent=1), indent=0),
                makeGen('break;', indent=0)
            ]
            self.caseBodies.append(caseBody)
