//
// Copyright (c) 2021 Samsung
// Copyright (c) 2023 Google
// Copyright (c) 2024 LunarG, Inc
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GFXRECON_DECODE_VULKAN_CPP_LOADER_GENERATOR_H
#define GFXRECON_DECODE_VULKAN_CPP_LOADER_GENERATOR_H

#include "util/defines.h"
#include "decode/vulkan_cpp_utilities.h"

#include <set>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanCppLoaderGenerator
{
  public:
    VulkanCppLoaderGenerator();

    ~VulkanCppLoaderGenerator();

    void AddMethodName(const std::string method_name);
    void WriteOutLoaderGenerator(const std::string& outDir, const GfxToCppPlatform& platform);

  private:
    std::set<std::string> vulkan_methods_;

    void WriteOutLoadFunctions(FILE* file);
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_LOADER_GENERATOR_H
