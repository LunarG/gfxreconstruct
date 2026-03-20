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

#ifndef GFXRECON_UTIL_FEATURE_MODULE_REGISTRY_H
#define GFXRECON_UTIL_FEATURE_MODULE_REGISTRY_H

#include "util/defines.h"

#include <functional>
#include <iomanip>
#include <memory>
#include <mutex>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <typename T>
class FeatureModuleRegistry
{
  public:
    static FeatureModuleRegistry& GetSingleton()
    {
        std::call_once(singleton_flag_, [&]() { singleton_.reset(new FeatureModuleRegistry<T>()); });
        return *singleton_;
    }

    ~FeatureModuleRegistry() = default;

    // Define a method that can be used to create and cast a child unique_ptr
    // to the base type so it can be registered.
    using funcCreator = std::function<std::unique_ptr<T>()>;
    void RegisterFeatureCreator(funcCreator creator)
    {
        const std::lock_guard<std::mutex> lock(target_mut_);
        registered_modules_.push_back(creator);
    }
    std::vector<funcCreator>& GetRegisteredFeatureCreators() { return registered_modules_; }

  private:
    inline static std::unique_ptr<FeatureModuleRegistry> singleton_;
    inline static std::once_flag                         singleton_flag_;
    inline static std::mutex                             target_mut_;

    std::vector<funcCreator> registered_modules_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#define GFXR_UTIL_REGISTER_FEATURE_CREATOR(B, T)                                         \
    inline static const bool __registered_##T = []() {                                   \
        gfxrecon::util::FeatureModuleRegistry<B>::GetSingleton().RegisterFeatureCreator( \
            []() { return std::make_unique<T>(); });                                     \
        return true;                                                                     \
    }();

#endif // GFXRECON_UTIL_FEATURE_MODULE_REGISTRY_H
