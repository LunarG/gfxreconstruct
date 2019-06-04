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
import copy
import distutils.version
import os
import platform
import re
import shutil
import subprocess
import sys


def is_windows():
    '''
    Check if the system is Windows
    '''
    return 'windows' == platform.system().lower()


ARCHITECTURES = ['x64', 'x86']
BUILD_ROOT = os.path.split(os.path.abspath(__file__))[0]
BUILD_CONFIGS = {'debug': 'dbuild', 'release': 'build'}
if is_windows():
    BUILD_CONFIGS['debug'] = 'build'
CONFIGURATIONS = ['release', 'debug']
VERSION = distutils.version.StrictVersion('0.0.0')
ALL_TESTS = {}  # TODO add all tests


class TestError(Exception):
    '''
    Raised on a test error
    '''


def parse_args():
    '''
    Parse command line arguments
    '''
    arg_parser = argparse.ArgumentParser(
        description="gfxreconstruct build script",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    arg_parser.add_argument('--version', dest='version',
                            action='version', version=str(VERSION))
    arg_parser.add_argument(
        '--test-exe', dest='test_exe', metavar='TEST_EXE',
        action='store', default=None,
        help='Test executable to run')
    arg_parser.add_argument(
        '--test-args', dest='test_args', metavar='TEST_ARGS', nargs='+',
        action='store',
        help='Test arguments passed to the test executable')
    arg_parser.add_argument(
        '-a', '--arch', dest='architecture',
        metavar='ARCH', action='store',
        choices=ARCHITECTURES, default=ARCHITECTURES[0],
        help='Build target architecture. Can be one of: {0}'.format(
                ', '.join(ARCHITECTURES)))
    arg_parser.add_argument(
        '-c', '--config', dest='configuration',
        metavar='CONFIG', action='store',
        choices=CONFIGURATIONS, default=CONFIGURATIONS[0],
        help='Build target configuration. Can be one of: {0}'.format(
            ', '.join(CONFIGURATIONS)))
    return arg_parser.parse_args()


def run_test(test_exe, test_args):
    '''
    Run a single test
    '''
    print(test_exe, test_args)
    run_test_args = [test_exe]
    if args.test_args is not None:
        run_test_args.extend(args.test_args)
    run_test_work_dir = os.path.split(test_exe)[0]
    if '' == run_test_work_dir:
        run_test_work_dir = os.getcwd()
    try:
        test_result = subprocess.run(run_test_args, cwd=run_test_work_dir)
        if 0 != test_result.returncode:
            raise TestError('Running test', ' '.join(run_test_args), 'failed')
    except Exception:
        raise TestError('Failed to run test', test_exe, ' '.join(test_args))


# Main entry point
if '__main__' == __name__:
    try:
        args = parse_args()
        tests = copy.deepcopy(ALL_TESTS)
        if args.test_exe is None:
            if args.test_args is not None:
                for test_args in tests.values():
                    test_args.extend(args.test_args)
        else:
            tests = {args.test.exe: args.test.args}
        for test_exe, test_args in tests.items():
            run_test(test_exe, test_args)
    except Exception as error:
        print('Error', *(error.args))
        sys.exit(1)
    sys.exit(0)
