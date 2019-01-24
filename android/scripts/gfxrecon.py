#!/usr/bin/env python3
#
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

import os
import sys
import shlex
import subprocess

argv = sys.argv
argc = len(sys.argv)

# Supported commands
commands = [
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

def PrintUsage():
    print('gfxrecon.py usage:')
    print('\tgfxrecon.py install-apk <file>')
    print('\tgfxrecon.py replay [-p | --push-file <file-on-desktop>] <file-on-device>')

def InstallApk():
    if argc != 3:
        PrintUsage()
    else:
        cmd = adb_install + ' ' + argv[2]
        print('Executing:', cmd)
        subprocess.check_call(shlex.split(cmd))

def Replay():
    filename = ''
    push_source = ''

    if argc != 3 or argc != 5:
        if argc == 5:
            if argv[2] in ['-p', '--push-file']:
                push_source = argv[3]
                filename = argv[4]
            elif argv[3] in ['-p', '--push-file']:
                filename = argv[2]
                push_source = argv[4]
        else:
            filename = argv[2]

    if filename:
        if push_source:
            cmd = adb_push + ' ' + push_source + ' ' + filename
            print('Executing:', cmd)
            subprocess.check_call(shlex.split(cmd))

        print('Executing:', adb_stop)
        subprocess.check_call(shlex.split(adb_stop))

        cmd = adb_start + ' ' + '--es' + ' ' + '"args"' + ' "' + filename + '"'
        print('Executing:', cmd)

        # Specify posix=False to prevent removal of quotes from adb extras.
        subprocess.check_call(shlex.split(cmd, posix=False))
    else:
        PrintUsage()

if __name__ == '__main__':
    if argc > 1 and argv[1] in commands:
        if argv[1] == 'install-apk':
            InstallApk()
        elif argv[1] == 'replay':
            Replay()
    else:
        PrintUsage()
