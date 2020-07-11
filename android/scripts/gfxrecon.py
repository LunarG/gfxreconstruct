#!/usr/bin/env python3
#
# Copyright (c) 2018-2019 LunarG, Inc.
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

import argparse
import os
import sys
import shlex
import subprocess

argv = sys.argv
argc = len(sys.argv)

# Supported commands
valid_commands = [
    'install-apk',
    'replay'
]

# Arguments
# gfxrecon install-apk <file>
# gfxrecon replay [-p | --push-file <file-on-desktop>] <file-on-device>

# Application info
app_name = 'com.lunarg.gfxreconstruct.replay'
app_activity = '"com.lunarg.gfxreconstruct.replay/android.app.NativeActivity"'
app_action = 'android.intent.action.MAIN'
app_category = 'android.intent.category.LAUNCHER'

# ADB commands
adb_install = 'adb install -g -t -r'
adb_start = 'adb shell am start -n {} -a {} -c {}'.format(app_activity, app_action, app_category)
adb_stop = 'adb shell am force-stop {}'.format(app_name)
adb_push = 'adb push'

def CreateCommandParser():
    parser = argparse.ArgumentParser(description='GFXReconstruct utility launcher for Android.')
    parser.add_argument('command', choices=valid_commands, metavar='command', help='Command to execute. Valid options are [{}]'.format(', '.join(valid_commands)))
    parser.add_argument('args', nargs=argparse.REMAINDER, help='Command-specific argument list. Specify -h after command name for more.')
    return parser

def CreateInstallApkParser():
    parser = argparse.ArgumentParser(prog=os.path.basename(sys.argv[0]) + ' install-apk', description='Install the replay tool.')
    parser.add_argument('file', help='APK file to install')
    return parser

def CreateReplayParser():
    parser = argparse.ArgumentParser(prog=os.path.basename(sys.argv[0]) + ' replay', description='Launch the replay tool.')
    parser.add_argument('-p', '--push-file', metavar='local-file', help='Local file to push to the location on device specified by <file>')
    parser.add_argument('--version', action='store_true', default=False, help='Print version information and exit (forwarded to replay tool)')
    parser.add_argument('--pause-frame', metavar='N', help='Pause after replaying frame number N (forwarded to replay tool)')
    parser.add_argument('--paused', action='store_true', default=False, help='Pause after replaying the first frame (same as "--pause-frame 1"; forwarded to replay tool)')
    parser.add_argument('--sfa', '--skip-failed-allocations', action='store_true', default=False, help='Skip vkAllocateMemory, vkAllocateCommandBuffers, and vkAllocateDescriptorSets calls that failed during capture (forwarded to replay tool)')
    parser.add_argument('--opcd', '--omit-pipeline-cache-data', action='store_true', default=False, help='Omit pipeline cache data from calls to vkCreatePipelineCache (forwarded to replay tool)')
    parser.add_argument('-m', '--memory-translation', metavar='<mode>', choices=['none', 'remap', 'realign', 'rebind'], help='Enable memory translation for replay on GPUs with memory types that are not compatible with the capture GPU\'s memory types.  Available modes are: none, remap, realign, rebind (forwarded to replay tool)')
    parser.add_argument('file', nargs='?', help='File on device to play (forwarded to replay tool)')
    return parser

def MakeExtrasString(args):
    arg_list = []

    if args.version:
        arg_list.append('--version')

    if args.pause_frame:
        arg_list.append('--pause-frame')
        arg_list.append('{}'.format(args.pause_frame))

    if args.paused:
        arg_list.append('--paused')

    if args.sfa:
        arg_list.append('--sfa')

    if args.opcd:
        arg_list.append('--opcd')

    if args.memory_translation:
        arg_list.append('-m')
        arg_list.append('{}'.format(args.memory_translation))

    if args.file:
        arg_list.append(args.file)
    elif not args.version:
        print('gfxrecon.py release: error: the following arguments are required: file')
        return None

    return ' '.join(arg_list)

def InstallApk(install_args):
    install_parser = CreateInstallApkParser()
    args = install_parser.parse_args(install_args)
    cmd = adb_install + ' ' + args.file
    print('Executing:', cmd)
    subprocess.check_call(shlex.split(cmd, posix='win' not in sys.platform))

def Replay(replay_args):
    replay_parser = CreateReplayParser()
    args = replay_parser.parse_args(replay_args)

    extras = MakeExtrasString(args)

    if extras:
        if args.push_file:
            cmd = ' '.join([adb_push, args.push_file, args.file])
            print('Executing:', cmd)
            subprocess.check_call(shlex.split(cmd, posix='win' not in sys.platform))

        print('Executing:', adb_stop)
        subprocess.check_call(shlex.split(adb_stop, posix='win' not in sys.platform))

        cmd = ' '.join([adb_start, '--es', '"args"', '"{}"'.format(extras)])
        print('Executing:', cmd)

        # Specify posix=False to prevent removal of quotes from adb extras.
        subprocess.check_call(shlex.split(cmd, posix=False))

if __name__ == '__main__':
    command_parser = CreateCommandParser()
    command = command_parser.parse_args()

    if command.command == 'install-apk':
        InstallApk(command.args)
    elif command.command == 'replay':
        Replay(command.args)
