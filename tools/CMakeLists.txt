###############################################################################
# Copyright (c) 2018-2026 LunarG, Inc.
# Copyright (c) 2018-2026 Valve Corporation.
# Copyright (c) 2020-2022 Advanced Micro Devices, Inc.
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
###############################################################################

set(GFXRECON_WIN_MANIFEST "${CMAKE_CURRENT_SOURCE_DIR}/windows-app.manifest")

add_subdirectory(replay)
add_subdirectory(compress)
add_subdirectory(info)
add_subdirectory(file_version_patch)

if(GFXRECON_TOCPP_SUPPORT)
add_subdirectory(tocpp)
endif()

add_subdirectory(extract)
add_subdirectory(optimize)
add_subdirectory(capture-vulkan)
add_subdirectory(capture)
add_subdirectory(gfxrecon)
add_subdirectory(convert)

if(MSVC)
    add_subdirectory(launcher)
endif()
