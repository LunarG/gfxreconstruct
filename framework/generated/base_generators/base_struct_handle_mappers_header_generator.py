#!/usr/bin/python3 -i
#
# Copyright (c) 2019-2020 Valve Corporation
# Copyright (c) 2019-2024 LunarG, Inc.
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
from base_generator import write


class BaseStructHandleMappersHeaderGenerator():
    """Base class for generating struct handle mappers header code."""

    def endFile(self):
        platform_type = self.get_api_prefix()
        object_type = 'Common'
        map_types = 'Handles'
        map_type = 'Handle'
        map_table = ''
        map_object = ''

        is_dx12_class = self.is_dx12_class()
        if is_dx12_class:
            object_type = platform_type
            map_types = 'Objects'
            map_type = 'Object'
            map_table = ', const graphics::Dx12GpuVaMap& gpu_va_map'
            map_object = ', gpu_va_map'

        if not is_dx12_class:
            self.newline()
            if platform_type == 'Vulkan':
                write(
                    f'void MapPNextStructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);',
                    file=self.outFile
                )
            else:
                write(
                    f'void MapNextStructHandles(const void* value, void* wrapper, const CommonObjectInfoTable& object_info_table);',
                    file=self.outFile
                )

        self.newline()

        if is_dx12_class:
            write('template <typename T>', file=self.outFile)
            write(
                'void MapStructArray{}(T* structs, size_t len, const {}ObjectInfoTable& object_info_table{})'
                .format(map_types, object_type, map_table),
                file=self.outFile
            )
            write('{', file=self.outFile)
            write('    if (structs != nullptr)', file=self.outFile)
            write('    {', file=self.outFile)
            write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
            write('        {', file=self.outFile)
            write(
                '            MapStruct{}(&structs[i], object_info_table{});'.
                format(map_types, map_object),
                file=self.outFile
            )
            write('        }', file=self.outFile)
            write('    }', file=self.outFile)
            write('}', file=self.outFile)
            self.newline()

        for struct in self.output_structs_with_handles:
            write(
                'void AddStruct{}(format::HandleId parent_id, const Decoded_{type}* id_wrapper, const {type}* handle_struct, {}ObjectInfoTable* object_info_table{});'
                .format(map_types, object_type, map_table, type=struct),
                file=self.outFile
            )
            self.newline()

        if is_dx12_class:
            write('template <typename T>', file=self.outFile)
            write(
                'void AddStructArray{}(format::HandleId parent_id, const T* id_wrappers, size_t id_len, const typename T::struct_type* handle_structs, size_t handle_len, {}ObjectInfoTable* object_info_table{})'
                .format(map_types, object_type, map_table),
                file=self.outFile
            )
            write('{', file=self.outFile)
            write(
                '    if (id_wrappers != nullptr && handle_structs != nullptr)',
                file=self.outFile
            )
            write('    {', file=self.outFile)
            write(
                '        // TODO: Improved handling of array size mismatch.',
                file=self.outFile
            )
            write(
                '        size_t len = std::min(id_len, handle_len);',
                file=self.outFile
            )
            write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
            write('        {', file=self.outFile)
            write(
                '            AddStruct{}(parent_id, &id_wrappers[i], &handle_structs[i], object_info_table);'
                .format(map_types),
                file=self.outFile
            )
            write('        }', file=self.outFile)
            write('    }', file=self.outFile)
            write('}', file=self.outFile)
            self.newline()

        for struct in self.output_structs_with_handles:
            if struct in self.structs_with_handle_ptrs:
                write(
                    'void SetStruct{map_type}Lengths(Decoded_{type}* wrapper);'
                    .format(map_type=map_type, type=struct),
                    file=self.outFile
                )
                self.newline()

        if is_dx12_class:
            write('template <typename T>', file=self.outFile)
            write(
                'void SetStructArray{}Lengths(T* wrappers, size_t len)'.
                format(map_type),
                file=self.outFile
            )
            write('{', file=self.outFile)
            write('    if (wrappers != nullptr)', file=self.outFile)
            write('    {', file=self.outFile)
            write('        for (size_t i = 0; i < len; ++i)', file=self.outFile)
            write('        {', file=self.outFile)
            write(
                '            SetStruct{}Lengths(&wrappers[i]);'.format(map_type),
                file=self.outFile
            )
            write('        }', file=self.outFile)
            write('    }', file=self.outFile)
            write('}', file=self.outFile)
            self.newline()
        else:
            write('#include "decode/common_struct_handle_mappers.h"', file=self.outFile)

        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        object_table = 'Common'
        map_type = 'Handles'
        map_table = ''
        if self.is_dx12_class():
            object_table = 'Dx12'
            map_type = 'Objects'
            map_table = ', const graphics::Dx12GpuVaMap& gpu_va_map'

        for struct in self.get_filtered_struct_names():
            if (
                (struct in self.structs_with_handles)
                or (struct in self.GENERIC_HANDLE_STRUCTS)
                or (struct in self.structs_with_map_data)
            ) and (struct not in self.STRUCT_MAPPERS_BLACKLIST):
                body = '\n'
                body += 'void MapStruct{}(Decoded_{}* wrapper, const {}ObjectInfoTable& object_info_table{});'.format(
                    map_type, struct, object_table, map_table
                )
                write(body, file=self.outFile)
