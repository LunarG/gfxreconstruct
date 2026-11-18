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

#ifndef GFXRECON_UTIL_INPUT_FILE_STORE_H
#define GFXRECON_UTIL_INPUT_FILE_STORE_H

#include "util/defines.h"

#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Holds the input files a remote controller pushes during the handshake in a per-process scratch directory, so read
// sites open an ordinary path. Not thread-safe; the owner keeps it on one thread.
class InputFileStore
{
  public:
    // Root to create the scratch directory under. Empty selects the temp directory, which Android does not have.
    explicit InputFileStore(std::string scratch_root = {});

    // Cleanup() as a fallback; a tool that exits without unwinding has to call it.
    ~InputFileStore();

    InputFileStore(const InputFileStore&)            = delete;
    InputFileStore& operator=(const InputFileStore&) = delete;

    // Writes data into the scratch directory as name, which must be a bare file name. Returns false on failure. Also
    // reaps directories abandoned by earlier runs.
    bool Add(const std::string& name, const std::vector<uint8_t>& data);

    // Path to a previously added file, or nullopt when name was not supplied by the controller.
    std::optional<std::string> Resolve(const std::string& name) const;

    // Removes the scratch directory and everything in it.
    void Cleanup();

  private:
    // Creates the scratch directory on first use. Returns false on failure.
    bool EnsureScratchDir();

    std::string                                  scratch_root_;
    std::string                                  scratch_dir_;
    std::unordered_map<std::string, std::string> files_; // File name to scratch path.
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_INPUT_FILE_STORE_H
