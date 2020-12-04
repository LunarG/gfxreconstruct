#!/usr/bin/env python3
#
# Copyright (c) 2018-2020 LunarG, Inc.
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
    parser.add_argument('-p', '--push-file', metavar='LOCAL_FILE', help='Local file to push to the location on device specified by <file>')
    parser.add_argument('--version', action='store_true', default=False, help='Print version information and exit (forwarded to replay tool)')
    parser.add_argument('--pause-frame', metavar='N', help='Pause after replaying frame number N (forwarded to replay tool)')
    parser.add_argument('--paused', action='store_true', default=False, help='Pause after replaying the first frame (same as "--pause-frame 1"; forwarded to replay tool)')
    parser.add_argument('--screenshot-all', action='store_true', default=False, help='Generate screenshots for all frames.  When this option is specified, --screenshots is ignored (forwarded to replay tool)')
    parser.add_argument('--screenshots', metavar='RANGES', help='Generate screenshots for the specified frames.  Target frames are specified as a comma separated list of frame ranges.  A frame range can be specified as a single value, to specify a single frame, or as two hyphenated values, to specify the first and last frames to process.  Frame ranges should be specified in ascending order and cannot overlap.  Note that frame numbering is 1-based (i.e. the first frame is frame 1).  Example: 200,301-305 will generate six screenshots (forwarded to replay tool)')
    parser.add_argument('--screenshot-format', metavar='FORMAT', choices=['bmp'], help='Image file format to use for screenshot generation.  Available formats are: bmp (forwarded to replay tool)')
    parser.add_argument('--screenshot-dir', metavar='DIR', help='Directory to write screenshots. Default is "/sdcard" (forwarded to replay tool)')
    parser.add_argument('--screenshot-prefix', metavar='PREFIX', help='Prefix to apply to the screenshot file name.  Default is "screenshot" (forwarded to replay tool)')
    parser.add_argument('--sfa', '--skip-failed-allocations', action='store_true', default=False, help='Skip vkAllocateMemory, vkAllocateCommandBuffers, and vkAllocateDescriptorSets calls that failed during capture (forwarded to replay tool)')
    parser.add_argument('--opcd', '--omit-pipeline-cache-data', action='store_true', default=False, help='Omit pipeline cache data from calls to vkCreatePipelineCache and skip calls to vkGetPipelineCacheData (forwarded to replay tool)')
    parser.add_argument('--surface-index', metavar='N', help='Restrict rendering to the Nth surface object created.  Used with captures that include multiple surfaces.  Default is -1 (render to all surfaces; forwarded to replay tool)')
    parser.add_argument('--sync', action='store_true', default=False, help='Synchronize after each queue submission with vkQueueWaitIdle (forwarded to replay tool)')
    parser.add_argument('--remove-unsupported', action='store_true', default=False, help='Remove unsupported extensions and features from instance and device creation parameters (forwarded to replay tool)')
    parser.add_argument('-m', '--memory-translation', metavar='MODE', choices=['none', 'remap', 'realign', 'rebind'], help='Enable memory translation for replay on GPUs with memory types that are not compatible with the capture GPU\'s memory types.  Available modes are: none, remap, realign, rebind (forwarded to replay tool)')
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

    if args.screenshot_all:
        arg_list.append('--screenshot-all')
    elif args.screenshots:
        arg_list.append('--screenshots')
        arg_list.append('{}'.format(args.screenshots))

    if args.screenshot_format:
        arg_list.append('--screenshot-format')
        arg_list.append('{}'.format(args.screenshot_format))

    if args.screenshot_dir:
        arg_list.append('--screenshot-dir')
        arg_list.append('{}'.format(args.screenshot_dir))

    if args.screenshot_prefix:
        arg_list.append('--screenshot-prefix')
        arg_list.append('{}'.format(args.screenshot_prefix))

    if args.sfa:
        arg_list.append('--sfa')

    if args.opcd:
        arg_list.append('--opcd')

    if args.surface_index:
        arg_list.append('--surface-index')
        arg_list.append('{}'.format(args.surface_index))

    if args.sync:
        arg_list.append('--sync')

    if args.remove_unsupported:
        arg_list.append('--remove-unsupported')

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
