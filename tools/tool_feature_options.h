/*
** Copyright (c) 2026 LunarG, Inc.
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

// Shared command-line handling for the option entries that Feature modules contribute (see
// util::FeatureOptionDesc in framework/util/feature_base.h). A tool keeps its own kOptions and
// kArguments strings for the entries that all of its Features share. Each Feature returns the
// entries that belong only to that Feature, and these functions put the two sets together.
//
// The steps in a tool main are:
//
//   1. AppendFeatureOptions()     -- before the tool builds the ArgumentParser
//   2. CheckFeatureOptionValues() -- after the tool builds the ArgumentParser
//   3. BuildFeatureSynopsis()     -- in the usage function of the tool, for the "Usage:" line
//   4. PrintFeatureUsage()        -- after the usage function of the tool
//
// An entry exists only when its Feature is built into the tool, so a Feature that the build
// removes also removes its entries from the parser and from the usage text. An entry with an
// empty description is accepted but is not documented, which suits an experimental entry.

#ifndef GFXRECON_TOOL_FEATURE_OPTIONS_H
#define GFXRECON_TOOL_FEATURE_OPTIONS_H

#include "util/argument_parser.h"
#include "util/feature_base.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <vector>

// Splits an ArgumentParser name list into the individual names. The separators are the comma
// between entries and the pipe between the alternative names of one entry.
inline std::vector<std::string> SplitFeatureOptionNames(const std::string& name_list)
{
    std::vector<std::string> names;
    size_t                   start = 0;

    while (start <= name_list.size())
    {
        size_t end = name_list.find_first_of(",|", start);
        if (end == std::string::npos)
        {
            end = name_list.size();
        }

        if (end > start)
        {
            names.push_back(name_list.substr(start, end - start));
        }

        start = end + 1;
    }

    return names;
}

// Joins two alternative names of one entry into the syntax that the ArgumentParser reads.
inline std::string AliasNames(const char* first, const char* second)
{
    return std::string(first) + "|" + second;
}

// Joins the accepted values of one entry into the text that the usage output shows.
inline std::string JoinFeatureOptionValues(const std::vector<std::string>& values)
{
    std::string joined;

    for (const auto& value : values)
    {
        if (!joined.empty())
        {
            joined += ", ";
        }
        joined += value;
    }

    return joined;
}

// Adds the command-line entries of every Feature to the two name lists that the ArgumentParser
// accepts. Call this function after the tool loads its Features and before it builds the parser.
// An entry whose name is already in use is not added, and the tool writes a warning.
template <typename FeatureBaseT>
inline void AppendFeatureOptions(const std::vector<std::unique_ptr<FeatureBaseT>>& features,
                                 std::string&                                      options,
                                 std::string&                                      arguments)
{
    std::set<std::string> used_names;

    for (const auto& name : SplitFeatureOptionNames(options))
    {
        used_names.insert(name);
    }
    for (const auto& name : SplitFeatureOptionNames(arguments))
    {
        used_names.insert(name);
    }

    for (const auto& feature : features)
    {
        for (const auto& desc : feature->GetOptionDescs())
        {
            const std::vector<std::string> desc_names = SplitFeatureOptionNames(desc.trigger_names);
            bool                           in_use     = false;

            for (const auto& name : desc_names)
            {
                if (used_names.find(name) != used_names.end())
                {
                    GFXRECON_LOG_WARNING("The %s feature declares the command-line name %s, which is already in use. "
                                         "This tool ignores the entry.",
                                         feature->Label().c_str(),
                                         name.c_str());
                    in_use = true;
                }
            }

            if (in_use)
            {
                continue;
            }

            used_names.insert(desc_names.begin(), desc_names.end());

            std::string& name_list = desc.has_argument ? arguments : options;

            if (!name_list.empty())
            {
                name_list += ",";
            }
            name_list += desc.trigger_names;
        }
    }
}

// Makes sure that each Feature entry with a closed set of accepted values received one of those
// values. The comparison ignores case, because the Feature functions that read these values use
// util::platform::StringCompareNoCase. A value that is not in the set gets a warning, and the
// Feature then uses the default value for that entry. The tool continues, because an unusable
// value for one entry does not stop the replay of the capture file. An entry with an empty
// accepted_values list accepts any value, and the Feature checks that value itself.
template <typename FeatureBaseT>
inline void CheckFeatureOptionValues(const std::vector<std::unique_ptr<FeatureBaseT>>& features,
                                     const gfxrecon::util::ArgumentParser&             arg_parser)
{
    for (const auto& feature : features)
    {
        for (const auto& desc : feature->GetOptionDescs())
        {
            if (!desc.has_argument || desc.accepted_values.empty())
            {
                continue;
            }

            const std::vector<std::string> desc_names = SplitFeatureOptionNames(desc.trigger_names);
            if (desc_names.empty() || !arg_parser.IsArgumentSet(desc_names.front()))
            {
                continue;
            }

            // All of the alternative names of one entry share a value, so the first name reads it.
            const std::string& value = arg_parser.GetArgumentValue(desc_names.front());

            const bool accepted = std::any_of(
                desc.accepted_values.begin(), desc.accepted_values.end(), [&value](const std::string& accepted_value) {
                    return gfxrecon::util::platform::StringCompareNoCase(accepted_value.c_str(), value.c_str()) == 0;
                });

            if (!accepted)
            {
                GFXRECON_LOG_WARNING("The value \"%s\" is not valid for %s. The accepted values are: %s. "
                                     "This tool uses the default value instead.",
                                     value.c_str(),
                                     desc_names.front().c_str(),
                                     JoinFeatureOptionValues(desc.accepted_values).c_str());
            }
        }
    }
}

// Builds the part of the "Usage:" line that comes from the Features, as a set of bracketed
// fragments such as "[--dxr] [--gpu <index>]". A tool puts this text between its own leading
// options and its positional arguments. An entry with an empty description stays out of the
// synopsis, the same as it stays out of the usage sections.
template <typename FeatureBaseT>
inline std::string BuildFeatureSynopsis(const std::vector<std::unique_ptr<FeatureBaseT>>& features)
{
    std::string synopsis;

    for (const auto& feature : features)
    {
        for (const auto& desc : feature->GetOptionDescs())
        {
            if (desc.description.empty())
            {
                continue;
            }

            const std::vector<std::string> desc_names = SplitFeatureOptionNames(desc.trigger_names);
            const std::string value = (desc.has_argument && !desc.name.empty()) ? (" " + desc.name) : std::string();
            std::string       fragment;

            for (const auto& name : desc_names)
            {
                if (!fragment.empty())
                {
                    fragment += " | ";
                }
                fragment += name + value;
            }

            if (fragment.empty())
            {
                continue;
            }

            if (!synopsis.empty())
            {
                synopsis += " ";
            }
            synopsis += "[" + fragment + "]";
        }
    }

    return synopsis;
}

// Prints one usage section for each Feature that adds command-line entries. Call this function
// directly after the usage function of the tool.
template <typename FeatureBaseT>
inline void PrintFeatureUsage(const std::vector<std::unique_ptr<FeatureBaseT>>& features)
{
    // The continuation prefix and the wrap column keep the sections aligned with the usage text
    // that the tool prints before them.
    const char*  kContinuation = "          \t\t";
    const size_t kWrapColumn   = 56;

    for (const auto& feature : features)
    {
        const std::vector<gfxrecon::util::FeatureOptionDesc> descs = feature->GetOptionDescs();

        const bool has_documented_entry =
            std::any_of(descs.begin(), descs.end(), [](const gfxrecon::util::FeatureOptionDesc& desc) {
                return !desc.description.empty();
            });
        if (!has_documented_entry)
        {
            continue;
        }

        GFXRECON_WRITE_CONSOLE("");
        GFXRECON_WRITE_CONSOLE("%s only:", feature->Label().c_str());
        GFXRECON_WRITE_CONSOLE("**************");

        for (const auto& desc : descs)
        {
            // An entry with no description stays out of the usage text.
            if (desc.description.empty())
            {
                continue;
            }

            // The parser separates alternative names with a pipe. The usage text spaces it out.
            std::string names = desc.trigger_names;
            for (size_t pos = names.find('|'); pos != std::string::npos; pos = names.find('|', pos + 3))
            {
                names.replace(pos, 1, " | ");
            }

            if (desc.has_argument && !desc.name.empty())
            {
                GFXRECON_WRITE_CONSOLE("  %s %s", names.c_str(), desc.name.c_str());
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("  %s", names.c_str());
            }

            for (const auto& line : desc.description)
            {
                GFXRECON_WRITE_CONSOLE("%s%s", kContinuation, line.c_str());
            }
        }
    }
}

#endif // GFXRECON_TOOL_FEATURE_OPTIONS_H
