#!/usr/bin/env python
#
# Copyright (c) 2013-2016 The Khronos Group Inc.
# Copyright (c) 2018 LunarG, Inc.
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

import argparse, cProfile, pdb, string, sys, time
from reg import *
from generator import write

from api_call_decoders_generator import ApiCallDecodersGenerator,ApiCallDecodersGeneratorOptions
from struct_decoders_generator import StructDecodersGenerator,StructDecodersGeneratorOptions

# Simple timer functions
startTime = None

def startTimer(timeit):
    global startTime
    startTime = time.clock()

def endTimer(timeit, msg):
    global startTime
    endTime = time.clock()
    if (timeit):
        write(msg, endTime - startTime, file=sys.stderr)
        startTime = None

# JSON files for cusomizing code generation
defaultBlacklists = 'blacklists.json'
defaultPlatformTypes = 'platform_types.json'

# Returns a directory of [ generator function, generator options ] indexed
# by specified short names. The generator options incorporate the following
# parameters:
#
# args is an parsed argument object; see below for the fields that are used.
def makeGenOpts(args):
    global genOpts
    genOpts = {}

    # Output target directory
    directory = args.directory

    # Copyright text prefixing all headers (list of strings).
    prefixStrings = [
        '/*',
        '** Copyright (c) 2018 LunarG, Inc.',
        '**',
        '** Licensed under the Apache License, Version 2.0 (the "License");',
        '** you may not use this file except in compliance with the License.',
        '** You may obtain a copy of the License at',
        '**',
        '**     http://www.apache.org/licenses/LICENSE-2.0',
        '**',
        '** Unless required by applicable law or agreed to in writing, software',
        '** distributed under the License is distributed on an "AS IS" BASIS,',
        '** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.',
        '** See the License for the specific language governing permissions and',
        '** limitations under the License.',
        '*/',
        ''
    ]

    # Text specific to Vulkan headers
    vkPrefixStrings = [
        '/*',
        '** This file is generated from the Khronos Vulkan XML API Registry.',
        '**',
        '*/',
        ''
    ]

    genOpts['generated_api_call_decoders.inc'] = [
          ApiCallDecodersGenerator,
          ApiCallDecodersGeneratorOptions(
            filename          = 'generated_api_call_decoders.inc',
            directory         = directory,
            blacklists        = defaultBlacklists,
            platformTypes     = defaultPlatformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = True,
            alignFuncParam    = 48)
        ]

    genOpts['generated_struct_decoders.inc'] = [
          StructDecodersGenerator,
          StructDecodersGeneratorOptions(
            filename          = 'generated_struct_decoders.inc',
            directory         = directory,
            blacklists        = defaultBlacklists,
            platformTypes     = defaultPlatformTypes,
            prefixText        = prefixStrings + vkPrefixStrings,
            protectFile       = False,
            protectFeature    = True)
        ]

# Generate a target based on the options in the matching genOpts{} object.
# This is encapsulated in a function so it can be profiled and/or timed.
# The args parameter is an parsed argument object containing the following
# fields that are used:
#   target - target to generate
#   directory - directory to generate it in
#   protect - True if re-inclusion wrappers should be created
#   extensions - list of additional extensions to include in generated
#   interfaces
def genTarget(args):
    global genOpts

    # Create generator options with specified parameters
    makeGenOpts(args)

    if (args.target in genOpts.keys()):
        createGenerator = genOpts[args.target][0]
        options = genOpts[args.target][1]

        if not args.quiet:
            write('* Building', options.filename, file=sys.stderr)
            write('* options.versions          =', options.versions, file=sys.stderr)
            write('* options.emitversions      =', options.emitversions, file=sys.stderr)
            write('* options.defaultExtensions =', options.defaultExtensions, file=sys.stderr)
            write('* options.addExtensions     =', options.addExtensions, file=sys.stderr)
            write('* options.removeExtensions  =', options.removeExtensions, file=sys.stderr)
            write('* options.emitExtensions    =', options.emitExtensions, file=sys.stderr)

        startTimer(args.time)
        gen = createGenerator(errFile=errWarn,
                              warnFile=errWarn,
                              diagFile=diag)
        reg.setGenerator(gen)
        reg.apiGen(options)

        if not args.quiet:
            write('* Generated', options.filename, file=sys.stderr)
        endTimer(args.time, '* Time to generate ' + options.filename + ' =')
    else:
        write('No generator options for unknown target:',
              args.target, file=sys.stderr)

# -feature name
# -extension name
# For both, "name" may be a single name, or a space-separated list
# of names, or a regular expression.
if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('-debug', action='store_true',
                        help='Enable debugging')
    parser.add_argument('-dump', action='store_true',
                        help='Enable dump to stderr')
    parser.add_argument('-diagfile', action='store',
                        default=None,
                        help='Write diagnostics to specified file')
    parser.add_argument('-errfile', action='store',
                        default=None,
                        help='Write errors and warnings to specified file instead of stderr')
    parser.add_argument('-noprotect', dest='protect', action='store_false',
                        help='Disable inclusion protection in output headers')
    parser.add_argument('-profile', action='store_true',
                        help='Enable profiling')
    parser.add_argument('-registry', action='store',
                        default='vk.xml',
                        help='Use specified registry file instead of vk.xml')
    parser.add_argument('-time', action='store_true',
                        help='Enable timing')
    parser.add_argument('-validate', action='store_true',
                        help='Enable group validation')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')
    parser.add_argument('target', metavar='target', nargs='?',
                        help='Specify target')
    parser.add_argument('-quiet', action='store_true', default=True,
                        help='Suppress script output during normal execution.')
    parser.add_argument('-verbose', action='store_false', dest='quiet', default=True,
                        help='Enable script output during normal execution.')

    args = parser.parse_args()

    # Load & parse registry
    reg = Registry()

    startTimer(args.time)
    tree = etree.parse(args.registry)
    endTimer(args.time, '* Time to make ElementTree =')

    if args.debug:
        pdb.run('reg.loadElementTree(tree)')
    else:
        startTimer(args.time)
        reg.loadElementTree(tree)
        endTimer(args.time, '* Time to parse ElementTree =')

    if (args.validate):
        reg.validateGroups()

    if (args.dump):
        write('* Dumping registry to regdump.txt', file=sys.stderr)
        reg.dumpReg(filehandle = open('regdump.txt', 'w', encoding='utf-8'))

    # create error/warning & diagnostic files
    if (args.errfile):
        errWarn = open(args.errfile, 'w', encoding='utf-8')
    else:
        errWarn = sys.stderr

    if (args.diagfile):
        diag = open(args.diagfile, 'w', encoding='utf-8')
    else:
        diag = None

    if (args.debug):
        pdb.run('genTarget(args)')
    elif (args.profile):
        import cProfile, pstats
        cProfile.run('genTarget(args)', 'profile.txt')
        p = pstats.Stats('profile.txt')
        p.strip_dirs().sort_stats('time').print_stats(50)
    else:
        genTarget(args)
