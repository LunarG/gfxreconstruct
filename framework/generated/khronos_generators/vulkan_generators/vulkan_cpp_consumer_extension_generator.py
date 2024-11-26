#!/usr/bin/python3 -i
#
# Copyright (c) 2021 Samsung
# Copyright (c) 2023 Google
# Copyright (c) 2023 LunarG, Inc.
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

# Copyright text prefixing all headers (list of strings).
CPP_PREFIX_STRING = [
    '/*',
    '** Copyright (c) 2021 Samsung',
    '** Copyright (c) 2023 Google',
    '** Copyright (c) 2023 LunarG, Inc.',
    '**',
    '** Permission is hereby granted, free of charge, to any person obtaining a',
    '** copy of this software and associated documentation files (the "Software"),',
    '** to deal in the Software without restriction, including without limitation',
    '** the rights to use, copy, modify, merge, publish, distribute, sublicense,',
    '** and/or sell copies of the Software, and to permit persons to whom the',
    '** Software is furnished to do so, subject to the following conditions:',
    '**',
    '** The above copyright notice and this permission notice shall be included in',
    '** all copies or substantial portions of the Software.', '**',
    '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',
    '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',
    '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',
    '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',
    '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',
    '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER',
    '** DEALINGS IN THE SOFTWARE.',
    '*/',
    '',
    '/*',
    '** This file is generated from the Khronos Vulkan XML API Registry.',
    '**',
    '*/',
    ''
]

class VulkanCppConsumerExtensionGeneratorOptions(BaseGeneratorOptions):
    """Options for generating a C++ class for Vulkan capture file to CPP structure generation"""

    def __init__(
        self,
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text=CPP_PREFIX_STRING,
        protect_file=False,
        protect_feature=True,
        extra_headers=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            blacklists,
            platform_types,
            filename,
            directory,
            CPP_PREFIX_STRING,
            protect_file,
            protect_feature,
            extra_headers=extra_headers
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

        if not self.is_header:
            self.writeout('#include "generated/generated_vulkan_cpp_consumer_extension.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_consumer.h"')
            self.writeout('#include "generated/generated_vulkan_cpp_structs.h"')
            self.writeout('#include "decode/vulkan_cpp_structs.h"')
        self.writeout('#include "util/defines.h"')
        self.writeIncludesOfCommonApiHeaders(genOpts)
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
            self.writeout('std::string GenerateExtension(std::ostream& out, const void* struct_info, void* meta_info, VulkanCppConsumerBase& consumer);')
        else:
            defaultBody = [makeGen('next_var_name = "NULL";', indent=0),
                        makeGen('break;', indent=0)]
            function = [makeGen('std::string GenerateExtension(std::ostream& out, const void* struct_info, void* meta_info, VulkanCppConsumerBase& consumer) {{', indent=0),
                        makeGen('std::string next_var_name = "NULL";'),
                        makeGenCond('struct_info != nullptr && meta_info != nullptr',
                                    [makeGenCastVar('reinterpret_cast', 'const VkBaseInStructure*',
                                                    'base_struct', 'struct_info', indent=8),
                                    makeGen('PNextNode* pnext_meta_data = reinterpret_cast<PNextNode*>(meta_info);', indent=8),
                                    makeGenSwitch('base_struct->sType', self.cases, self.caseBodies, defaultBody, indent=4)], [], locals(), indent=4),
                        makeGen('return next_var_name;', indent=4),
                        makeGen('}}', indent=0)]
            body = ''.join(function)
            self.writeout(body)


        self.newline()
        self.writeout('GFXRECON_END_NAMESPACE(decode)')
        self.writeout('GFXRECON_END_NAMESPACE(gfxrecon)')

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def need_feature_generation(self):
        if self.struct_names:
            return True
        return False

    def generate_feature(self):
        structs = self.get_filtered_struct_names()
        structs.sort()

        for structName in structs:
            if (structName in self.feature_struct_aliases or structName in self.feature_union_aliases):
                continue

            sType = None
            if structName in self.registry.typedict:
                typeinfo = self.registry.typedict[structName]
                parent_structs = typeinfo.elem.get('structextends')
                if parent_structs:
                    sType = self.make_structure_type_enum(typeinfo, structName)
            if not sType:
                continue

            self.cases.append(sType)
            caseBody = [
                makeGenCastVar('reinterpret_cast', 'const %s*' % structName, 'casted_struct', 'struct_info', use_auto=True, indent=0),
                makeGenCastVar('reinterpret_cast', 'Decoded_%s*' % structName, 'decoded_struct', 'pnext_meta_data->GetMetaStructPointer()', use_auto=True, indent=0),
                makeGen('next_var_name = "&" + ' + makeGenCall(f'GenerateStruct_{structName}',
                                                            ['out',
                                                            'casted_struct',
                                                            'decoded_struct',
                                                            'consumer'],
                                                            locals(), indent=1), indent=0),
                makeGen('break;', indent=0)
            ]
            self.caseBodies.append(caseBody)
