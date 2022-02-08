#!/usr/bin/python3 -i
#
# Copyright (c) 2022 LunarG, Inc.
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
import filecmp
import json
import os
import subprocess
import time

def set_env_var(key, value):
    if value is not None:
        os.environ[key] = value
    elif key in os.environ:
        del os.environ[key]

def main():
    # TODO : Make paths platform agnostic...
    # TODO : Make frames configurable...
    vulkan_sdk = os.getenv('VULKAN_SDK')
    parser = argparse.ArgumentParser(description='TODO : Description')
    parser.add_argument('--workload', type=str, default=os.path.join(vulkan_sdk, 'bin/vkcube.exe'))
    parser.add_argument('--screensshotjson', type=str, default=os.path.join(vulkan_sdk, 'bin/VkLayer_screenshot.json'))
    parser.add_argument('--gfxreconstructjson', type=str, default=os.path.join(vulkan_sdk, 'bin/VkLayer_gfxreconstruct.json'))
    parser.add_argument('--replay', type=str, default=os.path.join(vulkan_sdk, 'bin/gfxrecon-replay.exe'))
    parser.add_argument('--output', type=str, default=os.path.join(os.getcwd(), 'test_artifacts'))
    parser.add_argument('--frames', type=str, default='16,32') # 256 found a bug?!
    parser.add_argument('--duration', type=int, default=5)
    parser.add_argument('--gfxreconstructrepo', type=str, default='')
    parser.add_argument('--configuration', type=str, default='Debug')
    args = parser.parse_args()

    # If gfxreconstructrepo is set, use the local repo for capture and replay...
    if args.gfxreconstructrepo:
        args.gfxreconstructjson = os.path.join(args.gfxreconstructrepo, 'build/layer', args.configuration, 'VkLayer_gfxreconstruct.json')
        args.replay = os.path.join(args.gfxreconstructrepo, 'build/tools/replay', args.configuration, 'gfxrecon-replay.exe')

    # Configure gfxreconstruct and screenshot layers...
    os.environ['VK_LAYER_PATH'] = os.path.dirname(args.gfxreconstructjson) + os.pathsep + os.path.dirname(args.screensshotjson)
    os.environ['VK_INSTANCE_LAYERS'] = 'VK_LAYER_LUNARG_gfxreconstruct' + os.pathsep + 'VK_LAYER_LUNARG_screenshot'
    capture_results = os.path.join(args.output, 'capture_results')
    os.makedirs(capture_results, exist_ok=True)
    gfxr_file_name = 'gfxrecon_capture'
    gfxr_file_path = os.path.join(capture_results, gfxr_file_name + '.gfxr')
    set_env_var('GFXRECON_CAPTURE_FILE', gfxr_file_path)
    set_env_var('GFXRECON_CAPTURE_FRAMES', None)
    set_env_var('GFXRECON_CAPTURE_FILE_TIMESTAMP', '0')
    set_env_var('VK_SCREENSHOT_DIR', capture_results)
    set_env_var('VK_SCREENSHOT_FRAMES', args.frames)

    # Capture .gfxr and .ppm files...
    capture = subprocess.Popen(args.workload, creationflags=subprocess.DETACHED_PROCESS)
    time.sleep(args.duration)
    capture.terminate()

    # Configure screenshot layer...
    os.environ['VK_LAYER_PATH'] = os.path.dirname(args.screensshotjson)
    os.environ['VK_INSTANCE_LAYERS'] = 'VK_LAYER_LUNARG_screenshot'
    replay_results = os.path.join(args.output, 'replay_results')
    os.makedirs(replay_results, exist_ok=True)
    set_env_var('VK_SCREENSHOT_DIR', replay_results)
    set_env_var('VK_SCREENSHOT_FRAMES', args.frames)

    # Replay .gfxr with screenshots taken at the same frame indices as capture time...
    time.sleep(1)
    subprocess.run([args.replay, gfxr_file_path])
    time.sleep(1)

    # Diff the screenshots from capture and replay...
    match, mismatch, errors = filecmp.cmpfiles(capture_results, replay_results, ['16.ppm', '32.ppm'], shallow=True)
    print('\n\n================================================================================')
    print('match:', match)
    print('mismatch:', mismatch)
    print('errors:', errors)

if __name__ == "__main__":
    main()
