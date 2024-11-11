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
from khronos_base_generator import write


class KhronosEncodeExtendedStructGenerator():
    """KhronosEncodeExtendedStructGenerator.
    Generates C++ code for a Khronos API's extended structure encoding.
    """

    def writeCommonHeaders(self, gen_opts):
        # Get the current API and generate the items relavent to that
        current_api_data = self.getApiData()
        lower_api_name = current_api_data.api_name.lower()

        write(
            '#include "generated/generated_{}_struct_encoders.h"'.
            format(lower_api_name),
            file=self.outFile
        )
        self.newline()
        write('#include "encode/parameter_encoder.h"', file=self.outFile)
        write('#include "encode/struct_pointer_encoder.h"', file=self.outFile)
        write(
            '#include "encode/{}_capture_manager.h"'.format(lower_api_name),
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.includeVulkanHeaders(gen_opts)
        self.newline()
        write('#include <cassert>', file=self.outFile)
        write('#include <cstdio>', file=self.outFile)
        write('#include <memory>', file=self.outFile)

    def writeEncodeStructWhileLoopStatement(self, current_api_data):
        """
        Method intended to be overridden.
        This is because some of the loop determination is API-specific
        """
        write('    while (base != nullptr)', file=self.outFile)

    def writeEncodeStructDefinitionPrefix(self):
        # Get the current API and generate the items relavent to that
        current_api_data = self.getApiData()

        write(
            'void Encode{}Struct(ParameterEncoder* encoder, const void* value)'
            .format(current_api_data.extended_struct_func_prefix),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('    assert(encoder != nullptr);', file=self.outFile)
        self.newline()
        write(
            '    auto base = reinterpret_cast<const {}*>(value);'.format(
                current_api_data.base_in_struct
            ),
            file=self.outFile
        )
        self.newline()
        write(
            '    // Ignore the structures added to the {} chain by the loader.'
            .format(current_api_data.extended_struct_variable),
            file=self.outFile
        )
        self.writeEncodeStructWhileLoopStatement(current_api_data)
        write('    {', file=self.outFile)
        write(
            '        base = base->{};'.format(
                current_api_data.extended_struct_variable
            ),
            file=self.outFile
        )
        write('    }', file=self.outFile)
        self.newline()
        write('    if (base != nullptr)', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        switch (base->{})'.format(
                current_api_data.struct_type_variable
            ),
            file=self.outFile
        )
        write('        {', file=self.outFile)
        write('        default:', file=self.outFile)
        write('            {', file=self.outFile)
        write(
            '                // {} is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.'
            .format(current_api_data.extended_struct_variable),
            file=self.outFile
        )
        write(
            '                int32_t message_size = std::snprintf(nullptr, 0, "A {} value with unrecognized {} = %d was omitted from the capture file, which may cause replay to fail.", base->{});'
            .format(
                current_api_data.extended_struct_variable,
                current_api_data.struct_type_enum,
                current_api_data.struct_type_variable
            ),
            file=self.outFile
        )
        write(
            '                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.',
            file=self.outFile
        )
        write(
            '                std::snprintf(message.get(), (message_size + 1), "A {} value with unrecognized {} = %d was omitted from the capture file, which may cause replay to fail.", base->{});'
            .format(
                current_api_data.extended_struct_variable,
                current_api_data.struct_type_enum,
                current_api_data.struct_type_variable
            ),
            file=self.outFile
        )
        write(
            '                {}CaptureManager::Get()->WriteDisplayMessageCmd(message.get());'
            .format(current_api_data.api_class_prefix),
            file=self.outFile
        )
        write(
            '                GFXRECON_LOG_WARNING("%s", message.get());',
            file=self.outFile
        )
        write(
            '                Encode{}Struct(encoder, base->{});'.format(
                current_api_data.extended_struct_func_prefix,
                current_api_data.extended_struct_variable
            ),
            file=self.outFile
        )
        write('            }', file=self.outFile)
        write('            break;', file=self.outFile)

    def writeEncodeStructDefinitionData(self):
        current_api_data = self.getApiData()

        for struct in self.all_extended_structs:
            if struct in self.struct_type_names:
                stype = self.struct_type_names[struct]
                write('        case {}:'.format(stype), file=self.outFile)
                write(
                    '            EncodeStructPtr(encoder, reinterpret_cast<const {}*>(base));'
                    .format(struct),
                    file=self.outFile
                )
                write('            break;', file=self.outFile)

        current_api_data = self.getApiData()

        write('        }', file=self.outFile)
        write('    }', file=self.outFile)
        write('    else', file=self.outFile)
        write('    {', file=self.outFile)
        write(
            '        // {} was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.'
            .format(current_api_data.extended_struct_variable),
            file=self.outFile
        )
        write(
            '        encoder->EncodeStructPtrPreamble(nullptr);',
            file=self.outFile
        )
        write('    }', file=self.outFile)
        write('}', file=self.outFile)
