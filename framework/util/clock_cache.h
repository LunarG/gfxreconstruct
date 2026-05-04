/*
** Copyright (c) 2025 LunarG, Inc.
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
#ifndef GFXRECON_UTIL_CLOCK_CACHE_H

#include "util/defines.h"
#include "util/logging.h"

#include <array>
#include <limits>
#include <optional>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
template <typename T>
struct IdentityTransform
{
    const T& operator()(const T& v) { return v; }
};

template <typename ValueType,
          unsigned char LogSize,
          typename KeyType      = ValueType,
          typename KeyExtractor = IdentityTransform<KeyType>,
          typename Hash         = std::hash<KeyType>,
          typename Equal        = std::equal_to<KeyType>>
class ClockCache
{
  public:
    constexpr static size_t kCacheSize = (1U << LogSize);

    using Cache    = std::array<ValueType, kCacheSize>;
    using SizeType = typename Cache::size_type;
    using Map      = std::unordered_map<KeyType, SizeType, Hash, Equal>;

    using value_type = typename Cache::value_type;
    using key_type   = KeyType;

    using UseBits = std::array<bool, kCacheSize>;

    ClockCache() { use_bits_.fill(false); }

    std::optional<ValueType> Lookup(const KeyType& key)
    {
        auto find_it = index_.find(key);
        if (find_it != index_.end())
        {
            const SizeType index = find_it->second;
            use_bits_[index]     = true;
            return cache_[index];
        }
        return std::nullopt;
    }

    template <typename T>
    bool Insert(T&& value)
    {
        static_assert(std::is_same_v<std::decay_t<T>, ValueType>, "Passed argument must be ValueType lvalue or rvalue");

        // Look for value in cache.
        // Note lifetime.  Do not use key after forwarding value
        const KeyType& key     = GetKey(value);
        auto           find_it = index_.find(key);
        if (find_it != index_.end())
        {
            ++hit_;
            use_bits_[find_it->second] = true;
            return false;
        }

        auto fill_slot = [&key, &value, this](SizeType index) {
            index_.insert(std::make_pair(key, index));
            cache_[index]    = std::forward<T>(value);
            use_bits_[index] = true;
        };

        // Key not in cache_, find next non-recent slot to replace
        ++miss_;

        if (size_ < kCacheSize)
        {
            // No victim search because the cache is still filling, so we take the next free slot
            // Don't advance the next_slot needelessly
            fill_slot(size_);
            size_++;
        }
        else
        {
            GFXRECON_ASSERT(size_ == kCacheSize);
            // May loop through kCachSize + 1 times if use_bits_ uniformly true
            while (use_bits_[next_slot_])
            {
                // Set slot to not used since checked
                use_bits_[next_slot_] = false;
                AdvanceNextSlot();
            }

            // Victim found, remove and replace
            index_.erase(GetKey(cache_[next_slot_]));
            fill_slot(next_slot_);
            AdvanceNextSlot();
        }
        return true;
    }

    double HitRate() const
    {
        size_t total = hit_ + miss_;
        if (total)
        {
            return static_cast<double>(hit_) / static_cast<double>(total);
        }
        return 0.;
    }

  private:
    static const KeyType& GetKey(const ValueType& value) { return KeyExtractor()(value); }
    void                  AdvanceNextSlot() { next_slot_ = (next_slot_ + 1) % kCacheSize; }

    Cache    cache_;
    UseBits  use_bits_;
    Map      index_;
    SizeType next_slot_ = 0;
    SizeType size_      = 0;

    size_t hit_  = 0;
    size_t miss_ = 0;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GFXRECON_UTIL_CLOCK_CACHE_H
