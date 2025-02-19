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
GFXReconstruct build script
'''

import argparse
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

def is_mac():
    '''
    Check if the system is macOS
    '''
    return 'darwin' == platform.system().lower()

ARCHITECTURES = ['x64', 'x86', 'arm', 'arm64']
if is_mac():
    ARCHITECTURES = ['universal', 'x64', 'arm64']
DEFAULT_ARCHITECTURE = ARCHITECTURES[0]
BUILD_ROOT = os.path.abspath(
    os.path.join(os.path.split(os.path.abspath(__file__))[0], '..'))
BUILD_CONFIGS = {'debug': 'dbuild', 'release': 'build'}
CONFIGURATIONS = ['release', 'debug']
DEFAULT_CONFIGURATION = CONFIGURATIONS[0]
VERSION = '0.0.0'


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
                            action='version', version=VERSION)
    arg_parser.add_argument('--build-dir', dest='build_dir',
                            metavar='PATH', action='store', default=None,
                            help='Directory for build files. When not specified, defaults to <build|dbuild>/<platform>/<architecture>/cmake_output')
    arg_parser.add_argument('--install-dir', dest='install_dir',
                            metavar='PATH', action='store', default=None,
                            help='Install directory for build artifacts. When not specified, defaults to <build|dbuild>/<platform>/<architecture>/output')
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
    arg_parser.add_argument('-j', '--parallel', dest='jobs',
            action='store', default=None,
            help='Specify a parallel build level. Level 0 is equivalent to the use of all logical CPUs')
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
        '--test-apps', dest='test_apps',
        action='store_true', default=False,
        help='Build test apps')
    arg_parser.add_argument(
        '--cmake-system-version', dest='cmake_system_version',
        type=str, default="10.0.20348.0",help='Select SDK version')
    arg_parser.add_argument(
        '--skip-d3d12-support', dest='skip_d3d12_support',
        action='store_true', default=False,help='Skip Direct3D 12 build')
    arg_parser.add_argument(
        '--build-launcher', dest='build_launcher',
        action='store_true', default=False,help='Build Launcher')
    arg_parser.add_argument(
        '--lint', dest='lint',
        action='store_true', default=False,
        help='Run static analysis lint tests on code')
    arg_parser.add_argument(
        '--cmake-extra', dest='cmake_extra',
        action='append', default=[],
        help='Extra variables to set on the cmake invocation')
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


def prefix_dir(configuration, architecture):
    '''Get the CMake build directory
    '''
    return os.path.join(BUILD_ROOT,
                        BUILD_CONFIGS[configuration],
                        platform.system().lower(),
                        architecture)


def get_install_dir(user_install_dir, configuration, architecture):
    '''Get the build output directory

    This is the directory that will hold the compiled, linked and generated
    outputs of the build.
    '''
    if user_install_dir:
        return user_install_dir
    else:
        return os.path.join(prefix_dir(configuration, architecture), 'output')


def get_build_dir(user_build_dir, configuration, architecture):
    '''Get the CMake files output directory

    This is the directory that will hold the CMake cache, and generated build
    files.
    '''
    if user_build_dir:
        return user_build_dir
    else:
        return os.path.join(prefix_dir(configuration, architecture), 'cmake_output')


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
    cmake_version = [int(x) for x in match.group('version').split('.')]
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
            '-DGFXRECON_INCLUDE_TEST_APPS={}'.format('ON' if args.test_apps else 'OFF'))
        generate_options.append(
            '-DGENERATE_TEST_ARCHIVE={}'.format(
                'ON' if args.test_archive else 'OFF'))
        generate_options.append(
            '-DCMAKE_CXX_CLANG_TIDY=clang-tidy;--format-style=file' if args.lint
            else '-UCMAKE_CXX_CLANG_TIDY')
        if args.cmake_system_version:
            generate_options.append(
                '-DCMAKE_SYSTEM_VERSION={}'.format(
                    args.cmake_system_version))
        generate_options.append(
            '-DD3D12_SUPPORT={}'.format(
                'ON' if not args.skip_d3d12_support else 'OFF'))
        generate_options.append(
            '-DBUILD_LAUNCHER_AND_INTERCEPTOR={}'.format(
                'OFF' if not args.build_launcher else 'ON'))
        generate_options.extend('-D' + arg for arg in args.cmake_extra)
    
    return generate_options


def cmake_generate_build_files(args):
    '''
    Use CMake to generate build files
    '''
    system = platform.system().lower()
    cmake_generate_args = [
        'cmake',
        '-DCMAKE_INSTALL_PREFIX=' + get_install_dir(args.install_dir, args.configuration, args.architecture)]
    cmake_generate_env = os.environ.copy()
    if 'windows' == system:
        if 'x64' == args.architecture:
            cmake_generate_args.extend(['-A', 'x64'])
        elif 'x86' == args.architecture:
            cmake_generate_args.extend(['-A', 'Win32'])
        elif 'arm64' == args.architecture:
            cmake_generate_args.extend(['-A', 'ARM64'])
    elif 'darwin' == system:
        if 'debug' == args.configuration:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Debug')
        else:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Release')
        if 'universal' == args.architecture:
            cmake_generate_args.append('-DCMAKE_OSX_ARCHITECTURES=x86_64;arm64')
        elif 'x64' == args.architecture:
            cmake_generate_args.append('-DCMAKE_OSX_ARCHITECTURES=x86_64')
        elif 'arm64' == args.architecture:
            cmake_generate_args.append('-DCMAKE_OSX_ARCHITECTURES=arm64')
    else:
        if 'debug' == args.configuration:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Debug')
        else:
            cmake_generate_args.append('-DCMAKE_BUILD_TYPE=Release')
        if 'x86' == args.architecture:
            toolchain_path = os.path.join(BUILD_ROOT, "cmake", "toolchain", "linux_x86_32.cmake")
            cmake_generate_args.append('-DCMAKE_TOOLCHAIN_FILE={}'.format(toolchain_path))
        elif 'arm' == args.architecture:
            toolchain_path = os.path.join(BUILD_ROOT, "cmake", "toolchain", "linux_arm.cmake")
            cmake_generate_args.append('-DCMAKE_TOOLCHAIN_FILE={}'.format(toolchain_path))
        elif 'arm64' == args.architecture:
            toolchain_path = os.path.join(BUILD_ROOT, "cmake", "toolchain", "linux_arm64.cmake")
            cmake_generate_args.append('-DCMAKE_TOOLCHAIN_FILE={}'.format(toolchain_path))
    cmake_generate_args.append('-DPYTHON={0}'.format(sys.executable))
    cmake_generate_args.extend(cmake_generate_options(args))
    work_dir = BUILD_ROOT
    cmake_generate_args.extend([
        '-S', '.',
        '-B', get_build_dir(args.build_dir, args.configuration, args.architecture)])
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

    if args.jobs:
        if args.jobs == '0':
            args.jobs = str(os.cpu_count()) if (os.cpu_count() is not None) else '1'
        cmake_build_args.extend(['--parallel', args.jobs])
    if is_windows():
        cmake_build_args.extend(
            ['--config', args.configuration.capitalize()])
    if args.clean or args.clobber:
        cmake_build_args.extend(['--target', 'clean'])
    cmake_build_result = subprocess.run(
        cmake_build_args,
        cwd=get_build_dir(args.build_dir, args.configuration, args.architecture))
    if 0 != cmake_build_result.returncode:
        raise BuildError('cmake build failed')
    if not (args.clean or args.clobber):
        cmake_install_args = ['cmake', '--install', '.']
        if is_windows():
            cmake_install_args.extend(
                ['--config', args.configuration.capitalize()])
        cmake_install_result = subprocess.run(
            cmake_install_args,
            cwd=get_build_dir(args.build_dir, args.configuration, args.architecture))
        if 0 != cmake_install_result.returncode:
            raise BuildError('cmake install failed')


# Main entry point
if '__main__' == __name__:
    args = parse_args()
    clean = args.clean or args.clobber
    if not clean:
        update_external_dependencies(args)
    build_dir = get_build_dir(args.build_dir, args.configuration, args.architecture)
    build_dir_exists = os.path.exists(build_dir)
    if (clean and build_dir_exists) or (not clean):
        cmake_generate_build_files(args)
        cmake_build(args)
    if args.clobber:
        if build_dir_exists:
            shutil.rmtree(build_dir)
        install_dir = get_install_dir(args.install_dir, args.configuration, args.architecture)
        if os.path.exists(install_dir):
            shutil.rmtree(install_dir)
    sys.exit(0)
