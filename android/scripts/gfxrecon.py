#!/usr/bin/env python3
#
# Copyright (c) 2018-2023 LunarG, Inc.
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
    'multiwin-replay',
    'replay'
]

# Arguments
# gfxrecon install-apk <file>
# gfxrecon replay [-p | --push-file <file-on-desktop>] <file-on-device>
# gfxrecon multiwin-replay [-p | --push-file <file-on-desktop>] <file-on-device>

# Application info
app_name = 'com.lunarg.gfxreconstruct.replay'
app_activity = '"com.lunarg.gfxreconstruct.replay/android.app.NativeActivity"'
multiwin_app_activity = '"com.lunarg.gfxreconstruct.replay/.ReplayActivity"'
app_action = 'android.intent.action.MAIN'
app_category = 'android.intent.category.LAUNCHER'

# ADB commands
adb_install = 'adb install -g -t -r'
adb_sdk_version = 'adb shell getprop ro.build.version.sdk'
adb_stop = 'adb shell am force-stop {}'.format(app_name)
adb_push = 'adb push'
adb_devices = 'adb devices'

# Environment variable for android serial number
android_serial = 'ANDROID_SERIAL'

class DeviceSelectionException(Exception):
    pass

def QueryAvailableDevices():
    result = subprocess.run(shlex.split(adb_devices, posix='win' not in sys.platform), capture_output=True, check=True)
    devices = result.stdout.decode().strip().splitlines()[1:]
    return [device.split('\t')[0] for device in devices]

def CheckDeviceSelection():
    devices = QueryAvailableDevices()
    if len(devices) <= 1:
        return

    selection = os.getenv(android_serial)
    if selection is None or selection == '':
        raise DeviceSelectionException('Multiple devices detected - you must specify which one to use by setting ANDROID_SERIAL environment variable.')
    if selection not in devices:
        raise DeviceSelectionException(f'Selected ({selection}) device not present. Available devices: {devices}')

def CreateCommandParser():
    parser = argparse.ArgumentParser(description='GFXReconstruct utility launcher for Android.')
    parser.add_argument('command', choices=valid_commands, metavar='command', help='Command to execute. Valid options are [{}]'.format(', '.join(valid_commands)))
    parser.add_argument('args', nargs=argparse.REMAINDER, help='Command-specific argument list. Specify -h after command name for more.')
    return parser

def CreateInstallApkParser():
    parser = argparse.ArgumentParser(prog=os.path.basename(sys.argv[0]) + ' install-apk', description='Install the replay tool.')
    parser.add_argument('file', help='APK file to install')
    parser.add_argument('-s', '--select', metavar='DEVICE_ID', help='Specify the destination device id. Needed if multiple devices are attached.')
    return parser

