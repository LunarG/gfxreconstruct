/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_INTERCEPTION_UTILS_REAL_AND_MINE_HOOK_H
#define GFXRECON_INTERCEPTION_UTILS_REAL_AND_MINE_HOOK_H

#include "hooking_detours.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

//--------------------------------------------------------------------------
/// Manage linking a Real_ and Mine_ function together when hooked.
//--------------------------------------------------------------------------
template <typename HookType>
class RealAndMineHook
{
  public:
    //--------------------------------------------------------------------------
    /// Default constructor that initializes the internal hooks to nullptr.
    //--------------------------------------------------------------------------
    RealAndMineHook() : real_hook_(nullptr), mine_hook_(nullptr) {}

    //--------------------------------------------------------------------------
    /// Initialize the hooks pair within this instance of a RealAndMineHook.
    /// \param inRealHook A function pointer to the real implementation of the function.
    /// \param inMineHook A function pointer to the Mine_ implementation of the function.
    //--------------------------------------------------------------------------
    void SetHooks(HookType inRealHook, HookType inMineHook)
    {
        real_hook_ = inRealHook;
        mine_hook_ = inMineHook;
    }

    //--------------------------------------------------------------------------
    /// This call allows us to attach our hooked function.
    /// \return True if the function was hooked successfully, false if otherwise.
    //--------------------------------------------------------------------------
    bool Attach()
    {
        hooked_ = HookAPICall((PVOID*)&real_hook_, mine_hook_);

        return hooked_;
    }

    //--------------------------------------------------------------------------
    /// This call allows us to detach our hooked function.
    /// \return True if the function was unhooked successfully.
    //--------------------------------------------------------------------------
    void Detach()
    {
        if (true == hooked_)
        {
            UnhookAPICall((PVOID*)&real_hook_, mine_hook_);
        }
    }

    /// Flag indicating whether the function was hooked
    bool hooked_ = false;

    /// A function pointer to the real function implementation.
    HookType real_hook_;

    /// A function pointer to the instrumented function implementation.
    HookType mine_hook_;
};

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INTERCEPTION_UTILS_REAL_AND_MINE_HOOK_H
