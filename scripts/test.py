#!/usr/bin/env python3

# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
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

'''
GFXReconstruct test script

Runs one test executable. The build runs this script for each Catch2
test target when RUN_TESTS is on. To run every unit test at once, use
"ctest -L unit" in the build directory.
'''

import argparse
import importlib
import os
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
        '--test-exe', required=True,
        help='Path of the test executable to run')
    arg_parser.add_argument(
        '--test-args', nargs='+',
        help='Test arguments passed to the test executable')
    arg_parser.add_argument(
        '--build-dir', dest='build_dir', metavar='BUILD_DIR',
        action='store', default=None,
        help='Accepted for compatibility with the CMake test targets. Unused.')
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
    run_test(args.test_exe, args.test_args)
    sys.exit(0)
