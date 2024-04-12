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
from base_generator import BaseGenerator, BaseGeneratorOptions, write


class OpenXrConsumerHeaderGeneratorOptions(BaseGeneratorOptions):
    """Adds the following new option:
    is_override - Specify whether the member function declarations are
                  virtual function overrides or pure virtual functions.
    Options for generating C++ class declarations for OpenXR parameter processing.
    """

    def __init__(
        self,
        class_name,
        base_class_header,
        is_override,
        constructor_args='',
        blacklists=None,  # Path to JSON file listing apicalls and structs to ignore.
        platform_types=None,  # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
        filename=None,
        directory='.',
        prefix_text='',
        protect_file=False,
        protect_feature=True,
        extraOpenXrHeaders=[]
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
            extraOpenXrHeaders=extraOpenXrHeaders
        )
        self.class_name = class_name
        self.base_class_header = base_class_header
        self.is_override = is_override
        self.constructor_args = constructor_args


class OpenXrConsumerHeaderGenerator(BaseGenerator):
    """OpenXrConsumerHeaderGenerator - subclass of BaseGenerator.
    Generates C++ member declarations for the OpenXrConsumer class responsible for processing
    OpenXR API call parameter data.
    Generate C++ class declarations for OpenXR parameter processing.
    """

    def __init__(
        self, err_file=sys.stderr, warn_file=sys.stderr, diag_file=sys.stdout
    ):
        BaseGenerator.__init__(
            self,
            process_cmds=True,
            process_structs=False,
            feature_break=True,
            err_file=err_file,
            warn_file=warn_file,
            diag_file=diag_file
        )

    def beginFile(self, gen_opts):
        """Method override."""
        BaseGenerator.beginFile(self, gen_opts)

        write(
            '#include "decode/{}"'.format(gen_opts.base_class_header),
            file=self.outFile
        )
        write(
            '#include "generated/generated_openxr_struct_decoders.h"',
            file=self.outFile
        )
        write('#include "util/defines.h"', file=self.outFile)
        self.newline()
        self.forceCommonXrDefines(gen_opts)
        self.newline()
        self.includeOpenXrHeaders(gen_opts)
        self.newline()
        write('GFXRECON_BEGIN_NAMESPACE(gfxrecon)', file=self.outFile)
        write('GFXRECON_BEGIN_NAMESPACE(decode)', file=self.outFile)
        self.newline()
        write(
            'class {class_name} : public {class_name}Base'.format(
                class_name=gen_opts.class_name
            ),
            file=self.outFile
        )
        write('{', file=self.outFile)
        write('  public:', file=self.outFile)
        if gen_opts.constructor_args:
            arg_list = ', '.join(
                [
                    arg.split(' ')[-1]
                    for arg in gen_opts.constructor_args.split(',')
                ]
            )
            write(
                '    {class_name}({}) : {class_name}Base({}) {{ }}\n'.format(
                    gen_opts.constructor_args,
                    arg_list,
                    class_name=gen_opts.class_name
                ),
                file=self.outFile
            )
        else:
            write(
                '    {}() {{ }}\n'.format(gen_opts.class_name),
                file=self.outFile
            )
        write(
            '    virtual ~{}() override {{ }}'.format(gen_opts.class_name),
            file=self.outFile
        )

    def endFile(self):
        """Method override."""
        write('};', file=self.outFile)
        self.newline()
        write('GFXRECON_END_NAMESPACE(decode)', file=self.outFile)
        write('GFXRECON_END_NAMESPACE(gfxrecon)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def need_feature_generation(self):
        if self.feature_cmd_params:
            return True
        return False

    def generate_feature(self):
        """Performs C++ code generation for the feature."""
        first = True
        for cmd in self.get_filtered_cmd_names():
            info = self.feature_cmd_params[cmd]
            return_type = info[0]
            values = info[2]

            decl = self.make_consumer_func_decl(
                return_type, 'Process_' + cmd, values
            )

            cmddef = '' if first else '\n'
            if self.genOpts.is_override:
                cmddef += self.indent(
                    'virtual ' + decl + ' override;', self.INDENT_SIZE
                )
            else:
                cmddef += self.indent(
                    'virtual ' + decl + ' {}', self.INDENT_SIZE
                )

            write(cmddef, file=self.outFile)
            first = False
