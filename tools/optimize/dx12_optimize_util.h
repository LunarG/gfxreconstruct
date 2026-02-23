/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef GFXRECON_DX12_OPTIMIZE_UTIL_H
#define GFXRECON_DX12_OPTIMIZE_UTIL_H

#include "decode/dx12_object_scanning_consumer.h"
#include "decode/dx12_referenced_resource_consumer.h"
#include "decode/dx12_optimize_options.h"
#include "generated/generated_dx12_decoder.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

bool Dx12OptimizeFile(std::string                      input_filename,
                      std::string                      output_filename,
                      decode::Dx12OptimizationOptions& options);

GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_OPTIMIZE_UTIL_H
