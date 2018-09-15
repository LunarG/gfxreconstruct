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

#include <cstring>
#include <sstream>

#include "util/argument_parser.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)
BRIMSTONE_BEGIN_NAMESPACE(util)

ArgumentParser::ArgumentParser(int32_t            argc,
                               const char** const argv,
                               const std::string& options,
                               const std::string& arguments,
                               const int32_t      expected_non_opt_args)
{
    if (argc > 1 && nullptr != argv)
    {
        std::vector<std::string> valid_options;
        std::string              sub_string;
        std::string              sub_string2;

        is_invalid_ = false;

        uint32_t option_index = 0;
        if (options.size() > 0)
        {
            std::stringstream option_strstr(options);
            while (option_strstr.good())
            {
                std::getline(option_strstr, sub_string, ',');

                // If a pipe '|' exists, we have multiple command-line
                // values that can set the same option.  So, set all
                // of the values to point to the same option flag.
                if (sub_string.find('|') != std::string::npos)
                {
                    std::stringstream option_strstr_2(sub_string);
                    while (option_strstr_2.good())
                    {
                        std::getline(option_strstr_2, sub_string2, '|');
                        options_indices_[sub_string2] = option_index;
                    }
                }
                // Otherwise, we only have one option value for the flag
                else
                {
                    options_indices_[sub_string] = option_index;
                }
                option_index++;
            }
        }
        options_present_.resize(option_index);

        uint32_t argument_index = 0;
        if (arguments.size() > 0)
        {
            std::stringstream arguments_strstr(arguments);
            while (arguments_strstr.good())
            {
                std::getline(arguments_strstr, sub_string, ',');

                // If a pipe '|' exists, we have multiple command-line
                // values that can set the same argument.  So, set all
                // of the values to point to the same argument.
                if (sub_string.find('|') != std::string::npos)
                {
                    std::stringstream arguments_strstr_2(sub_string);
                    while (arguments_strstr_2.good())
                    {
                        std::getline(arguments_strstr_2, sub_string2, '|');
                        arguments_indices_[sub_string2] = argument_index;
                    }
                }
                // Otherwise, we only have one argument value pair
                else
                {
                    arguments_indices_[sub_string] = argument_index;
                }
                argument_index++;
            }
        }
        argument_values_.resize(argument_index);

        for (int32_t cur_arg = 1; cur_arg < argc; ++cur_arg)
        {
            bool is_option   = false;
            bool is_argument = false;

            // Strip off any quotes surrounding the whole string
            std::string current_argument = argv[cur_arg];
            if (current_argument[0] == '\"')
            {
                current_argument.erase(0, 1);
            }
            if (current_argument[current_argument.size() - 1] == '\"')
            {
                current_argument.erase(current_argument.size() - 1);
            }

            // Optional option/argument
            if (current_argument[0] == '-')
            {
                for (const auto& cur_option : options_indices_)
                {
                    if (cur_option.first == current_argument)
                    {
                        options_present_[cur_option.second] = true;
                        is_option                           = true;
                        break;
                    }
                }
                if (!is_option)
                {
                    for (const auto& cur_argument : arguments_indices_)
                    {
                        if (cur_argument.first == current_argument)
                        {
                            // Make sure we have room for the argument's value.
                            if (cur_arg == argc - 1)
                            {
                                // We're on the last argument, so add this to the invalid list.
                                invalid_values_present_.push_back(current_argument);
                                is_invalid_ = true;
                            }
                            else
                            {
                                // Get the next value and strip off any quotes surrounding the whole string
                                std::string argument_value = argv[++cur_arg];
                                if (argument_value[0] == '\"')
                                {
                                    argument_value.erase(0, 1);
                                }
                                if (current_argument[argument_value.size() - 1] == '\"')
                                {
                                    argument_value.erase(argument_value.size() - 1);
                                }
                                argument_values_[cur_argument.second] = argument_value;
                            }
                            is_argument = true;
                            break;
                        }
                    }
                }
                if (!is_option && !is_argument)
                {
                    // Past the valid number of non-optional arguments, this must
                    // be an invalid value.
                    invalid_values_present_.push_back(current_argument);
                    is_invalid_ = true;
                    printf("ERROR: Invalid command-line setting \'%s\'\n", current_argument.c_str());
                }
            }
            else
            {
                if (non_option_arguments_present_.size() < static_cast<size_t>(expected_non_opt_args))
                {
                    non_option_arguments_present_.push_back(current_argument);
                }
                else
                {
                    // Past the valid number of non-optional arguments, this must
                    // be an invalid value.
                    invalid_values_present_.push_back(current_argument);
                    is_invalid_ = true;
                }
            }
        }
    }

    if (expected_non_opt_args > (argc - 1))
    {
        // Expected some number of arguments and didn't get any
        is_invalid_ = true;
        printf("Error: Different number of non-optional arguments.\n");
        printf("Error:     Requires %d options, but %d provided\n", expected_non_opt_args, (argc - 1));
    }
}

bool ArgumentParser::IsOptionSet(const std::string& option)
{
    auto ret_iterator = options_indices_.find(option);

    if (ret_iterator != options_indices_.end())
    {
        return options_present_[ret_iterator->second];
    }
    return false;
}

const std::string& ArgumentParser::GetArgumentValue(const std::string& argument)
{
    static const std::string empty_string("");
    auto                     ret_iterator = arguments_indices_.find(argument);

    if (ret_iterator != arguments_indices_.end() && argument_values_[ret_iterator->second].size() > 0)
    {
        return argument_values_[ret_iterator->second];
    }
    return empty_string;
}

BRIMSTONE_END_NAMESPACE(util)
BRIMSTONE_END_NAMESPACE(brimstone)
