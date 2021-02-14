/*
** Copyright (c) 2021 LunarG, Inc.
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

#include "decode/dx12_ascii_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

Dx12AsciiConsumerBase::Dx12AsciiConsumerBase() : m_file(nullptr) {}

Dx12AsciiConsumerBase::~Dx12AsciiConsumerBase()
{
    Destroy();
}

bool Dx12AsciiConsumerBase::Initialize(const std::string& filename)
{
    bool success = false;

    if (m_file == nullptr)
    {
        int32_t result = util::platform::FileOpen(&m_file, filename.c_str(), "w");
        if (result == 0)
        {
            success    = true;
            m_filename = filename;
        }
    }

    return success;
}

void Dx12AsciiConsumerBase::Destroy()
{
    if (m_file != nullptr)
    {
        util::platform::FileClose(m_file);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
