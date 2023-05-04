
/*
** Copyright (c) 2021 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "graphics/dx12_gpu_va_map.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

constexpr uint64_t kNullAddress = 0;

void Dx12GpuVaMap::Add(format::HandleId resource_id,
                       uint64_t         old_start_address,
                       uint64_t         old_size,
                       uint64_t         new_start_address)
{
    if ((resource_id != format::kNullHandleId) && (old_start_address != kNullAddress) &&
        (new_start_address != kNullAddress))
    {
        auto& aliased_resource_list     = gpu_va_map_[old_start_address];
        auto& resource_info             = aliased_resource_list[resource_id];
        resource_info.old_end_address   = old_start_address + old_size;
        resource_info.new_start_address = new_start_address;
    }
}

void Dx12GpuVaMap::Remove(format::HandleId resource_id, uint64_t old_start_address)
{
    if ((resource_id != format::kNullHandleId) && (old_start_address != kNullAddress))
    {
        auto entry = gpu_va_map_.find(old_start_address);
        if (entry != gpu_va_map_.end())
        {
            entry->second.erase(resource_id);
            if (entry->second.empty())
            {
                gpu_va_map_.erase(entry);
            }
        }
    }
}

uint64_t Dx12GpuVaMap::Map(uint64_t                 address,
                           format::HandleId*        resource_id,
                           bool*                    found,
                           uint64_t                 minimum_old_end_address,
                           ResourceMatchFunctionPtr resource_match_func) const
{
    bool local_found = false;

    if (address != kNullAddress)
    {
        auto va_entry = gpu_va_map_.lower_bound(address);
        if (va_entry != gpu_va_map_.end())
        {
            // Check for a match in the aliased resource list.
            local_found = FindMatch(
                va_entry->second, va_entry->first, address, resource_id, minimum_old_end_address, resource_match_func);

            // The addresses did not fall within the address range of the resource(s) at the start address returned
            // by the lower_bound search.  These resources may be aliased with a larger resource that contains them.
            // Check for an aliased resource with a smaller start address.  The entries in the GPU VA map are sorted
            // in descending order to get a <= behavior from lower_bound, so the next smallest address is obtained
            // by incrementing the iterator.

            // NOTE: This turns the O(logn) search into a O(n) search when an entry is not found in the map.  If this
            // becomes an issue, it is possible that the add and remove operations be changed to merge all aliased
            // resources into a single entry keyed by the smallest start address of all of the aliased resources.  On
            // remove, if none of the remaining aliased resources share the start address that is used for the key to
            // the entry, the entry would need to be removed and re-added with the smallest address of the remaining
            // aliased resources as the key.
            while (!local_found && ++va_entry != gpu_va_map_.end())
            {
                local_found = FindMatch(va_entry->second,
                                        va_entry->first,
                                        address,
                                        resource_id,
                                        minimum_old_end_address,
                                        resource_match_func);
            }
        }

        if (!local_found && (found == nullptr))
        {
            GFXRECON_LOG_WARNING_ONCE("No matching replay address found for capture address.");
        }
    }

    if (found != nullptr)
    {
        (*found) = local_found;
    }

    return address;
}

// If func is valid, the function return matched resource which is used for RaytracingAccelerationStructure,
// if func is nullptr, it return first resource which match old_start_address and minimum_old_end_address.
bool Dx12GpuVaMap::FindMatch(const AliasedResourceVaInfo& resource_info,
                             uint64_t                     old_start_address,
                             uint64_t&                    address,
                             format::HandleId*            resource_id,
                             uint64_t                     minimum_old_end_address,
                             ResourceMatchFunctionPtr     resource_match_func) const
{
    // Check for a match in the aliased resource list.
    for (const auto& resource_entry : resource_info)
    {
        const auto& info = resource_entry.second;

        if (address < info.old_end_address && minimum_old_end_address <= info.old_end_address)
        {
            address = info.new_start_address + (address - old_start_address);

            // if type checking func is valid, then call it to looking for expected type of resource
            if ((resource_match_func == nullptr) || ((*resource_match_func)(resource_entry.first) == true))
            {
                if (resource_id != nullptr)
                {
                    *resource_id = resource_entry.first;
                }

                return true;
            }
        }
    }

    return false;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
