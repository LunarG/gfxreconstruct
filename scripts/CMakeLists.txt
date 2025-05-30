###############################################################################
# Copyright (c) 2023 LunarG, Inc.
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
# Description: CMake script for scripts target
###############################################################################

if (D3D12_SUPPORT)

    add_custom_target(gfxrecon-optimize-renamed.py ALL)

    add_custom_command(TARGET gfxrecon-optimize-renamed.py
                       DEPENDS ${CMAKE_SOURCE_SOURCE_DIR}/gfxrecon-optimize-renamed.py
                       COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gfxrecon-optimize-renamed.py ${CMAKE_CURRENT_BINARY_DIR}/gfxrecon-optimize-renamed.py)

    install(FILES gfxrecon-optimize-renamed.py DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS
            OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

    add_custom_target(gfxrecon-replay-renamed.py ALL)

    add_custom_command(TARGET gfxrecon-replay-renamed.py
                       DEPENDS ${CMAKE_SOURCE_SOURCE_DIR}/gfxrecon-replay-renamed.py
                       COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gfxrecon-replay-renamed.py ${CMAKE_CURRENT_BINARY_DIR}/gfxrecon-replay-renamed.py)

    install(FILES gfxrecon-replay-renamed.py DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS
            OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)

endif()
