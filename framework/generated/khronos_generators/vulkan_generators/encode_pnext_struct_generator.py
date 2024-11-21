#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018 LunarG, Inc.
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

import sys
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class EncodePNextStructGeneratorOptions(BaseGeneratorOptions):
    """Eliminates JSON black_lists and platform_types files, which are not necessary for
    pNext switch statement generation.
    Options for Vulkan API pNext structure encoding C++ code generation.
    """

    def __init__(
        self,
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraVulkanHeaders=[]
    ):
        BaseGeneratorOptions.__init__(
            self,
            None,
            None,
            filename,
            directory,
            prefix_text,
            protect_file,
            protect_feature,
            extraVulkanHeaders=extraVulkanHeaders
        )


class EncodePNextStructGenerator(BaseGenerator):
    """EncodePNextStructGenerator - subclass of BaseGenerator.
    Generates C++ code for Vulkan API pNext structure encoding.
    Generate pNext structure encoding C++ code.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=False,
            process_structs=False,
            feature_break=False,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

        # Map to store VkStructureType enum values.
        self.stype_values = dict()

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "generated/generated_vulkan_struct_encoders.h"',
            file=self.outFile
        )
        self.newline()
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write('#include "encode/vulkan_capture_manager.h"', file=self.outFile)
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        write('#include <cstdio>', file=self.outFile)
        write('#include <memory>', file=self.outFile)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(encode)', file=self.outFile)
        self.newline()
        write(
            'void EncodePNextStruct(ParameterEncoder* encoder, const void* value)',
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(encoder != nullptr);', file=self.outFile)
        self.newline()
        write(
            '    auto base = reinterpret_cast<const VkBaseInStructure*>(value);',
            file=self.outFile
        )
        self.newline()
        write(
            '    // Ignore the structures added to the pnext chain by the loader.',
            file=self.outFile
        )
        write(
            '    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||',
            file=self.outFile
        )
        write(
            '                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))',
            file=self.outFile
        )
        write('    {', file=self.outFile)
        write('        base = base->pNext;', file=self.outFile)
        write('    }', file=self.outFile)
        self.newline()
        write('    if (base != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write('        switch (base->sType)', file=self.outFile)
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.',
            file=self.outFile
        )
        write(
            '                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);',
            file=self.outFile
        )
        write(
            '                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.',
            file=self.outFile
        )
        write(
            '                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);',
            file=self.outFile
        )
        write(
            '                VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());',
            file=self.outFile
        )
        write(
            '                GFXRECON_LOG_WARNING("%s", message.get());',
            file=self.outFile
        )
        write(
            '                EncodePNextStruct(encoder, base->pNext);',
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('            break;', file=self.outFile)

    def endFile(self):
        """Method override."""
        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('    else', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.',
            file=self.outFile
        )
        write(
            '        encoder->EncodeStructPtrPreamble(nullptr);',
            file=self.outFile
        )
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(encode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    def genStruct(self, typeinfo, typename, alias):
        """Method override."""
        if not alias:
            # Only process struct types that specify a 'structextends' tag, which indicates the struct can be used in a pNext chain.
            parent_structs = typeinfo.elem.get('structextends')
            if parent_structs:
                stype = self.make_structure_type_enum(typeinfo, typename)
                if stype:
                    self.stype_values[typename] = stype

    def need_feature_generation(self):
        """Indicates that the current feature has C++ code to generate."""
        if self.stype_values:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        for struct in self.stype_values:
            write(
                '        case {}:'.format(self.stype_values[struct]),
                file=self.outFile
            )
            write(
                '            EncodeStructPtr(encoder, reinterpret_cast<const {}*>(base));'
                .format(struct),
                file=self.outFile
            )
            write('            break;', file=self.outFile)
        self.stype_values = dict()
