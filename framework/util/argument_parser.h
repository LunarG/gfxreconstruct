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

#ifndef GFXRECON_UTIL_ARGUMENT_PARSER_H
#define GFXRECON_UTIL_ARGUMENT_PARSER_H

#include "util/defines.h"

#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class ArgumentParser
{
  public:
    // Options and arguments can be specified in the following way:
    // "-c,-b|--binary" where the list is comma-delimited.  If an option/argument
    // can be defined using two different string values (such as "-b" and "--binary")
    // they are further delimited by the pipe "|" symbol.

    ArgumentParser(int32_t argc, const char** const argv, const std::string& options, const std::string& arguments);
    ArgumentParser(bool first_is_exe_name, const char* args, const std::string& options, const std::string& arguments);
    ~ArgumentParser() {}

    bool                            IsInvalid() const { return is_invalid_; }
    const std::vector<std::string>& GetInvalidArgumentOrOptions() const { return invalid_values_present_; };
    bool                            IsOptionSet(const std::string& option) const;
    const std::string&              GetArgumentValue(const std::string& argument) const;
    size_t                          GetPositionalArgumentsCount() const { return positional_arguments_present_.size(); }
    const std::vector<std::string>& GetPositionalArguments() const { return positional_arguments_present_; }

  private:
    void Init(std::vector<std::string> command_line_args, const std::string& options, const std::string& arguments);

    bool                     is_invalid_;
    std::vector<std::string> invalid_values_present_;

    // For arguments and options, use a map to the index in the vector.  This allows
    // us to have multiple keys pointing at the same value.  For example, if the keys
    // "-c", "--count", "--my_count" are all for the same option, then you can set that
    // option by using any one of those, and you can query that same option later by using
    // any of those values, including one of the values that wasn't used to set it.
    std::unordered_map<std::string, uint32_t> options_indices_;
    std::vector<bool>                         options_present_;
    std::unordered_map<std::string, uint32_t> arguments_indices_;
    std::vector<std::string>                  argument_values_;
    std::vector<std::string>                  positional_arguments_present_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_ARGUMENT_PARSER_H
