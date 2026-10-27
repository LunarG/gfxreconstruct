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
###############################################################################

add_library(gfxrecon_replay_event_recorder
    MODULE
        ${CMAKE_CURRENT_LIST_DIR}/replay_event_recorder.cpp)
target_link_libraries(gfxrecon_replay_event_recorder PRIVATE gfxrecon_replay_event_plugin_abi)

if(ANDROID)
    target_link_options(gfxrecon_replay_event_recorder PRIVATE "-Wl,-z,max-page-size=16384")
else()
    common_build_directives(gfxrecon_replay_event_recorder)
endif()

install(TARGETS gfxrecon_replay_event_recorder LIBRARY DESTINATION ${GFXRECON_INSTALL_TESTDIR}
                                               RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
