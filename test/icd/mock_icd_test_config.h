/*
** Copyright (c) 2015-2018, 2023 The Khronos Group Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#pragma once
namespace vkmock
{

struct TestConfig
{
    uint32_t device_api_version_override = 0;
    void*    map_addr_override           = nullptr;
};

} // namespace vkmock

typedef vkmock::TestConfig*(VKAPI_PTR* PFN_mockICD_getTestConfig)();
