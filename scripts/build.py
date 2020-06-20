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
DEFAULT_ARCHITECTURE = ARCHITECTURES[0]
BUILD_ROOT = os.path.abspath(
    os.path.join(os.path.split(os.path.abspath(__file__))[0], '..'))
BUILD_CONFIGS = {'debug': 'dbuild', 'release': 'build'}
if is_windows():
    BUILD_CONFIGS['debug'] = 'build'
CMAKE_VERSION_3_13 = distutils.version.StrictVersion('3.13.0')
CONFIGURATIONS = ['release', 'debug']
DEFAULT_CONFIGURATION = CONFIGURATIONS[0]
VERSION = distutils.version.StrictVersion('0.0.0')


class BuildError(Exception):
    '''
    Raised on a build error
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
        '-a', '--arch', dest='architecture',
        metavar='ARCH', action='store',
        choices=ARCHITECTURES, default=DEFAULT_ARCHITECTURE,
        help='Build target architecture. Can be one of: {0}'.format(
                ', '.join(ARCHITECTURES)))
    arg_parser.add_argument(
        '-c', '--config', dest='configuration',
        metavar='CONFIG', action='store',
        choices=CONFIGURATIONS, default=DEFAULT_CONFIGURATION,
        help='Build target configuration. Can be one of: {0}'.format(
            ', '.join(CONFIGURATIONS)))
    arg_parser.add_argument(
        '--clean', dest='clean', action='store_true', default=False,
        help='Clean the build targets')
    arg_parser.add_argument(
        '--clobber', dest='clobber', action='store_true', default=False,
        help='Clean the build targets, and remove build and intermediate files')
    arg_parser.add_argument(
        '--skip-update-deps', dest='skip_update_deps',
        action='store_true', default=False,
        help='Skip updating external dependencies')
    arg_parser.add_argument(
        '--code-style', dest='code_style',
        action='store_true', default=False,
        help='Apply C++ code style before compiling')
    arg_parser.add_argument(
        '--skip-tests', action='store_true', help='Skip running tests')
    arg_parser.add_argument('--test-archive', action='store_true',
                            help='Generate a test archive package')
    arg_parser.add_argument(
        '--skip-check-code-style', dest='skip_check_code_style',
        action='store_true', default=False,
        help='Skip checking C++ code style before compiling')
    arg_parser.add_argument(
        '--check-code-style-base', dest='check_code_style_base',
        metavar='BASE', action='store', default='HEAD',
        help='Git branch name or commit ID to use as the base for C++ code style comparison')
    arg_parser.add_argument(
        '--lint', dest='lint',
        action='store_true', default=False,
        help='Run static analysis lint tests on code')
    return arg_parser.parse_args()


def update_external_dependencies(args):
    '''
    Update git submodules
    '''
    if not args.skip_update_deps:
        update_git_submodule_result = subprocess.run(
            ['git', 'submodule', 'update', '--init'], cwd=BUILD_ROOT)
        if 0 != update_git_submodule_result.returncode:
            raise BuildError('failed to update git submodules')


def build_dir(args):
    '''
    Get the CMake build directory
    '''
    return os.path.join(BUILD_ROOT,
                        BUILD_CONFIGS[args.configuration],
                        platform.system().lower(),
                        args.architecture)


def cmake_version():
    '''
    Get the CMake version
    '''
    cmake_version_output = subprocess.check_output(
        ['cmake', '--version']).decode('utf-8')
    match = re.match(
        r'cmake version (?P<version>[\d\.]+)', cmake_version_output)
    if match is None:
        raise BuildError('failed to get CMake version')
    cmake_version = distutils.version.StrictVersion(match.group('version'))
    return cmake_version


def cmake_generate_options(args):
    '''
    CMake build file generation options
    '''
    generate_options = []
    if args.clean or args.clobber:
        generate_options.append('-DAPPLY_CPP_CODE_STYLE=OFF')
        generate_options.append('-DRUN_TESTS=OFF')
        generate_options.append('-DGENERATE_TEST_ARCHIVE=OFF')
    else:
        generate_options.append(
            '-DAPPLY_CPP_CODE_STYLE={}'.format(
                'ON' if args.code_style else 'OFF'))
        generate_options.append(
            '-DCHECK_CPP_CODE_STYLE={}'.format(
                'ON' if not args.skip_check_code_style else 'OFF'))
        generate_options.append(
            '-DCHECK_CPP_CODE_STYLE_BASE={}'.format(args.check_code_style_base))
        generate_options.append(
            '-DRUN_TESTS={}'.format('OFF' if args.skip_tests else 'ON'))
        generate_options.append(
            '-DGENERATE_TEST_ARCHIVE={}'.format(
                'ON' if args.test_archive else 'OFF'))
        generate_options.append(
            '-DCMAKE_CXX_CLANG_TIDY=clang-tidy;--format-style=file' if args.lint
            else '-UCMAKE_CXX_CLANG_TIDY')
    return generate_options


def cmake_generate_build_files(args):
    '''
    Use CMake to generate build files
    '''
    system = platform.system().lower()
    cmake_generate_args = [
        'cmake',
        '-DCMAKE_INSTALL_PREFIX=' + os.path.join(build_dir(args), 'install')]
    cmake_generate_env = os.environ.copy()
    if 'windows' == system:
        if 'x64' == args.architecture:
            cmake_generate_args.extend(['-A', 'x64'])
    else:
        if 'debug' == args.configuration:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Debug')
        else:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Release')
        if (shutil.which('clang') is not None) and\
                (shutil.which('clang++') is not None):
            cmake_generate_env['CC'] = 'clang'
            cmake_generate_env['CXX'] = 'clang++'
    for config, dir in BUILD_CONFIGS.items():
        for output in [('ARCHIVE', 'lib'), ('LIBRARY', 'bin'), ('RUNTIME', 'bin')]:
            cmake_generate_args.append(
                '-DCMAKE_{0}_OUTPUT_DIRECTORY_{1}={2}/{3}/{4}/{5}/{6}'.format(
                    output[0],
                    config.upper(),
                    BUILD_ROOT,
                    dir,
                    system,
                    args.architecture,
                    output[1]))
    cmake_generate_args.extend(cmake_generate_options(args))
    work_dir = BUILD_ROOT
    if(cmake_version() < CMAKE_VERSION_3_13):
        work_dir = build_dir(args)
        cmake_generate_args.append(BUILD_ROOT)
    else:
        cmake_generate_args.extend(['-S', '.', '-B', build_dir(args)])
    os.makedirs(work_dir, mode=0o744, exist_ok=True)
    cmake_generate_result = subprocess.run(
        cmake_generate_args, cwd=work_dir, env=cmake_generate_env)
    if 0 != cmake_generate_result.returncode:
        raise BuildError('failed to generate build files')


def cmake_build(args):
    '''
    Build using CMake
    '''
    cmake_build_args = ['cmake', '--build', '.']
    if is_windows():
        cmake_build_args.extend(
            ['--config', args.configuration.capitalize()])
    if args.clean or args.clobber:
        cmake_build_args.extend(['--target', 'clean'])
    cmake_build_result = subprocess.run(
        cmake_build_args, cwd=build_dir(args))
    if 0 != cmake_build_result.returncode:
        raise BuildError('cmake build failed')


# Main entry point
if '__main__' == __name__:
    try:
        args = parse_args()
        clean = args.clean or args.clobber
        if not clean:
            update_external_dependencies(args)
        build_dir_exists = os.path.exists(build_dir(args))
        if (clean and build_dir_exists) or (not clean):
            cmake_generate_build_files(args)
            cmake_build(args)
        if args.clobber and build_dir_exists:
            shutil.rmtree(build_dir(args))
    except Exception as error:
        print('Error', *(error.args))
        sys.exit(1)
    sys.exit(0)