def CreateReplayParser():
    parser = argparse.ArgumentParser(prog=os.path.basename(sys.argv[0]) + ' replay', description='Launch the replay tool.')
    parser.add_argument('-p', '--push-file', metavar='LOCAL_FILE', help='Local file to push to the location on device specified by <file>')
    parser.add_argument('--version', action='store_true', default=False, help='Print version information and exit (forwarded to replay tool)')
    parser.add_argument('--log-level', metavar='LEVEL', help='Specify highest level message to log. Options are: debug, info, warning, error, and fatal. Default is info. (forwarded to replay tool)')
    parser.add_argument('--log-file', metavar='DEVICE_FILE', help='Write log messages to a file at the specified path instead of logcat (forwarded to replay tool)')
    parser.add_argument('--debug-messenger-level', metavar='LEVEL', help='Specify highest debug messenger severity level. Options are: debug, info, warning, and error. Default is warning. (forwarded to replay tool)')
    parser.add_argument('--pause-frame', metavar='N', help='Pause after replaying frame number N (forwarded to replay tool)')
    parser.add_argument('--paused', action='store_true', default=False, help='Pause after replaying the first frame (same as "--pause-frame 1"; forwarded to replay tool)')
    parser.add_argument('--cpu-mask', metavar='binary_mask', help='Set of CPU cores used by the replayer. `binary-mask` is a succession of "0" and "1" that specifies used/unused cores read from left to right. For example "10010" activates the first and fourth cores and deactivate all other cores. If the option is not set, all cores can be used. If the option is set only for some cores, the other cores are not used. (forwarded to replay tool)')
    parser.add_argument('--screenshot-all', action='store_true', default=False, help='Generate screenshots for all frames.  When this option is specified, --screenshots is ignored (forwarded to replay tool)')
    parser.add_argument('--screenshots', metavar='RANGES', help='Generate screenshots for the specified frames.  Target frames are specified as a comma separated list of frame ranges.  A frame range can be specified as a single value, to specify a single frame, or as two hyphenated values, to specify the first and last frames to process.  Frame ranges should be specified in ascending order and cannot overlap.  Note that frame numbering is 1-based (i.e. the first frame is frame 1).  Example: 200,301-305 will generate six screenshots (forwarded to replay tool)')
    parser.add_argument('--screenshot-interval', metavar='INTERVAL', help='Specifies the number of frames between two screenshots within a screenshot range. Example: If screenshot range is 10-15 and interval is 2, screenshot will be generated for frames 10, 12 and 14. Default is 1. (forwarded to replay tool)')
    parser.add_argument('--screenshot-format', metavar='FORMAT', choices=['bmp', 'png'], help='Image file format to use for screenshot generation.  Available formats are: bmp, png (forwarded to replay tool)')
    parser.add_argument('--screenshot-dir', metavar='DIR', help='Directory to write screenshots. Default is "/sdcard" (forwarded to replay tool)')
    parser.add_argument('--screenshot-prefix', metavar='PREFIX', help='Prefix to apply to the screenshot file name.  Default is "screenshot" (forwarded to replay tool)')
    parser.add_argument('--screenshot-size', metavar='SIZE', help='Screenshot dimensions. Ignored if --screenshot-scale is specified.  Expected format is <width>x<height>.')
    parser.add_argument('--screenshot-scale', metavar='SCALE', help='Scale screenshot dimensions. Overrides --screenshot-size, if specified. Expects a number which can be decimal')
    parser.add_argument('--sfa', '--skip-failed-allocations', action='store_true', default=False, help='Skip vkAllocateMemory, vkAllocateCommandBuffers, and vkAllocateDescriptorSets calls that failed during capture (forwarded to replay tool)')
    parser.add_argument('--opcd', '--omit-pipeline-cache-data', action='store_true', default=False, help='Omit pipeline cache data from calls to vkCreatePipelineCache and skip calls to vkGetPipelineCacheData (forwarded to replay tool)')
    parser.add_argument('--surface-index', metavar='N', help='Restrict rendering to the Nth surface object created.  Used with captures that include multiple surfaces.  Default is -1 (render to all surfaces; forwarded to replay tool)')
    parser.add_argument('--sync', action='store_true', default=False, help='Synchronize after each queue submission with vkQueueWaitIdle (forwarded to replay tool)')
    parser.add_argument('--remove-unsupported', action='store_true', default=False, help='Remove unsupported extensions and features from instance and device creation parameters (forwarded to replay tool)')
    parser.add_argument('--validate', action='store_true', default=False, help='Enables the Khronos Vulkan validation layer (forwarded to replay tool)')
    parser.add_argument('--onhb', '--omit-null-hardware-buffers', action='store_true', default=False, help='Omit Vulkan calls that would pass a NULL AHardwareBuffer* (forwarded to replay tool)')
    parser.add_argument('--use-colorspace-fallback', action='store_true', default=False, help='Swap the swapchain color space if unsupported by replay device. Check if color space is not supported by replay device and swap to VK_COLOR_SPACE_SRGB_NONLINEAR_KHR. (forwarded to replay tool).')
    parser.add_argument('--offscreen-swapchain-frame-boundary', action='store_true', default=False, help='Should only be used with offscreen swapchain. Activates the extension VK_EXT_frame_boundary (always supported if trimming, checks for driver support otherwise) and inserts command buffer submission with VkFrameBoundaryEXT where vkQueuePresentKHR was called in the original capture. This allows preserving frames when capturing a replay that uses. offscreen swapchain. (forwarded to replay tool)')
    parser.add_argument('--mfr', '--measurement-frame-range', metavar='START-END', help='Custom framerange to measure FPS for. This range will include the start frame but not the end frame. The measurement frame range defaults to all frames except the loading frame but can be configured for any range. If the end frame is past the last frame in the trace it will be clamped to the frame after the last (so in that case the results would include the last frame). (forwarded to replay tool)')
    parser.add_argument('--measurement-file', metavar='DEVICE_FILE', help='Write measurements to a file at the specified path. Default is: \'/sdcard/gfxrecon-measurements.json\' on android and \'./gfxrecon-measurements.json\' on desktop. (forwarded to replay tool)')
    parser.add_argument('--quit-after-measurement-range', action='store_true', default=False, help='If this is specified the replayer will abort when it reaches the <end_frame> specified in the --measurement-frame-range argument. (forwarded to replay tool)')
    parser.add_argument('--flush-measurement-range', action='store_true', default=False, help='If this is specified the replayer will flush and wait for all current GPU work to finish at the start and end of the measurement range. (forwarded to replay tool)')
    parser.add_argument('--flush-inside-measurement-range', action='store_true', default=False, help='If this is specified the replayer will flush and wait for all current GPU work to finish at end of each frame inside the measurement range. (forwarded to replay tool)')
    parser.add_argument('--sgfs', '--skip-get-fence-status', metavar='STATUS', default=0, help='Specify behaviour to skip calls to vkWaitForFences and vkGetFenceStatus. Default is 0 - No skip (forwarded to replay tool)')
    parser.add_argument('--sgfr', '--skip-get-fence-ranges', metavar='FRAME-RANGES', default='', help='Frame ranges where --sgfs applies. Default is all frames (forwarded to replay tool)')
    parser.add_argument('--wait-before-present', action='store_true', default=False, help='Force wait on completion of queue operations for all queues before calling Present. This is needed for accurate acquisition of instrumentation data on some platforms.')
    parser.add_argument('-m', '--memory-translation', metavar='MODE', choices=['none', 'remap', 'realign', 'rebind'], help='Enable memory translation for replay on GPUs with memory types that are not compatible with the capture GPU\'s memory types.  Available modes are: none, remap, realign, rebind (forwarded to replay tool)')
    parser.add_argument('--swapchain', metavar='MODE', choices=['virtual', 'captured', 'offscreen'], help='Choose a swapchain mode to replay. Available modes are: virtual, captured, offscreen (forwarded to replay tool)')
    parser.add_argument('--vssb', '--virtual-swapchain-skip-blit', action='store_true', default=False, help='Skip blit to real swapchain to gain performance during replay.')
    parser.add_argument('--use-captured-swapchain-indices', action='store_true', default=False, help='Same as "--swapchain captured". Ignored if the "--swapchain" option is used.')
    parser.add_argument('file', nargs='?', help='File on device to play (forwarded to replay tool)')
    parser.add_argument('--dump-resources', metavar='DUMP_RESOURCES', help='The capture file will be examined, and <submit-index,command-index,draw-call-index> will be converted to <arg> as used in --dump-resources <arg>.  The converted args will be used used as the args for dump resources.')
    parser.add_argument('--dump-resources-before-draw', action='store_true', default=False, help= 'In addition to dumping gpu resources after the Vulkan draw calls specified by the --dump-resources argument, also dump resources before the draw calls.')
    parser.add_argument('--dump-resources-image-format', metavar='FORMAT', choices=['bmp', 'png'], help='Image file format to use when dumping image resources. Available formats are: bmp, png')
    parser.add_argument('--dump-resources-scale', metavar='DR_SCALE', help='tScale images generated by dump resources by the given scale factor. The scale factor must be a floating point number greater than 0. Values greater than 10 are capped at 10. Default value is 1.0.')
    parser.add_argument('--dump-resources-dir', metavar='DIR', help='Directory to write dump resources output files. Default is "/sdcard" (forwarded to replay tool)')
    parser.add_argument('--dump-resources-dump-depth-attachment', action='store_true', default=False, help= 'Dump depth attachment when dumping a draw call. Default is false.')
    parser.add_argument('--dump-resources-dump-color-attachment-index', metavar='N', help='Specify which color attachment to dump when dumping draw calls. It should be an unsigned zero based integer. Default is to dump all color attachments.')
    parser.add_argument('--dump-resources-dump-vertex-index-buffers', action='store_true', default=False, help= 'Enables dumping of vertex and index buffers while dumping draw call resources. Default is disabled.')
    parser.add_argument('--dump-resources-json-output-per-command', action='store_true', default=False, help= 'Enables storing a json output file for each dumped command. Default is disabled.')
    parser.add_argument('--dump-resources-dump-immutable-resources', action='store_true', default=False, help= 'Dump immutable immutable shader resources.')
    parser.add_argument('--dump-resources-dump-all-image-subresources', action='store_true', default=False, help= 'Dump all available mip levels and layers when dumping images.')
    parser.add_argument('--dump-resources-dump-raw-images', action='store_true', default=False, help= 'Dump images verbatim as raw binary files.')
    parser.add_argument('--dump-resources-dump-separate-alpha', action='store_true', default=False, help= 'Dump image alpha in a separate image file.')
    parser.add_argument('--dump-resources-dump-unused-vertex-bindings', action='store_true', default=False, help= 'Dump a vertex binding even if no vertex attributes references it.')
    parser.add_argument('--pbi-all', action='store_true', default=False, help='Print all block information.')
    parser.add_argument('--pbis', metavar='RANGES', default=False, help='Print block information between block index1 and block index2')
    parser.add_argument('--pcj', '--pipeline-creation-jobs', action='store_true', default=False, help='Specify the number of pipeline-creation-jobs or background-threads.')
    parser.add_argument('--save-pipeline-cache', metavar='DEVICE_FILE', help='If set, produces pipeline caches at replay time instead of using the one saved at capture time and save those caches in DEVICE_FILE. (forwarded to replay tool)')
    parser.add_argument('--load-pipeline-cache', metavar='DEVICE_FILE', help='If set, loads data created by the `--save-pipeline-cache` option in DEVICE_FILE and uses it to create the pipelines instead of the pipeline caches saved at capture time. (forwarded to replay tool)')
    parser.add_argument('--add-new-pipeline-caches', action='store_true', default=False, help='If set, allows gfxreconstruct to create new vkPipelineCache objects when it encounters a pipeline created without cache. This option can be used in coordination with `--save-pipeline-cache` and `--load-pipeline-cache`. (forwarded to replay tool)')
    parser.add_argument('--quit-after-frame', metavar='FRAME', help='Specify a frame after which replay will terminate.')
    parser.add_argument('--screenshot-ignore-FrameBoundaryANDROID', action='store_true', default=False, help='If set, frames switced with vkFrameBoundANDROID will be ignored from the screenshot handler.')

    return parser

