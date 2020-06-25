###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2020 Advanced Micro Devices, Inc.
# All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake script for framework util target
###############################################################################

add_executable(gfxrecon-compress "")

target_sources(gfxrecon-compress
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_include_directories(gfxrecon-compress PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-compress gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-compress)

install(TARGETS gfxrecon-compress RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
