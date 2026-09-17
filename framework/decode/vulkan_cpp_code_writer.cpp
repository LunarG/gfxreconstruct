//
// Copyright (c) 2026 LunarG, Inc
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

#include "decode/vulkan_cpp_code_writer.h"

#include "util/logging.h"

#include <cstdarg>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void CodeWriter::SetFile(FILE* file, uint32_t indent)
{
    file_   = file;
    indent_ = indent;
}

void CodeWriter::Outdent()
{
    if (indent_ > 0)
    {
        --indent_;
    }
    else
    {
        GFXRECON_LOG_ERROR("CodeWriter: more outdents than indents");
    }
}

void CodeWriter::Line(const char* format, ...)
{
    if (file_ == nullptr)
    {
        return;
    }

    for (uint32_t index = 0; index < indent_; ++index)
    {
        fputc('\t', file_);
    }

    va_list args;
    va_start(args, format);
    vfprintf(file_, format, args);
    va_end(args);

    fputc('\n', file_);
}

void CodeWriter::Blank()
{
    if (file_ != nullptr)
    {
        fputc('\n', file_);
    }
}

void CodeWriter::Raw(const std::string& text)
{
    if (file_ != nullptr)
    {
        fputs(text.c_str(), file_);
    }
}

CodeWriter::Scope::Scope(CodeWriter& writer) : writer_(writer)
{
    writer_.Line("{");
    writer_.Indent();
}

CodeWriter::Scope::~Scope()
{
    writer_.Outdent();
    writer_.Line("}");
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
