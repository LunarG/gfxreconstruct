/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_UTIL_SETTINGS_LOADER_H
#define GFXRECON_UTIL_SETTINGS_LOADER_H

#include "util/defines.h"

#include <string>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(settings)

std::string RemoveQuotes(const std::string& source);

std::string FindLayerSettingsFile();

// Returns 0 on success, value of errno on failure.
int32_t LoadLayerSettingsFile(const std::string&                            filename,
                              const std::string&                            filter,
                              std::unordered_map<std::string, std::string>* settings);

GFXRECON_END_NAMESPACE(settings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_SETTINGS_LOADER_H
