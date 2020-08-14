#!/usr/bin/env python3

# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

'''
GFX reconstruct build script
'''

import argparse
import collections
import copy
import importlib
import os
import platform
import subprocess
import sys


def is_windows():
    '''
    Check if the system is Windows
    '''
    return 'windows' == platform.system().lower()


# Repository root directory
REPO_ROOT = os.path.abspath(os.path.join(
    os.path.split(os.path.abspath(__file__))[0], '..'))

# List of tests to run when no test executable is passed to script
ALL_TESTS = collections.OrderedDict({
    'gfxrecon_application_test': [],
    'gfxrecon_decode_test': [],
    'gfxrecon_encode_test': [],
    'gfxrecon_format_test': [],
    'gfxrecon_util_test': [],
    'VkLayer_gfxreconstruct_test': [],
})


class TestError(Exception):
    '''
    Raised on a test error
    '''


def import_build_script():
    '''
    Import the build script - reuse build script constants
    '''
    sys.path.insert(0, os.path.join(REPO_ROOT, 'scripts'))
    build_script = importlib.import_module('build')
    return build_script


def parse_args(build_script):
    '''
    Parse command line arguments
    '''
    arg_parser = argparse.ArgumentParser(
        description="gfxreconstruct test script")
    arg_parser.add_argument('--version', action='version',
                            version=str(build_script.VERSION),
                            help='Print script version and exit')
    arg_parser.add_argument(
        '--test-exe', default=None,
        help='the name of a single internal test to run (one of: {}), or a '
        'path to an external test to run.  If not specified, all internal '
        'tests are run.'.format(', '.join(ALL_TESTS)))
    arg_parser.add_argument(
        '--test-args', nargs='+',
        help='Test arguments passed to the test executable')
    arg_parser.add_argument(
        '--build-dir', dest='build_dir', metavar='BUILD_DIR',
        action='store', default=None)
    arg_parser.add_argument(
        '-a', '--arch', dest='architecture',
        metavar='ARCH', action='store', choices=build_script.ARCHITECTURES,
        default=build_script.DEFAULT_ARCHITECTURE,
        help='Build target architecture. Can be one of: {0}'.format(
                ', '.join(build_script.ARCHITECTURES)))
    arg_parser.add_argument(
        '-c', '--config', dest='configuration',
        metavar='CONFIG', action='store', choices=build_script.CONFIGURATIONS,
        default=build_script.DEFAULT_CONFIGURATION,
        help='Build target configuration. Can be one of: {0}'.format(
            ', '.join(build_script.CONFIGURATIONS)))
    return arg_parser.parse_args()


def run_test(test_exe, test_args):
    '''
    Run a single test

    The test working directory is based on the test relative path.
    If the test executable is not found or the test fails an error is thrown.
    '''
    run_test_args = [test_exe]
    if args.test_args is not None:
        run_test_args.extend(args.test_args)
    run_test_work_dir = os.path.split(os.path.abspath(test_exe))[0]
    if '' == run_test_work_dir:
        run_test_work_dir = os.getcwd()
    try:
        test_result = subprocess.run(run_test_args, cwd=run_test_work_dir)
        if 0 != test_result.returncode:
            raise TestError('Running test', ' '.join(
                run_test_args), 'failed', ', working_dir:', run_test_work_dir)
    except Exception:
        raise TestError('Failed to run test', test_exe, ' '.join(
            test_args), ', working_dir:', run_test_work_dir)


# Main entry point
if '__main__' == __name__:
    build_script = import_build_script()
    args = parse_args(build_script)
    tests = []
    if args.test_exe is None:
        for test in ALL_TESTS.items():
            test_exe_dir = args.build_dir
            if test_exe_dir is None:
                test_exe_dir = os.path.join(
                    build_script.BUILD_CONFIGS[args.configuration],
                    platform.system().lower(),
                    args.architecture,
                    'bin')
            test_exe = os.path.join(test_exe_dir, test[0])
            test_args = copy.deepcopy(test[1])
            if args.test_args is not None:
                test_args.extend(args.test_args)
            tests.append((test_exe, test_args))
    else:
        tests = [(args.test_exe, args.test_args)]
    for test_exe, test_args in tests:
        run_test(test_exe, test_args)