def MakeExtrasString(args):
    arg_list = []

    if args.version:
        arg_list.append('--version')

    if args.log_level:
        arg_list.append('--log-level')
        arg_list.append('{}'.format(args.log_level))

    if args.log_file:
        arg_list.append('--log-file')
        arg_list.append('{}'.format(args.log_file))

    if args.debug_messenger_level:
        arg_list.append('--debug-messenger-level')
        arg_list.append('{}'.format(args.debug_messenger_level))

    if args.pause_frame:
        arg_list.append('--pause-frame')
        arg_list.append('{}'.format(args.pause_frame))

    if args.paused:
        arg_list.append('--paused')

    if args.cpu_mask:
        arg_list.append('--cpu-mask')
        arg_list.append('{}'.format(args.cpu_mask))

    if args.screenshot_all:
        arg_list.append('--screenshot-all')
    elif args.screenshots:
        arg_list.append('--screenshots')
        arg_list.append('{}'.format(args.screenshots))

    if args.screenshot_interval:
        arg_list.append('--screenshot-interval')
        arg_list.append('{}'.format(args.screenshot_interval))

    if args.screenshot_format:
        arg_list.append('--screenshot-format')
        arg_list.append('{}'.format(args.screenshot_format))

    if args.screenshot_dir:
        arg_list.append('--screenshot-dir')
        arg_list.append('{}'.format(args.screenshot_dir))

    if args.screenshot_prefix:
        arg_list.append('--screenshot-prefix')
        arg_list.append('{}'.format(args.screenshot_prefix))

    if args.screenshot_size:
        arg_list.append('--screenshot-size')
        arg_list.append('{}'.format(args.screenshot_size))

    if args.screenshot_scale:
        arg_list.append('--screenshot-scale')
        arg_list.append('{}'.format(args.screenshot_scale))

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

    if args.validate:
        arg_list.append('--validate')

    if args.onhb:
        arg_list.append('--onhb')

    if args.use_captured_swapchain_indices:
        arg_list.append('--use-captured-swapchain-indices')

    if args.use_colorspace_fallback:
        arg_list.append('--use-colorspace-fallback')

    if args.mfr:
        arg_list.append('--mfr')
        arg_list.append('{}'.format(args.mfr))

    if args.measurement_file:
        arg_list.append('--measurement-file')
        arg_list.append('{}'.format(args.measurement_file))

    if args.quit_after_measurement_range:
        arg_list.append('--quit-after-measurement-range')

    if args.flush_measurement_range:
        arg_list.append('--flush-measurement-range')

    if args.flush_inside_measurement_range:
        arg_list.append('--flush-inside-measurement-range')

    if args.swapchain:
        arg_list.append('--swapchain')
        arg_list.append('{}'.format(args.swapchain))

    if args.offscreen_swapchain_frame_boundary:
        arg_list.append('--offscreen-swapchain-frame-boundary')

    if args.vssb:
        arg_list.append('--vssb')

    if args.sgfs:
        arg_list.append('--sgfs')
        arg_list.append('{}'.format(args.sgfs))

    if args.sgfr:
        arg_list.append('--sgfr')
        arg_list.append('{}'.format(args.sgfr))

    if args.memory_translation:
        arg_list.append('-m')
        arg_list.append('{}'.format(args.memory_translation))

    if args.wait_before_present:
        arg_list.append('--wait-before-present')

    if args.dump_resources:
        arg_list.append('--dump-resources')
        arg_list.append('{}'.format(args.dump_resources))

    if args.dump_resources_before_draw:
        arg_list.append('--dump-resources-before-draw')

    if args.dump_resources_image_format:
        arg_list.append('--dump-resources-image-format')
        arg_list.append('{}'.format(args.dump_resources_image_format))

    if args.dump_resources_scale:
        arg_list.append('--dump-resources-scale')
        arg_list.append('{}'.format(args.dump_resources_scale))

    if args.dump_resources_dir:
        arg_list.append('--dump-resources-dir')
        arg_list.append('{}'.format(args.dump_resources_dir))

    if args.dump_resources_dump_depth_attachment:
        arg_list.append('--dump-resources-dump-depth-attachment')

    if args.dump_resources_dump_color_attachment_index:
        arg_list.append('--dump-resources-dump-color-attachment-index')
        arg_list.append('{}'.format(args.dump_resources_dump_color_attachment_index))

    if args.dump_resources_dump_vertex_index_buffers:
        arg_list.append('--dump-resources-dump-vertex-index-buffers')

    if args.dump_resources_json_output_per_command:
        arg_list.append('--dump-resources-json-output-per-command')

    if args.dump_resources_dump_immutable_resources:
        arg_list.append('--dump-resources-dump-immutable-resources')

    if args.dump_resources_dump_all_image_subresources:
        arg_list.append('--dump-resources-dump-all-image-subresources')

    if args.dump_resources_dump_raw_images:
        arg_list.append('--dump-resources-dump-raw-images')

    if args.dump_resources_dump_separate_alpha:
        arg_list.append('--dump-resources-dump-separate-alpha')

    if args.dump_resources_dump_unused_vertex_bindings:
        arg_list.append('--dump-resources-dump-unused-vertex-bindings')

    if args.pbi_all:
        arg_list.append('--pbi-all')

    if args.pbis:
        arg_list.append('--pbis')
        arg_list.append('{}'.format(args.pbis))

    if args.pcj:
        arg_list.append('--pcj')
        arg_list.append('{}'.format(args.pcj))

    if args.save_pipeline_cache:
        arg_list.append('--save-pipeline-cache')
        arg_list.append('{}'.format(args.save_pipeline_cache))

    if args.load_pipeline_cache:
        arg_list.append('--load-pipeline-cache')
        arg_list.append('{}'.format(args.load_pipeline_cache))

    if args.add_new_pipeline_caches:
        arg_list.append('--add-new-pipeline-caches')

    if args.quit_after_frame:
        arg_list.append('--quit-after-frame')
        arg_list.append('{}'.format(args.quit_after_frame))

    if args.screenshot_ignore_FrameBoundaryANDROID:
        arg_list.append('--screenshot-ignore-FrameBoundaryANDROID')

    if args.file:
        arg_list.append(args.file)
    elif not args.version:
        print('gfxrecon.py release: error: the following arguments are required: file')
        return None

    return ' '.join(arg_list)

