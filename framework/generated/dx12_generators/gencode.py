#!/usr/bin/env python3
#
# Copyright (c) 2021 LunarG, Inc.
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

import argparse
import pdb
import sys
import time
import threading
from dx12_reg import DX12Registry
from generator import write


# API Call Encoders
from dx12_base_generator\
    import DX12GeneratorOptions

from dx12_api_call_encoders_header_generator\
    import DX12ApiCallEncodersHeaderGenerator


# Simple timer functions
start_time = None


def start_timer(timeit):
    global start_time
    if timeit:
        start_time = time.process_time()


def end_timer(timeit, msg):
    global start_time
    if timeit:
        end_time = time.process_time()
        write(msg, end_time - start_time, file=sys.stderr)
        start_time = None


# Returns a directory of [ generator function, generator options ] indexed
# by specified short names. The generator options incorporate the following
# parameters:
#
# args is an parsed argument object; see below for the fields that are used.
def make_gen_opts(args):
    global gen_opts
    gen_opts = {}

    # Output target directory
    directory = args.directory

    # Copyright text prefixing all headers (list of strings).
    prefix_strings = [
        '/*',
        '** Copyright (c) 2021 LunarG, Inc.',
        '**',
        '** Permission is hereby granted, free of charge, to any person obtaining a copy',  # noqa
        '** of this software and associated documentation files (the "Software"), to',      # noqa
        '** deal in the Software without restriction, including without limitation the',    # noqa
        '** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or',   # noqa
        '** sell copies of the Software, and to permit persons to whom the Software is',    # noqa
        '** furnished to do so, subject to the following conditions:',
        '**',
        '** The above copyright notice and this permission notice shall be included in',    # noqa
        '** all copies or substantial portions of the Software.',
        '**',
        '** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR',    # noqa
        '** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,',      # noqa
        '** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE',   # noqa
        '** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER',        # noqa
        '** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING',       # noqa
        '** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS',  # noqa
        '** IN THE SOFTWARE.',
        '*/',
        ''
    ]

    py_prefix_strings = [
        '/*',
        '** This file is generated from {}.',
        '**',
        '*/',
        ''
    ]

    # API call encoder generators
    py_prefix_strings1 = py_prefix_strings[-4]
    py_prefix_strings[-4] = py_prefix_strings1.format(
        'dx12_api_call_encoders_header_generator.py')
    gen_opts['generated_dx12_api_call_encoders.h'] = [
        DX12ApiCallEncodersHeaderGenerator,
        DX12GeneratorOptions(
            filename='generated_dx12_api_call_encoders.h',
            directory=directory,
            prefixText=prefix_strings + py_prefix_strings,
            protectFile=True,
            protectFeature=False)
    ]


err_warn = None
diag = None


# Generate a target based on the options in the matching genOpts{} object.
# This is encapsulated in a function so it can be profiled and/or timed.
# The args parameter is an parsed argument object containing the following
# fields that are used:
#   target - target to generate
#   directory - directory to generate it in
#   protect - True if re-inclusion wrappers should be created
#   extensions - list of additional extensions to include in generated
#   interfaces
def gen_target(args, source_dict):
    # Create generator options with specified parameters
    make_gen_opts(args)

    if args.target in gen_opts:
        create_generator = gen_opts[args.target][0]
        options = gen_opts[args.target][1]

        if not args.quiet:
            write('* Building', options.filename, file=sys.stderr)
            write(
                '* options.versions          =',
                options.versions,
                file=sys.stderr)
            write(
                '* options.emitversions      =',
                options.emitversions,
                file=sys.stderr)
            write(
                '* options.defaultExtensions =',
                options.defaultExtensions,
                file=sys.stderr)
            write(
                '* options.addExtensions     =',
                options.addExtensions,
                file=sys.stderr)
            write(
                '* options.removeExtensions  =',
                options.removeExtensions,
                file=sys.stderr)
            write(
                '* options.emitExtensions    =',
                options.emitExtensions,
                file=sys.stderr)

        # Text specific to dx12 headers
        dx12_prefix_strings = ("/*\n"
                               "** This part is generated from {} in Windows SDK: {}\n"  # noqa
                               "**\n"
                               "*/").format('{}', args.windows_sdk_version)

        gen = create_generator(
            source_dict,
            dx12_prefix_strings,
            errFile=err_warn,
            warnFile=err_warn,
            diagFile=diag)

        return (gen, options)
    else:
        write(
            'No generator options for unknown target:',
            args.target,
            file=sys.stderr)
        return None


