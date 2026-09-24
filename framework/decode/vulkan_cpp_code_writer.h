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

#ifndef GFXRECON_DECODE_VULKAN_CPP_CODE_WRITER_H
#define GFXRECON_DECODE_VULKAN_CPP_CODE_WRITER_H

#include "util/defines.h"

#include <cstdint>
#include <cstdio>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Writes the generated source and owns the indent level.
//
// An emitter that uses this class does not put a tab in a format string. That
// removes the main cause of wrong indentation in the generated source, because
// an emitter cannot know how deep the code around it is.
class CodeWriter
{
  public:
    CodeWriter() = default;

    // The writer does not own the file. The caller closes it.
    void  SetFile(FILE* file, uint32_t indent = 0);
    FILE* GetFile() const { return file_; }
    bool  IsValid() const { return file_ != nullptr; }

    // Write one line at the current indent. The format works like printf.
    void Line(const char* format, ...);

    // Write an empty line.
    void Blank();

    // Write text that already holds its own line breaks and indent, such as the
    // output of a GenerateStruct_ function. The writer adds no indent here.
    void Raw(const std::string& text);

    void     Indent() { ++indent_; }
    void     Outdent();
    uint32_t GetIndent() const { return indent_; }

    // Writes an open brace, then indents. On destruction it outdents and writes
    // the close brace, so that the two always match.
    class Scope
    {
      public:
        explicit Scope(CodeWriter& writer);
        ~Scope();

        Scope(const Scope&)            = delete;
        Scope& operator=(const Scope&) = delete;

      private:
        CodeWriter& writer_;
    };

  private:
    FILE*    file_{ nullptr };
    uint32_t indent_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_CPP_CODE_WRITER_H