def InstallApk(install_args):
    install_parser = CreateInstallApkParser()
    args = install_parser.parse_args(install_args)
    sdk = int(subprocess.check_output(shlex.split(adb_sdk_version)).decode())
    force_queryable = ' --force-queryable' if sdk >= 30 else ''
    cmd = adb_install + force_queryable + ' ' + args.file

    CheckDeviceSelection()

    print('Executing:', cmd)
    subprocess.check_call(shlex.split(cmd, posix='win' not in sys.platform))

def ReplayCommon(replay_args, activity):
    replay_parser = CreateReplayParser()
    args = replay_parser.parse_args(replay_args)

    extras = MakeExtrasString(args)

    CheckDeviceSelection()

    if extras:
        if args.push_file:
            cmd = ' '.join([adb_push, args.push_file, args.file])
            print('Executing:', cmd)
            subprocess.check_call(shlex.split(cmd, posix='win' not in sys.platform))

        print('Executing:', adb_stop)
        subprocess.check_call(shlex.split(adb_stop, posix='win' not in sys.platform))

        adb_start = 'adb shell am start -n {} -a {} -c {}'.format(activity, app_action, app_category)

        cmd = ' '.join([adb_start, '--es', '"args"', '"{}"'.format(extras)])
        print('Executing:', cmd)

        # Specify posix=False to prevent removal of quotes from adb extras.
        subprocess.check_call(shlex.split(cmd, posix=False))

def Replay(replay_args):
    ReplayCommon(replay_args, app_activity)

def MultiWinReplay(replay_args):
    ReplayCommon(replay_args, multiwin_app_activity)

if __name__ == '__main__':
    devices = QueryAvailableDevices()

    command_parser = CreateCommandParser()
    command = command_parser.parse_args()

    if command.command == 'install-apk':
        InstallApk(command.args)
    elif command.command == 'replay':
        Replay(command.args)
    elif command.command == 'multiwin-replay':
        MultiWinReplay(command.args)