class GenCode (threading.Thread):
    def __init__(self, target, source_dict,
                 windows_sdk_version, directory, configs):
        threading.Thread.__init__(self)
        self.target = target
        self.source_dict = source_dict
        self.windows_sdk_version = windows_sdk_version
        self.directory = directory
        self.configs = configs

    # -feature name
    # -extension name
    # For both, "name" may be a single name, or a space-separated list
    # of names, or a regular expression.
    def run(self):
        parser_info = argparse.ArgumentParser()

        parser_info.add_argument(
            '-debug',
            action='store_true',
            help='Enable debugging')
        parser_info.add_argument(
            '-dump',
            action='store_true',
            help='Enable dump to stderr')
        parser_info.add_argument(
            '-diagfile',
            action='store',
            default=None,
            help='Write diagnostics to specified file')
        parser_info.add_argument(
            '-errfile',
            action='store',
            default=None,
            help='Write errors and warnings to specified file instead of stderr')  # noqa
        parser_info.add_argument(
            '-noprotect',
            dest='protect',
            action='store_false',
            help='Disable inclusion protection in output headers')
        parser_info.add_argument(
            '-profile',
            action='store_true',
            help='Enable profiling')
        parser_info.add_argument(
            '-windows_sdk_version',
            action='store',
            help='WindowsSDK Version')
        parser_info.add_argument(
            '-source_dir',
            action='store',
            help='DX12 header fold path')
        parser_info.add_argument(
            '-source_list',
            action='store',
            help='DX12 header file name')
        parser_info.add_argument(
            '-time',
            action='store_true',
            help='Enable timing')
        parser_info.add_argument(
            '-validate',
            action='store_true',
            help='Enable group validation')
        parser_info.add_argument(
            '-o',
            action='store',
            dest='directory',
            default='.',
            help='Create target and related files in specified directory')
        parser_info.add_argument(
            'target',
            metavar='target',
            nargs='?',
            help='Specify target')
        parser_info.add_argument(
            '-quiet',
            action='store_true',
            default=True,
            help='Suppress script output during normal execution.')
        parser_info.add_argument(
            '-verbose',
            action='store_false',
            dest='quiet',
            default=True,
            help='Enable script output during normal execution.')
        parser_info.add_argument(
            '-configs',
            action='store',
            dest='configs',
            default='.',
            help='Specify directory containing JSON configuration files for generators')  # noqa

        args = parser_info.parse_args()
        args.target = self.target
        args.windows_sdk_version = self.windows_sdk_version
        args.directory = self.directory
        args.configs = self.configs

        global err_warn, diag
        # create error/warning & diagnostic files
        if (args.errfile):
            err_warn = open(args.errfile, 'w', encoding='utf-8')
        else:
            err_warn = sys.stderr

        if (args.diagfile):
            diag = open(args.diagfile, 'w', encoding='utf-8')
        else:
            diag = None

        (gen, options) = gen_target(args, self.source_dict)

        # TODO: Remove Registry in the future
        reg = DX12Registry(gen, options)

        start_timer(args.time)

        end_timer(args.time, '* Time to make ElementTree =')

        if (args.validate):
            reg.validateGroups()

        if (args.dump):
            write('* Dumping registry to regdump.txt', file=sys.stderr)
            reg.dumpReg(filehandle=open('regdump.txt', 'w', encoding='utf-8'))

        if (args.debug):
            pdb.run('reg.apiGen()')
        else:
            start_timer(args.time)
            reg.apiGen()
            end_timer(
                args.time,
                '* Time to generate ' +
                options.filename +
                ' =')

        if not args.quiet:
            write('* Generated', options.filename, file=sys.stderr)
