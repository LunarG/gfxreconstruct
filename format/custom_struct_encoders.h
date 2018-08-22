/*
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

#ifndef BRIMSTONE_CUSTOM_STRUCT_ENCODERS_H
#define BRIMSTONE_CUSTOM_STRUCT_ENCODERS_H

#include "format/parameter_encoder.h"
#include "format/platform_types.h"
#include "util/defines.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

size_t encode_struct(format::ParameterEncoder* encoder, const ACL& value);
size_t encode_struct(format::ParameterEncoder* encoder, const SECURITY_DESCRIPTOR& value);
size_t encode_struct(format::ParameterEncoder* encoder, const SECURITY_ATTRIBUTES& value);

BRIMSTONE_END_NAMESPACE(brimstone)

#endif // BRIMSTONE_CUSTOM_STRUCT_ENCODERS_H
