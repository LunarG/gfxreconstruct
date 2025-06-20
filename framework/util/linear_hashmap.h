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

#ifndef GFXRECONSTRUCT_UTIL_LINEAR_HASHMAP_H
#define GFXRECONSTRUCT_UTIL_LINEAR_HASHMAP_H

#include "util/alignment_utils.h"
#include "util/defines.h"
#include "util/hash.h"
#include <algorithm>
#include <functional>
#include <memory>
#include <optional>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/**
 * @brief   linear_hashmap is a hashmap using open addressing with linear probing.
 *          it can be used for POD key/value pairs and operates on a single array without chaining.
 *
 * goal is to offer an easy and performant hashmap-storage that can be populated on CPU- and queried on GPU-pipelines.
 *
 * @tparam K
 * @tparam V
 */
template <typename K, typename V>
class linear_hashmap
{
  public:
    using key_t     = K;
    using value_t   = V;
    using hash32_fn = std::function<uint32_t(const key_t&)>;
    static_assert(std::is_default_constructible_v<key_t>, "key_t not default-constructible");
    static_assert(key_t() == key_t(), "key_t not comparable");

    linear_hashmap()                      = default;
    linear_hashmap(const linear_hashmap&) = delete;
    linear_hashmap(linear_hashmap&& other) noexcept : linear_hashmap() { swap(*this, other); };
    linear_hashmap& operator=(linear_hashmap other)
    {
        swap(*this, other);
        return *this;
    }

    explicit linear_hashmap(uint64_t min_capacity) :
        m_capacity(util::next_pow_2(min_capacity)), m_storage(std::make_unique<storage_item_t[]>(m_capacity))
    {
        clear();
    }

    [[nodiscard]] inline size_t size() const { return m_num_elements; }

    [[nodiscard]] inline size_t capacity() const { return m_capacity; }

    [[nodiscard]] inline bool empty() const { return size() == 0; }

    inline void clear()
    {
        m_num_elements      = 0;
        storage_item_t *ptr = m_storage.get(), *end = ptr + m_capacity;
        for (; ptr != end; ++ptr)
        {
            ptr->key   = key_t();
            ptr->value = std::optional<value_t>();
        }
    }

    inline uint32_t put(const key_t& key, const value_t& value)
    {
        check_load_factor();
        return internal_put(key, value);
    }

    [[nodiscard]] std::optional<value_t> get(const key_t& key) const
    {
        if (!m_capacity)
        {
            return {};
        }

        for (uint32_t idx = m_hash_fn(key);; idx++)
        {
            idx &= m_capacity - 1;
            auto& item = m_storage[idx];
            if (item.key == key_t())
            {
                return {};
            }
            else if (key == item.key)
            {
                if (item.value)
                {
                    return item.value;
                }
            }
        }
    }

    void remove(const key_t& key)
    {
        if (!m_capacity)
        {
            return;
        }

        for (uint32_t idx = m_hash_fn(key);; idx++)
        {
            idx &= m_capacity - 1;
            auto& item = m_storage[idx];
            if (item.key == key_t())
            {
                return;
            }
            else if (key == item.key && item.value)
            {
                item.value = {};
                m_num_elements--;
                return;
            }
        }
    }

    [[nodiscard]] inline bool contains(const key_t& key) const { return get(key) != std::nullopt; }

    size_t get_storage(void* dst) const
    {
        struct output_item_t
        {
            key_t   key   = {};
            value_t value = {};
        };

        if (dst)
        {
            auto            output_ptr = reinterpret_cast<output_item_t*>(dst);
            storage_item_t *item = m_storage.get(), *end = item + m_capacity;
            for (; item != end; ++item, ++output_ptr)
            {
                if (item->key != key_t())
                {
                    output_ptr->key   = item->key;
                    output_ptr->value = item->value ? *item->value : value_t();
                }
                else
                {
                    *output_ptr = {};
                }
            }
        }
        return sizeof(output_item_t) * m_capacity;
    }

    void reserve(size_t new_capacity)
    {
        auto            new_linear_hashmap = linear_hashmap(new_capacity);
        storage_item_t *ptr = m_storage.get(), *end = ptr + m_capacity;
        for (; ptr != end; ++ptr)
        {
            if (ptr->key != key_t())
            {
                if (ptr->value)
                {
                    new_linear_hashmap.put(ptr->key, *ptr->value);
                }
            }
        }
        swap(*this, new_linear_hashmap);
    }

    [[nodiscard]] float load_factor() const { return static_cast<float>(m_num_elements) / m_capacity; }

    [[nodiscard]] float max_load_factor() const { return m_max_load_factor; }

    void max_load_factor(float load_factor)
    {
        m_max_load_factor = std::clamp<float>(load_factor, 0.01f, 1.f);
        check_load_factor();
    }

    friend void swap(linear_hashmap& lhs, linear_hashmap& rhs)
    {
        std::swap(lhs.m_capacity, rhs.m_capacity);
        std::swap(lhs.m_num_elements, rhs.m_num_elements);
        std::swap(lhs.m_storage, rhs.m_storage);
        std::swap(lhs.m_hash_fn, rhs.m_hash_fn);
        std::swap(lhs.m_max_load_factor, rhs.m_max_load_factor);
        std::swap(lhs.m_grow_factor, rhs.m_grow_factor);
    }

  private:
    struct storage_item_t
    {
        key_t                  key;
        std::optional<value_t> value;
    };

    inline void check_load_factor()
    {
        if (m_num_elements >= m_capacity * m_max_load_factor)
        {
            reserve(std::max<size_t>(32, static_cast<size_t>(m_grow_factor * m_capacity)));
        }
    }

    inline uint32_t internal_put(const key_t key, const value_t& value)
    {
        uint32_t probe_length = 0;

        for (uint64_t idx = m_hash_fn(key);; idx++, probe_length++)
        {
            idx &= m_capacity - 1;
            auto& item = m_storage[idx];

            // load previous key
            key_t probed_key = item.key;

            if (probed_key != key)
            {
                // hit another valid entry, keep probing
                if (probed_key != key_t() && item.value)
                {
                    continue;
                }
                item.key = key;
                m_num_elements++;
            }
            item.value = value;
            return probe_length;
        }
    }

    uint64_t                          m_capacity     = 0;
    uint64_t                          m_num_elements = 0;
    std::unique_ptr<storage_item_t[]> m_storage;
    hash32_fn                         m_hash_fn = std::bind(hash::xxhash32<key_t>, std::placeholders::_1, 0);

    // reasonably low load-factor to keep average probe-lengths low
    float m_max_load_factor = 0.5f;
    float m_grow_factor     = 2.f;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECONSTRUCT_UTIL_LINEAR_HASHMAP_H
