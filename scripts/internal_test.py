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

# AMD internal full functional tests

import argparse
import time
import datetime
import unittest
import distutils.version
import os
import platform
import subprocess
import sys
import shutil
import xmlrunner
from PIL import Image
import zipfile

VERSION = distutils.version.StrictVersion('0.0.0')
TEST_RESULT_FOLDER = "TestResult"
LOCAL_TEST_DST_PATH = "TestApp"
TEST_SRC_PATH = "TestSrc"
APPS_SCREENSHOT_FRAMES = "100,150,200,250,300"
RECAP_SCREENSHOT_FRAMES = "4000,4050,4100,4150,4200"
SCREENSHOT_COUNT = 5
TOLERANCE = 0.03
TRIM_RANGE = "3800-4300"
TRIM_PLAYBACK_SCREENSHOT = "200,250,300,350,400"


def parse_args():
    '''
    Parse command line arguments
    '''
    arg_parser = argparse.ArgumentParser(
        description="gfxreconstruct internal test script",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    arg_parser.add_argument(
        '--version', dest='version',
        action='version', version=str(VERSION))

    default_bin_path = os.path.join(
        os.getcwd(), "build", platform.system().lower(), "x64", "bin")
    arg_parser.add_argument(
        '--binary-path', dest='binary_path', type=str, default=default_bin_path,
        help='Folder path containing the GFXReconstruct binary')
    arg_parser.add_argument(
        '--layer-path', dest='layer_path', type=str, default=default_bin_path,
        help='Folder path containing the GFXReconstruct layers')
    arg_parser.add_argument(
        '--src-path', nargs='+', dest='src_path_list', default=["\\\\bender\\xcaptan_depot\\GoldenTraces\\gfxrec\\Samples_Win"],
        help='Folder path(s) containing the test app executables and/or golden trace files to be downloaded to the user specified dst-path or \"TestApp\" folder by default')
    arg_parser.add_argument(
        '--dst-path', dest='dst_path', type=str, default=LOCAL_TEST_DST_PATH,
        help='Local folder path(s) containing the test app executables and/or golden trace files to be downloaded from src path')
    arg_parser.add_argument(
        '--skip-test-app', dest='skip_test_app',
        action='store_true', default=False,
        help='Skip running Vulkan app testings')
    arg_parser.add_argument(
        '--skip-test-game', dest='skip_test_game',
        action='store_true', default=False,
        help='Skip running game title testings')
    arg_parser.add_argument(
        '--skip-sync-trace', dest='skip_sync_trace',
        action='store_true', default=False,
        help='Skip sync down golden traces or app from server path (i.e. test path)')
    return arg_parser.parse_args()


def get_system_gpu():
    '''
    get system GPU name
    '''
    try:
        if platform.system().lower() == "windows":
            output = subprocess.check_output(
                "wmic PATH Win32_videocontroller GET description")
            info = output.split(b"\r\r\n")
            gpu = info[1].decode("utf-8")
            gpu = gpu.strip()
        elif platform.system().lower() == "linux":
            gpu = subprocess.check_output("lspci | grep VGA")
            gpu = gpu.strip()
            gpu = gpu.replace(":", "_")
            gpu = gpu.replace(".", "_")
        else:
            gpu = "UNKNOWN"
    except:
        gpu = "UNKNOWN"
    gpu = gpu.replace(" ", "_")
    print("GPU detected = "+gpu)
    return gpu


def get_test(name, classname):
    '''
    get the testsuite name for run
    '''
    suite = unittest.TestSuite()
    _TESTCLASS = type(name, (GFXTestSuite,), {})
    suite.addTest(_TESTCLASS(classname))
    return suite


def get_latest_gfxrfile(folderpath, filename):
    '''
    GFXRec allows multiple trace files with same name co-exist as it auto append timestamp in the
    generated trace filename during capture
    For playback, only retrive the latest trace file created during capture
    '''
    gfxrfile = ""
    for file in os.listdir(folderpath):
        if file.endswith(".gfxr") and filename in file:
            if gfxrfile != "":
                # only get the latest trace file
                timestamp1 = os.path.getmtime(os.path.join(folderpath, file))
                timestamp2 = os.path.getmtime(
                    os.path.join(folderpath, gfxrfile))
                if timestamp1 > timestamp2:
                    gfxrfile = file
            else:
                gfxrfile = file
    return os.path.join(folderpath, gfxrfile)


def backup_screenshot_for_compare(foldername):
    '''
    backup screenshot from 1st run for comparison
    '''
    if not os.path.exists(foldername):
        os.mkdir(foldername)
    for file in os.listdir(os.getcwd()):
        if file.endswith('.ppm'):
            shutil.move(os.path.join(os.getcwd(), file),
                        os.path.join(foldername, file))


def remove_screenshots(foldername):
    '''
    remove screenshots after comparison
    '''
    for file in os.listdir(foldername):
        if file.endswith('.ppm'):
            os.remove(os.path.join(foldername, file))


def is_local_newer(localpath, remotepath):
    '''
    compare the modified date of the remote file with the created date of
    the local file. Return True if the local file is newer.
    '''
    if(zipfile.is_zipfile(remotepath)):
        zfile = zipfile.ZipFile(remotepath)
        filename =""
        for info in zfile.infolist():
            filename = info.filename
            remotedate = datetime.datetime(*info.date_time).timestamp()
        if filename!="":
            localpath = os.path.join(localpath, filename)
        if os.path.exists(localpath):
            localdate = os.path.getctime(localpath)
        else:
            #local does not have the golden trace
            #so return False to enable sync
            return False
    else:
        remotedate = os.path.getmtime(remotepath)
        localdate = os.path.getctime(localpath)

    print("Remote modified:", time.ctime(remotedate))
    print("Local created:", time.ctime(localdate))
    print("")
    return remotedate < localdate


class GFXTestSuite(unittest.TestCase):
    def test_capture(self):
        '''
        recapture from golden trace test
        '''
        try:
            # start app for test
            command = ''
            if platform.system().lower() == "windows":
                app = '{0}\\{1}.exe'.format(local_dst_path, exe)
                command = 'set VK_LAYER_PATH={0};%VULKAN_SDK%\\Bin&&\
                    set VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_SCREENSHOT_FRAMES={1}&&\
                    set GFXRECON_CAPTURE_FILE={2}\\{3}.gfxr&&\
                    set GFXRECON_LOG_LEVEL=warning&&\
                    start {4}'.format(args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe, app)
            elif platform.system().lower() == "linux":
                app = '{0}/{1}'.format(local_dst_path, exe)
                command = 'export VK_LAYER_PATH={0};$VULKAN_SDK/etc/vulkan/explicit_layer.d; export VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_SCREENSHOT_FRAMES={1}; export GFXRECON_CAPTURE_FILE={2}/{3}.gfxr; export GFXRECON_LOG_LEVEL=warning; {4} & (sleep 3 && sudo killall -9 {4})'.format(
                    args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe, app)

            print(command)
            ret = os.system(command)
            if platform.system().lower() == "windows":
                if not ret:
                    # checking for sufficient # screenshot ppm files exist before quit apps
                    ppmfiles = []
                    start = time.time()
                    while (len(ppmfiles) < SCREENSHOT_COUNT):
                        ppmfiles = []
                        ppmfiles += [each for each in os.listdir(
                            os.getcwd()) if each.endswith('.ppm')]
                        if(time.time()-start > 120 and len(ppmfiles) < 1):
                            if platform.system().lower() == "windows":
                                result = os.system(
                                    'taskkill /IM ' + exe + '.exe /f')
                            elif platform.system().lower() == "linux":
                                result = os.system('sudo killall -9 ' + app)
                            raise Exception(
                                'Time Out in capture. Insufficient screenshot generated from capture.')
                    time.sleep(1)
                    if platform.system().lower() == "windows":
                        result = os.system('taskkill /IM ' + exe + '.exe /f')
                    elif platform.system().lower() == "linux":
                        result = os.system('sudo killall -9 ' + app)
                    self.assertEqual(result, 0)

        except Exception as error:
            print('Error', *(error.args))
            sys.exit(1)

    def test_recapture(self):
        '''
        Recapture test
        '''
        try:
            # start golden trace playaback for recapture test
            command = ''
            tracefile = get_latest_gfxrfile(local_dst_path, exe)
            if platform.system().lower() == "windows":
                command = 'set VK_LAYER_PATH={0};%VULKAN_SDK%\\Bin&&\
                    set VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_SCREENSHOT_FRAMES={1}&&\
                    set GFXRECON_CAPTURE_FILE={2}\\{3}.gfxr&&\
                    set GFXRECON_LOG_LEVEL=warning&&\
                    {4}\\gfxrecon-replay.exe {5}'.format(args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe+"_recap", args.binary_path, tracefile)
            elif platform.system().lower() == "linux":
                command = 'export VK_LAYER_PATH={0};$VULKAN_SDK/etc/vulkan/explicit_layer.d; export VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_SCREENSHOT_FRAMES={1}; export GFXRECON_CAPTURE_FILE={2}/{3}.gfxr; export GFXRECON_LOG_LEVEL=warning; {4}/gfxrecon-replay {5}'.format(
                    args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe+"_recap", args.binary_path, tracefile)
            print(command)
            ret = os.system(command)
        except Exception as error:
            print('Error', *(error.args))
            sys.exit(1)

    def test_recapture_trim(self):
        '''
        Recapture trim test
        '''
        try:
            # start golden trace playaback for recapture trim test
            command = ''
            tracefile = get_latest_gfxrfile(local_dst_path, exe)
            if platform.system().lower() == "windows":
                command = 'set VK_LAYER_PATH={0};%VULKAN_SDK%\\Bin&&\
                    set VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot;&&\
                    set VK_SCREENSHOT_FRAMES={1}&&\
                    set GFXRECON_CAPTURE_FILE={2}\\{3}.gfxr&&\
                    set GFXRECON_LOG_LEVEL=warning&&\
                    set GFXRECON_CAPTURE_FRAMES={4}&&\
                    {5}\\gfxrecon-replay.exe {6}'.format(args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe+"_recaptrim", TRIM_RANGE, args.binary_path, tracefile)
            elif platform.system().lower() == "linux":
                command = 'export VK_LAYER_PATH={0};$VULKAN_SDK/etc/vulkan/explicit_layer.d; export VK_DEVICE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct;VK_LAYER_LUNARG_screenshot; export VK_SCREENSHOT_FRAMES={1}; export GFXRECON_CAPTURE_FILE={2}/{3}.gfxr; export GFXRECON_LOG_LEVEL=warning; export GFXRECON_CAPTURE_FRAMES={4}&&\
                    {5}/gfxrecon-replay {6}'.format(args.layer_path, screenshot_frames, TEST_RESULT_FOLDER, exe+"_recaptrim", TRIM_RANGE, args.binary_path, tracefile)
            print(command)
            ret = os.system(command)
        except Exception as error:
            print('Error', *(error.args))
            sys.exit(1)

    def test_playback(self):
        '''
        Playback trace file test
        '''
        try:
            if gfxrfile == "":
                raise Exception(
                    "Failed to retrieve tracefile for playback test.")

            if platform.system().lower() == "windows":
                command = 'set VK_LAYER_PATH={0};%VULKAN_SDK%\\Bin&&\
                    set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_screenshot;&&\
                    set VK_SCREENSHOT_FRAMES={1}&&\
                    {2}\\gfxrecon-replay.exe {3}'.format(args.layer_path, screenshot_frames, args.binary_path, gfxrfile)
                print(command)
            elif platform.system().lower() == "linux":
                command = 'export VK_LAYER_PATH={0};$VULKAN_SDK/etc/vulkan/explicit_layer.d; export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_screenshot; export VK_SCREENSHOT_FRAMES={1}; {2}/gfxrecon-replay {3}'.format(
                    args.layer_path, screenshot_frames, args.binary_path, gfxrfile)

            output = os.popen(command).read()
            print("-----playback output-----")
            print(output)
            if not("frames," in output):
                raise Exception("0 frame during playback.")

        except Exception as error:
            print('Error', *(error.args))
            sys.exit(1)

    def test_compare_screenshots(self):
        '''
        Image compare between capture and playback screenshots
        '''
        try:
            for file in os.listdir(os.getcwd()):
                if file.endswith('.ppm'):
                    playback_screenshot = Image.open(file)
                    capture_screenshot = Image.open(
                        os.path.join(backup_ppm_folder, file))
                    assert playback_screenshot.size == capture_screenshot.size, "Different sizes between screenshots."

                    screenshots = zip(
                        playback_screenshot.getdata(), capture_screenshot.getdata())
                    diff = sum(abs(c1-c2)
                               for p1, p2 in screenshots for c1, c2 in zip(p1, p2))

                    ncomponents = playback_screenshot.size[0] * \
                        playback_screenshot.size[1] * 3
                    diff_percentage = float((diff / 255.0 * 100) / ncomponents)
                    print("Screenshot Difference (percentage):", diff_percentage)
                    if diff_percentage > TOLERANCE:
                        print("Failed Image Comparison Test.")
                        self.assertTrue(False)
        except Exception as error:
            print('Error', *(error.args))
            sys.exit(1)


# Main entry point
if '__main__' == __name__:
    try:
        args = parse_args()

        # check for valid binary, layer and test apps paths
        if not os.path.exists(args.binary_path):
            raise Exception("Binary path not found.")
        if not os.path.exists(args.layer_path):
            raise Exception("Layer path not found.")
        if args.skip_sync_trace:
            if not os.path.exists(args.dst_path):
                raise Exception("Local test apps/traces dest path not found.")

        # detect system GPU (now only for Windows)
        if platform.system().lower() == "windows":
            gpu = get_system_gpu()

        # clean up the old ppm files before start tests
        for filename in os.listdir(os.getcwd()):
            if filename.endswith('.ppm'):
                os.remove(os.path.join(os.getcwd(), filename))

        # sync down golden trace files and app from test path (server path)
        if not args.skip_sync_trace:
            if (platform.system().lower() == "windows"):
                try:
                    print(
                        "Start syncing down apps/traces from network to local. Please wait...")
                    # create local sync directories to sync down apps or golden traces
                    for srcdir in args.src_path_list:
                        foldername = os.path.basename(srcdir)
                        dstfoldername = os.path.join(args.dst_path, foldername)
                        if not os.path.exists(args.dst_path):
                            os.mkdir(args.dst_path)
                        if not os.path.exists(dstfoldername):
                            os.mkdir(dstfoldername)
                        # for each file in the src path, check if is newer then only sync down to local
                        for filename in os.listdir(srcdir):
                            command = ""
                            if(zipfile.is_zipfile(os.path.join(srcdir, filename))):
                                if not is_local_newer(dstfoldername, os.path.join(srcdir, filename)):
                                    command = ['robocopy', srcdir, dstfoldername, filename]
                                    runcommand = subprocess.run(
                                        command, stdout=subprocess.PIPE, shell=True)
                                    output = runcommand.stdout.decode('utf-8')
                                    print(output)
                            elif os.path.exists(os.path.join(dstfoldername, filename)):
                                if not is_local_newer(os.path.join(dstfoldername, filename), os.path.join(srcdir, filename)):
                                    if os.path.isdir(os.path.join(srcdir, filename)):
                                        command = ['robocopy', '/S', '/E', os.path.join(srcdir, filename), os.path.join(dstfoldername, filename)]
                                    else:
                                        command = ['robocopy', srcdir, dstfoldername, filename]
                                    runcommand = subprocess.run(
                                        command, stdout=subprocess.PIPE, shell=True)
                                    output = runcommand.stdout.decode('utf-8')
                                    print(output)
                            else:
                                if os.path.isdir(os.path.join(srcdir, filename)):
                                    command = ['robocopy', '/S', '/E', os.path.join(srcdir, filename), os.path.join(dstfoldername, filename)]
                                else:
                                    command = ['robocopy', srcdir, dstfoldername, filename]
                                runcommand = subprocess.run(
                                    command, stdout=subprocess.PIPE, shell=True)
                                output = runcommand.stdout.decode('utf-8')
                                print(output)
                        print('Done syncing down apps from network to local test folder.')
                except Exception as e:
                    print(e)
                    sys.exit(1)
            elif (platform.system().lower() == "linux"):
                # create local sync directories to sync down apps or golden traces
                for srcdir in args.src_path_list:
                    foldername = os.path.basename(srcdir)
                    dstfoldername = args.path.join(args.dst_path, foldername)
                    if not os.path.exists(dstfoldername):
                        os.mkdir(dstfoldername)
                    # for each file in the src path, check if is newer then only sync down to local
                    for filename in os.listdir(srcdir):
                        if os.path.exists(os.path.join(dstfoldername, filename)):
                            if not is_local_newer(os.path.join(dstfoldername, filename), os.path.join(srcdir, filename)):
                                command = ['scp', os.path.join(srcdir, filename), os.path.join(dstfoldername, filename)]
                                runcommand = subprocess.run(
                                    command, stdout=subprocess.PIPE, shell=True)
                                output = runcommand.stdout.decode('utf-8')
                                print(output)
                        else:
                            command = ['scp', os.path.join(srcdir, filename), os.path.join(dstfoldername, filename)]
                            runcommand = subprocess.run(
                                command, stdout=subprocess.PIPE, shell=True)
                            output = runcommand.stdout.decode('utf-8')
                            print(output)
                    print('Done syncing down apps from network to local test folder.')
            for traceappfolder in os.listdir(args.dst_path):
                for traceappfile in os.listdir(os.path.join(args.dst_path, traceappfolder)):
                    if zipfile.is_zipfile(os.path.join(args.dst_path, traceappfolder, traceappfile)):
                        print("Unzipping test folder: " + str(traceappfile) + ". Please wait...")
                        with zipfile.ZipFile(os.path.join(args.dst_path, traceappfolder, traceappfile), 'r') as zip_ref:
                            zip_ref.extractall(os.path.join(args.dst_path, traceappfolder))
                        print("Done unzipping test folder.")
                        os.remove(os.path.join(args.dst_path, traceappfolder, traceappfile))

        # if test folder does not exists, create a TestResult directory
        if not os.path.exists(TEST_RESULT_FOLDER):
            os.mkdir(TEST_RESULT_FOLDER)
        # detect if it is sashasample, if yes then override the test app path
        # this is because sashasample has asset data folder relative to app
        # executable
        for folder in os.listdir(args.dst_path):
            if os.path.exists(os.path.join(args.dst_path, folder, "sashasample.dat")):
                local_dst_path = os.path.join(args.dst_path, folder, "bin")
                if not os.path.exists(os.path.join("TestApp","data")):
                    os.mkdir(os.path.join("TestApp","data"))
                    shutil.move(os.path.join(args.dst_path, folder,"data"),os.path.join("TestApp","data"))
            else:
                local_dst_path = os.path.join(args.dst_path, folder)
            # running the test suite for each Vulkan test apps
            for file in os.listdir(local_dst_path):
                test_file_path = os.path.join(local_dst_path, file)
                # running tests (capture, playback and snapshots compare) on executable app files
                is_exe = True

                # os.access does not works well with window, thus add .exe check
                if platform.system().lower() == "windows":
                    is_exe = file.endswith(".exe")

                if not args.skip_test_app and is_exe == True and not os.path.isdir(test_file_path):
                    time.sleep(1)
                    exe = file.split('.')[0]
                    screenshot_frames = APPS_SCREENSHOT_FRAMES
                    print("\n")
                    print(''.join(['=========================== ', 'TEST ',
                                exe, ' ===========================']))
                    suite = get_test(exe+"Capture", "test_capture")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    backup_ppm_folder = os.path.join(
                        os.path.abspath(TEST_RESULT_FOLDER), "LastCapture")
                    backup_screenshot_for_compare(backup_ppm_folder)
                    gfxrfile = get_latest_gfxrfile(TEST_RESULT_FOLDER, exe)
                    suite = get_test(exe+"Playback", "test_playback")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    if platform.system().lower() == "windows":
                        suite = get_test(exe+"ImgCompare",
                                        "test_compare_screenshots")
                        test_result = xmlrunner.XMLTestRunner(
                            verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    remove_screenshots(os.getcwd())
                    remove_screenshots(backup_ppm_folder)

                # running tests
                # (playback gold, recapture, playback_recap, recap_trim, playback_recap_trim, snaoshot_compare)
                # on golden GFXRec trace files
                if not args.skip_test_game and test_file_path.endswith('.gfxr'):
                    if not gpu in test_file_path:
                        print(''.join(["WARNING: Skipping test on ", file,
                                    ". Golden Trace file path name should contain GPU name \"", gpu, "\"."]))
                        continue
                    if gpu == "UNKNOWN":
                        raise Exception("Failed to get system GPU name.")
                    exe = file.split('.')[0]
                    screenshot_frames = RECAP_SCREENSHOT_FRAMES
                    print("\n")
                    print(''.join(['=========================== ', 'TEST ',
                                exe, ' ===========================']))
                    gfxrfile = get_latest_gfxrfile(local_dst_path, exe)
                    suite = get_test(exe+"PlaybackGold", "test_playback")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    remove_screenshots(os.getcwd())
                    suite = get_test(exe+"Recapture", "test_recapture")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    backup_ppm_folder = os.path.join(
                        os.path.abspath(TEST_RESULT_FOLDER), "LastCapture")
                    backup_screenshot_for_compare(backup_ppm_folder)
                    exe = exe+"_recap"
                    gfxrfile = get_latest_gfxrfile(TEST_RESULT_FOLDER, exe)
                    suite = get_test(exe+"PlaybackRecap", "test_playback")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    exe = file.split('.')[0]
                    suite = get_test(exe+"ImgCompare", "test_compare_screenshots")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    remove_screenshots(os.getcwd())
                    remove_screenshots(backup_ppm_folder)
                    suite = get_test(exe+"RecaptureTrim", "test_recapture_trim")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    backup_ppm_folder = os.path.join(
                        os.path.abspath(TEST_RESULT_FOLDER), "LastCapture")
                    backup_screenshot_for_compare(backup_ppm_folder)
                    exe = exe+"_recaptrim"
                    screenshot_frames = TRIM_PLAYBACK_SCREENSHOT
                    gfxrfile = get_latest_gfxrfile(TEST_RESULT_FOLDER, exe)
                    suite = get_test(exe+"PlaybackRecapTrim", "test_playback")
                    test_result = xmlrunner.XMLTestRunner(
                        verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    # TODO: image comparison for trim is disabled for now, due to the test limitation
                    # rename the playback screenschot ppm files accordingly for image comparison
                    #trim_recap_files = RECAP_SCREENSHOT_FRAMES.split(',')
                    #trim_playback_files = TRIM_PLAYBACK_SCREENSHOT.split(',')
                    # for  i in range(len(trim_playback_files)):
                    #    if os.path.exists(trim_playback_files[i]+".ppm"):
                    #        os.rename(trim_playback_files[i]+".ppm", trim_recap_files[i]+".ppm")
                    #exe = file.split('.')[0]
                    #suite = get_test(exe+"ImgCompare", "test_compare_screenshots")
                    #test_result = xmlrunner.XMLTestRunner(verbosity=2, output=TEST_RESULT_FOLDER).run(suite)
                    remove_screenshots(os.getcwd())
                    remove_screenshots(backup_ppm_folder)

    except Exception as error:
        print('Error', *(error.args))
        sys.exit(1)
    sys.exit(0)
