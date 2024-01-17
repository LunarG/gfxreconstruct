/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/argument_parser.h"

#include "util/logging.h"

#include <cinttypes>
#include <cstring>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

ArgumentParser::ArgumentParser(int32_t            argc,
                               const char** const argv,
                               const std::string& options,
                               const std::string& arguments) :
    is_invalid_(false)
{
    if (argc > 1 && nullptr != argv)
    {
        std::vector<std::string> command_line_args;
        command_line_args.resize(argc - 1);
        for (int32_t cur_arg = 1; cur_arg < argc; ++cur_arg)
        {
            command_line_args[cur_arg - 1] = argv[cur_arg];
        }

        Init(command_line_args, options, arguments);
    }
}

ArgumentParser::ArgumentParser(bool               first_is_exe_name,
                               const char*        args,
                               const std::string& options,
                               const std::string& arguments) :
    is_invalid_(false)
{
    std::vector<std::string> command_line_args;
    size_t                   args_len = strlen(args);

    if (nullptr != args && args_len > 0)
    {
        std::string arg_string = args;
        size_t      last_start = 0;

        // We don't want to save the executable name, just the arguments.
        // So, if the executable name is in the list, skip the first argument.
        bool save_component = !first_is_exe_name;

        for (size_t index = 0; index < arg_string.size(); ++index)
        {
            if (arg_string[index] == '\"')
            {
                size_t end_index = arg_string.find('\"', index + 1);
                if (end_index == std::string::npos)
                {
                    is_invalid_ = true;
                    GFXRECON_LOG_FATAL("Error: ArgumentParser command-line string contains unmatched quotes.", args);
                    return;
                }

                if (save_component)
                {
                    // Pull out just the string, not the quotes
                    command_line_args.push_back(arg_string.substr(index + 1, end_index - index - 1));
                }
                else
                {
                    save_component = true;
                }
                index      = end_index + 1;
                last_start = index + 1;
            }
            else if (arg_string[index] == ' ')
            {
                if (save_component)
                {
                    command_line_args.push_back(arg_string.substr(last_start, index - last_start));
                }
                else
                {
                    save_component = true;
                }
                last_start = index + 1;
            }
        }

        if (save_component)
        {
            command_line_args.push_back(arg_string.substr(last_start, arg_string.size() - last_start));
        }
    }

    if (!command_line_args.empty())
    {
        Init(command_line_args, options, arguments);
    }
}

void ArgumentParser::Init(std::vector<std::string> command_line_args,
                          const std::string&       options,
                          const std::string&       arguments)
{
    std::vector<std::string> valid_options;
    std::string              sub_string;
    std::string              sub_string2;

    uint32_t option_index = 0;
    if (!options.empty())
    {
        std::istringstream option_strstr(options);
        while (option_strstr.good())
        {
            std::getline(option_strstr, sub_string, ',');

            // If a pipe '|' exists, we have multiple command-line
            // values that can set the same option.  So, set all
            // of the values to point to the same option flag.
            if (sub_string.find('|') != std::string::npos)
            {
                std::istringstream option_strstr_2(sub_string);
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
    if (!arguments.empty())
    {
        std::istringstream arguments_strstr(arguments);
        while (arguments_strstr.good())
        {
            std::getline(arguments_strstr, sub_string, ',');

            // If a pipe '|' exists, we have multiple command-line
            // values that can set the same argument.  So, set all
            // of the values to point to the same argument.
            if (sub_string.find('|') != std::string::npos)
            {
                std::istringstream arguments_strstr_2(sub_string);
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
    arguments_present_.resize(argument_index);
    argument_values_.resize(argument_index);

    for (size_t cur_arg = 0; cur_arg < command_line_args.size(); ++cur_arg)
    {
        bool is_option   = false;
        bool is_argument = false;

        // Strip off any quotes surrounding the whole string
        std::string current_argument = command_line_args[cur_arg];
        if (current_argument.front() == '\"')
        {
            current_argument.erase(current_argument.begin());
        }
        if (current_argument.back() == '\"')
        {
            current_argument.pop_back();
        }

        // Optional option/argument
        if (current_argument.front() == '-')
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
                        if (cur_arg == (command_line_args.size() - 1))
                        {
                            // We're on the last argument, so add this to the invalid list.
                            invalid_values_present_.push_back(current_argument);
                            is_invalid_ = true;
                        }
                        else
                        {
                            // Get the next value and strip off any quotes surrounding the whole string
                            std::string argument_value = command_line_args[++cur_arg];
                            if (!argument_value.empty())
                            {
                                if (argument_value.front() == '\"')
                                {
                                    argument_value.erase(argument_value.begin());
                                }
                                if (argument_value.back() == '\"')
                                {
                                    argument_value.pop_back();
                                }
                            }
                            arguments_present_[cur_argument.second] = true;
                            argument_values_[cur_argument.second]   = argument_value;
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
                GFXRECON_LOG_FATAL("Invalid command-line setting \'%s\'", current_argument.c_str());
            }
        }
        else
        {
            positional_arguments_present_.push_back(current_argument);
        }
    }
}

bool ArgumentParser::IsOptionSet(const std::string& option) const
{
    auto ret_iterator = options_indices_.find(option);

    if (ret_iterator != options_indices_.end())
    {
        return options_present_[ret_iterator->second];
    }

    return false;
}

bool ArgumentParser::IsArgumentSet(const std::string& argument) const
{
    auto ret_iterator = arguments_indices_.find(argument);

    if (ret_iterator != arguments_indices_.end())
    {
        return arguments_present_[ret_iterator->second];
    }

    return false;
}

const std::string& ArgumentParser::GetArgumentValue(const std::string& argument) const
{
    static const std::string empty_string;
    auto                     ret_iterator = arguments_indices_.find(argument);

    if (ret_iterator != arguments_indices_.end())
    {
        return argument_values_[ret_iterator->second];
    }

    return empty_string;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
