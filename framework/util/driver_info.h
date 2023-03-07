/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_UTIL_DRIVER_INFO_H
#define GFXRECON_UTIL_DRIVER_INFO_H

#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"
#include <format/api_call_id.h>

#include <unordered_map>
#include <string>
#include <fstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(driverinfo)

const char amd_d3d12_driver_64[] = "amdxc64.dll";
const char amd_d3d12_driver_32[] = "amdxc32.dll";

std::string FindLoadedDriverModule(const std::vector<std::string>& known_user_mode_drivers);

bool AMD_GetAGSInfo(std::string& driver_info);

bool AMD_GetUMDInfo(const std::string& active_driver_path, std::string& driver_info);

bool AMD_IsDriverActive(const std::string& umd_path);

#if defined(WIN32)
bool GetDriverInfo(std::string& driver_info, format::ApiFamilyId api_family, std::vector<LUID>& adapter_luids);

bool RegistryDxDriverVersion(std::string& driver_info, const std::vector<LUID>& adapter_luids);

int GetRegSubkeys(HKEY& dx_key_handle, DWORD& num_of_adapters, DWORD& sub_key_max_length);

LSTATUS GetRegData(HKEY               dx_key_handle,
                   DWORD              num_of_adapters,
                   DWORD              sub_key_max_length,
                   std::string&       driver_info,
                   std::vector<LUID>& adapter_luids);
#endif

std::string ConvertDataToVersionNumber(uint64_t data);

GFXRECON_END_NAMESPACE(driverinfo)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_DRIVER_INFO_H
