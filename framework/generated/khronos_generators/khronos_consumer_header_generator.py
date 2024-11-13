#!/usr/bin/python3 -i
#
# Copyright (c) 2018 Valve Corporation
# Copyright (c) 2018-2024 LunarG, Inc.
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


class KhronosConsumerHeaderGenerator():
    """KhronosConsumerHeaderGenerator
    Generates C++ member declarations for the appropriate consumer class responsible
    for processing the current Khronos API call parameter data.
    """

    def write_class_setup(self, class_name, constructor_args):
        write(
            'class {class_name} : public {class_name}Base'.format(
                class_name=class_name
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        if constructor_args:
            arg_list = ', '.join(
                [arg.split(' ')[-1] for arg in constructor_args.split(',')]
            )
            write(
                '    {class_name}({}) : {class_name}Base({}) {{ }}\n'.format(
                    constructor_args, arg_list, class_name=class_name
                ),
                file=self.outFile
            )
        else:
            write('    {}() {{ }}\n'.format(class_name), file=self.outFile)
        write(
            '    virtual ~{}() override {{ }}'.format(class_name),
            file=self.outFile
        )

    def write_class_completion(self):
        write('};', file=self.outFile)

    def write_class_contents(self):
        """Method may be overridden."""
        for cmd in self.get_all_filtered_cmd_names():
            info = self.all_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            decl = self.make_consumer_func_decl(
                return_type, 'Process_' + cmd, values
            )

            cmddef = '\n'
            if self.genOpts.is_override:
                cmddef += self.indent(
                    'virtual ' + decl + ' override;', self.INDENT_SIZE
                )
            else:
                cmddef += self.indent(
                    'virtual ' + decl + ' {}', self.INDENT_SIZE
                )

            write(cmddef, file=self.outFile)

    def output_header_contents(self, class_name, constructor_args):
        self.write_class_setup(class_name, constructor_args)
        self.write_class_contents()
        self.write_class_completion()
