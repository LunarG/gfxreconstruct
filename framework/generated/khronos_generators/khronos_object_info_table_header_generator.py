#!/usr/bin/python3 -i
#
# Copyright (c) 2021-2025 LunarG, Inc.
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

from khronos_base_generator import write

# Generates declarations for functions for Khronos state table
class KhronosObjectInfoTableHeaderGenerator():

    # yapf: disable
    def generate_info_table(self, api_data, class_name, base_class):
        add_code = ''
        remove_code = ''
        const_get_code = ''
        get_code = ''
        visit_code = ''
        map_code = ''
        info = {}
        info['api'] = api_data.api_class_prefix
        info['type'] = api_data.type_prefix

        handle_like = set(self.handle_names).union(self.atom_names).union(self.opaque_names)
        for handle_name in sorted(handle_like):
            if handle_name in self.handle_aliases:
                continue
            if not handle_name.startswith(api_data.type_prefix):
                continue

            short_handle_name = handle_name[2:]
            info['handle'] = short_handle_name + 'Info'
            info['function'] = handle_name + 'Info'
            info['map'] = short_handle_name[0].lower() + short_handle_name[1:] + '_map_'
            add_code += '    void Add{function}({api}{handle}&& info) {{ Add{type}ObjectInfo(std::move(info), &{map}); }}\n'.format(**info)
            remove_code += '    void Remove{function}(format::HandleId id) {{ {map}.erase(id); }}\n'.format(**info)
            const_get_code += '    const {api}{handle}* Get{function}(format::HandleId id) const {{ return Get{type}ObjectInfo<{api}{handle}>(id, &{map}); }}\n'.format(**info)
            get_code += '    {api}{handle}* Get{function}(format::HandleId id) {{ return Get{type}ObjectInfo<{api}{handle}>(id, &{map}); }}\n'.format(**info)
            visit_code += '    void Visit{function}(std::function<void(const {api}{handle}*)> visitor) const {{  for (const auto& entry : {map}) {{ visitor(&entry.second); }}  }}\n'.format(**info)
            map_code += '     std::unordered_map<format::HandleId, {api}{handle}> {map};\n'.format(**info)

        code = '\n'
        code += f'class {class_name} : {base_class}\n'
        code += '{\n'
        code += '  public:\n'
        code += f'    {class_name}() {{}}\n'
        code += f'    ~{class_name}() {{}}\n'
        code += '\n'
        code += add_code
        code += '\n'
        code += remove_code
        code += '\n'
        code += const_get_code
        code += '\n'
        code += get_code
        code += '\n'
        code += visit_code
        code += '\n'
        code += '  protected:\n'
        code += map_code
        code += '};\n'
        write(code, file=self.outFile)
    # yapf: enable