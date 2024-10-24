/*
** Copyright (c) 2018-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GPU_VA_MAP_H
#define GPU_VA_MAP_H

#include "gpu_va_range.h"
#include "util/defines.h"

#include <d3d12.h>
#include "logging.h"

#include <Windows.h>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

/// This class maps from capture GPU virtual address (VA) to a
/// list of buffer resources bound to that GPU virtual address,
/// and the replay GPU VA.
///
/// Assumptions
/// * Subresource GPU VA range is consecutive
/// * GPU VA for a buffer resource is accessible when it is
///   added to the map
/// Operations on this class are not multi-thread safe, it is
/// up to the caller to synchronize all map operations.
///
/// On capture side GPU VA stored wrapped resoure pointer
/// On playback side GPU VA stored captured resource pointer
///
/// The current implementation of GPU VA map uses a linear
/// range search to find the buffer resource at a given GPU VA

class GpuVaMap
{
  public:
    GpuVaMap(const GpuVaMap&) noexcept            = delete;
    GpuVaMap& operator=(const GpuVaMap&) noexcept = delete;
    GpuVaMap(GpuVaMap&&) noexcept                 = delete;
    GpuVaMap& operator=(GpuVaMap&&) noexcept      = delete;

    GpuVaMap() = default;

    //----------------------------------------------------------------------------
    /// Add a buffer resource to the map
    /// \param pointer to resource
    /// \return True if adding the buffer succeeded
    ///         False if buffer is null, or not a buffer OR
    ///         if buffer GPU VA cannot be accessed OR
    ///         if adding the buffer failed
    //----------------------------------------------------------------------------
    bool Add(ID3D12Resource* resource);

    //----------------------------------------------------------------------------
    /// Add a buffer resource to the map
    /// \param [in] Pointer to the capture resource in the given GPU VA
    /// \param [in] The resources GPU VA
    /// \param [in] The resource Desc
    /// \return True if adding the buffer succeeded
    ///         False if buffer is null, or not a buffer OR
    ///         if buffer GPU VA cannot be accessed OR
    ///         if adding the buffer failed
    //----------------------------------------------------------------------------
    bool Add(ID3D12Resource* resource, D3D12_GPU_VIRTUAL_ADDRESS gpu_va, D3D12_RESOURCE_DESC* desc);

    //----------------------------------------------------------------------------
    /// Add a caputre / replay buffer resource to the map
    /// This method is used during replay to add the capture and replay
    /// GPU VAs for a given resource to the map.
    /// \param resource [in] Pointer to the capture/replay resource in the given GPU VA
    /// \param capture_gpu_va [in] [in] The resources GPU VA
    /// \param replay_gpu_va [in] The resources GPU VA
    /// \param desc [in] The resource Desc
    /// \return True if adding the buffer succeeded
    ///         False if buffer is null, or not a buffer, or one of the GPU VAs is invalid OR
    ///         if adding the buffer failed
    //----------------------------------------------------------------------------
    bool Add(ID3D12Resource*           resource,
             D3D12_GPU_VIRTUAL_ADDRESS capture_gpu_va,
             D3D12_GPU_VIRTUAL_ADDRESS replay_gpu_va,
             D3D12_RESOURCE_DESC*      desc);

    //----------------------------------------------------------------------------
    /// Remove a buffer resource from the map
    /// \param resource [in] Pointer to resource
    /// \return True if removing the buffer succeeded
    ///         False if buffer is null, or not in the map
    //----------------------------------------------------------------------------
    bool Remove(ID3D12Resource* resource);

    //----------------------------------------------------------------------------
    /// Remove a buffer resource from the map
    /// \param resource [in] Pointer to resource
    /// \param buffer_range [in] GPU VA range
    /// \return True if removing the buffer succeeded
    ///         False if buffer is null, or not in the map
    //----------------------------------------------------------------------------
    bool Remove(const ID3D12Resource* resource, GpuVaRange& buffer_range);

    //----------------------------------------------------------------------------
    /// Access the number of buffer resources bound to the given GPU VA
    /// \param gpu_va [in] GPU VA accessed
    /// \return Number of resourcs bound to the given GPU VA
    ///         0 if gpu_va is not in the map or if gpu_va is 0
    //----------------------------------------------------------------------------
    int GetResourcesCount(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) const;

    //----------------------------------------------------------------------------
    /// Access the buffer resources bound to the given GPU VA
    /// The resources returned by this method are owned by the map,
    /// and not the caller.
    /// \param gpu_va [in] GPU VA accessed
    /// \param resource_index [in] Index of the resource bound to the given GPU VA
    /// \param resource [out] Caller allocated list of resource bound to the gpu_va
    /// \return True if accessing the resource succeeded
    ///         False if gpu_va is not in the map OR
    ///         if gpu_va is 0, or if resource is null, or
    ///         if resource index is out of bounds
    //----------------------------------------------------------------------------
    bool GetResource(D3D12_GPU_VIRTUAL_ADDRESS gpu_va, int resource_index, ID3D12Resource** resource) const;

    //----------------------------------------------------------------------------
    /// Access the replay GPU VA from the given capture GPU VA
    /// \param gpu_va [in] [in] capture GPU VA accessed
    /// \return The replay GPU VA corresponding to the provided GPU VA,
    ///			or 0 if the capture GPU VA is not in the map
    //----------------------------------------------------------------------------
    D3D12_GPU_VIRTUAL_ADDRESS GetReplayGpuVa(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) const;

  private:
    /// Capture GPU VA range
    ///
    /// The capture GPU VA range is used to map a cpature GPU VA range to
    /// * List of D3D12 buffer resources
    ///	  * During capture these will be pointers to the application resources
    ///	  * During replay these will be pointers to the replay D3D12 resources
    ///		created by the DX12 player
    ///	* The replay GPU VA (assumes replay range size is equal to capture range
    ///	  size).
    struct GpuVaPage
    {
        std::vector<ID3D12Resource*> buffers{};   ///< List of buffers that are (partially) allocated in the page
        D3D12_GPU_VIRTUAL_ADDRESS    gpu_va{ 0 }; ///< The replay mapped GPU VA range start
    };

    /// Single level page table
    ///
    /// Store the given size number of page data.
    /// Top (= 0) and mid level page tables page is a pointer to the next
    /// level page table.
    /// The bottom level (= 4) page table page data is a pointer to a
    /// GpuVaRange structure

    template <typename T>
    struct PageTable
    {
        std::vector<T> pages;
    };

    /// Convenience types for different levels of the page table
    using PageTableLevel3 = PageTable<GpuVaPage>;
    using PageTableLevel2 = PageTable<PageTableLevel3>;
    using PageTableLevel1 = PageTable<PageTableLevel2>;
    using PageTableLevel0 = PageTable<PageTableLevel1>;

    // The constant values used here assume that D3D12_GPU_VIRTUAL_ADDRESS
    // is 64 bit and has 4 levels.
    static constexpr int                       kPageTableLevelCount{ 4 };
    static constexpr int                       kTopPageTableBitSize{ 16 };
    static constexpr int                       kTopPageTableBitMask{ (1 << kTopPageTableBitSize) - 1 };
    static constexpr int                       kPageTableBitSize{ 12 };
    static constexpr int                       kPageTableBitMask{ (1 << kPageTableBitSize) - 1 };
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kPageSize{ 1 << kPageTableBitSize };
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kPageBitsMask{ (1 << kPageTableBitSize) - 1 };
    static constexpr D3D12_GPU_VIRTUAL_ADDRESS kZeroPageBitsMask{ ~kPageBitsMask };

    //----------------------------------------------------------------------------
    /// Access the indices of into each table in the GPU VA map multi level
    /// page table
    /// \param gpu_va [in] GPU VA accessed
    /// \return An array of indices into each level of the page table,
    ///			where the top most level is at array index 0, and the
    ///			bottom level is at the end array index.
    //----------------------------------------------------------------------------
    static const std::array<int, kPageTableLevelCount> GetPageTableIndices(D3D12_GPU_VIRTUAL_ADDRESS gpu_va) noexcept;

    //----------------------------------------------------------------------------
    /// Check if there is a page allocated in the multi level page table
    /// \return True if the page is alloacted, false if not
    //----------------------------------------------------------------------------
    bool IsPageAllocated(const std::array<int, kPageTableLevelCount>& table_indices) const noexcept;

    //----------------------------------------------------------------------------
    /// Access a page in the multi level page table
    /// If the page does not have an entry in the map, this function
    /// will allocate it.
    /// \return True if the page is alloacted, false if not
    //----------------------------------------------------------------------------
    const GpuVaPage& GetPage(const std::array<int, kPageTableLevelCount>& table_indices) const;

    GpuVaPage& GetPage(const std::array<int, kPageTableLevelCount>& table_indices);

    /// The top level page table
    PageTableLevel0 page_table;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
#endif // GPU_VA_MAP_HH
