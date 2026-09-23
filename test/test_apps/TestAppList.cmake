###############################################################################
# Copyright (c) 2026 LunarG, Inc.
# All rights reserved
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
#
# Author: LunarG Team
# Description: The one list of test apps
###############################################################################

# Every other list of test apps derives from this one: the directories that CMake adds, the
# libraries that the launcher links, the names that the launcher accepts, and the apps that the
# reruns in test/test_cases/reruns.cpp cover. To add an app, create its directory and add one
# entry here.
#
# Each entry is "<name>:<case>".
#
# <name> is the directory under test/test_apps, the argument that the launcher accepts, and the
# suffix of the library target gfxrecon-testapp-<name>. The app header is <ident>_app.h and the
# app class is gfxrecon::test_app::<ident>::App, where <ident> is <name> with "-" replaced by "_".
#
# <case> says which cases the harness runs for the app without a case file of its own:
#   KNOWN_GOOD   The serialized rerun compares against test/known_good/<name>.gfxr, and the
#                capture-disabled rerun runs. The app also has a verify_gfxr case file.
#   REPLAY_ONLY  The app has a capture_and_replay case and no known-good file. Only the
#                capture-disabled rerun runs.
#   NONE         No rerun. The app has a case of its own that needs more than one process, or it
#                has a disabled case.
#   CUSTOM       The app is built, linked and its header included, but it is left out of the
#                X-macro lists. Its launcher names and constructor calls are written by hand in
#                test_launcher.cpp, for an app that runs under several names or takes arguments.
#
# Keep at least one KNOWN_GOOD and one REPLAY_ONLY entry, because reruns.cpp turns each list into
# an array, and an array cannot be empty.
set(GFXRECON_TEST_APP_ENTRIES
    "acquired-image:KNOWN_GOOD"
    "ahb:KNOWN_GOOD"
    "debug-utils:KNOWN_GOOD"
    "deep-pnext-chain:KNOWN_GOOD"
    "host-image-copy:NONE"
    "isolate-render-passes:REPLAY_ONLY"
    "multisample-depth:KNOWN_GOOD"
    "pipeline-binaries:KNOWN_GOOD"
    "screenshot-frame-boundaries:CUSTOM"
    "serialize-compute-and-transfer:REPLAY_ONLY"
    "shader-objects:KNOWN_GOOD"
    "sparse-resources:KNOWN_GOOD"
    "triangle:KNOWN_GOOD"
    "triangle-extra-device:KNOWN_GOOD")

# set-environment reads desktop environment variables.
if (NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    list(APPEND GFXRECON_TEST_APP_ENTRIES "set-environment:KNOWN_GOOD")
endif ()

# These apps need POSIX file descriptors, VK_KHR_present_wait on a desktop compositor, or a
# hotkey. The two external memory apps form one two-process case of their own.
if (CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU|Android")
    list(APPEND GFXRECON_TEST_APP_ENTRIES
        "external-memory-fd-export:NONE"
        "external-memory-fd-import:NONE"
        "wait-for-present:KNOWN_GOOD"
        "trigger-trimming:KNOWN_GOOD")
endif ()

# Derived lists, available to every file that includes this one.
#   GFXRECON_TEST_APP_NAMES       The names, for add_subdirectory.
#   GFXRECON_TEST_APP_LIBRARIES   gfxrecon-testapp-<name> for each, for the launcher.
set(GFXRECON_TEST_APP_NAMES "")
set(GFXRECON_TEST_APP_LIBRARIES "")
set(GFXRECON_TEST_APP_LIST_TEMPLATE_DIR ${CMAKE_CURRENT_LIST_DIR})
foreach (entry IN LISTS GFXRECON_TEST_APP_ENTRIES)
    string(REPLACE ":" ";" parts "${entry}")
    list(GET parts 0 name)
    list(APPEND GFXRECON_TEST_APP_NAMES ${name})
    list(APPEND GFXRECON_TEST_APP_LIBRARIES gfxrecon-testapp-${name})
endforeach ()

# Writes test_app_list.h and test_app_includes.h into OUTPUT_DIR. The first holds one X-macro
# list per case kind, the second the #include of every app header. The launcher includes both.
# The test runner includes only the list.
function(gfxrecon_generate_test_app_list OUTPUT_DIR)
    set(all "")
    set(known_good "")
    set(replay_only "")
    set(includes "")
    foreach (entry IN LISTS GFXRECON_TEST_APP_ENTRIES)
        string(REPLACE ":" ";" parts "${entry}")
        list(GET parts 0 name)
        list(GET parts 1 kind)
        string(REPLACE "-" "_" ident "${name}")
        string(APPEND includes "#include <${ident}_app.h>\n")
        if (kind STREQUAL "CUSTOM")
            continue()
        endif ()
        set(line "    X(${ident}, \"${name}\") \\\n")
        string(APPEND all "${line}")
        if (kind STREQUAL "KNOWN_GOOD")
            string(APPEND known_good "${line}")
        elseif (kind STREQUAL "REPLAY_ONLY")
            string(APPEND replay_only "${line}")
        elseif (NOT kind STREQUAL "NONE")
            message(FATAL_ERROR "Test app '${name}' has an unknown case kind '${kind}'.")
        endif ()
    endforeach ()
    set(GFXRECON_TEST_APP_LIST_ALL "${all}")
    set(GFXRECON_TEST_APP_LIST_KNOWN_GOOD "${known_good}")
    set(GFXRECON_TEST_APP_LIST_REPLAY_ONLY "${replay_only}")
    set(GFXRECON_TEST_APP_INCLUDES "${includes}")
    configure_file(${GFXRECON_TEST_APP_LIST_TEMPLATE_DIR}/test_app_list.h.in ${OUTPUT_DIR}/test_app_list.h @ONLY)
    configure_file(${GFXRECON_TEST_APP_LIST_TEMPLATE_DIR}/test_app_includes.h.in ${OUTPUT_DIR}/test_app_includes.h @ONLY)
endfunction()
