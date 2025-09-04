/*
** Copyright (c) 2025 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
**
* copy of this software and associated documentation files (the "Software"),
** to deal in the Software without
* restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute,
* sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do
* so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be
* included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
* WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
* FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#if !defined(WIN32)
#include <sys/mman.h>
#endif

#include "util/file_input_stream.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(WIN32)
MappedFileOps::MappedFileOpsWindows()
{
    SYSTEM_INFO sys_info;
    GetSystemInfo(&sys_info);
    offset_alignment_ = static_cast<int64_t>(sys_info.dwAllocationGranularity);
}

MappedFileOpsWindows::~MappedFileOpsWindows()
{
    Close();
}

bool MappedFileOpsWindows::Open(const std::string& filename)
{
    // Don't double open is in the contract
    assert(!IsValid());

    // Create a file handle for the file to map
    HANDLE file_handle =
        CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);

    if (file_handle == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    // Get the file size
    LARGE_INTEGER file_size;
    if (!GetFileSizeEx(file_handle, &file_size))
    {
        CloseHandle(file_handle);
        return false;
    }
    assert(file_size.QuadPart > 0);
    file_size_ = static_cast<uint64_t>(file_size.QuadPart);

    // Create a mapping handle, from which views can be created
    mapping_handle_ = CreateFileMapping(file_handle, nullptr, PAGE_READONLY, 0, 0, nullptr);
    CloseHandle(file_handle);
    return (mapping_handle_ != nullptr);
}

void MappedFileOpsWindows::Close()
{
    if (IsValid())
    {
        CloseHandle(mapping_handle_);
        mapping_handle_ = nullptr;
    }
}

const char* MappedFileOpsWindows::MapView(int64_t offset, size_t size)
{
    if (!IsValid())
    {
        return nullptr;
    }

    LARGE_INTEGER offset_arg;
    offset_arg.QuadPart = offset;
    const char* view    = static_cast<const char*>(
        MapViewOfFile(mapping_handle_, FILE_MAP_READ, offset_arg.HighPart, offset_arg.LowPart, size));

#define MAPPEDFILE_ENABLE_PREFETCH 0
#if MAPPEDFILE_ENABLE_PREFETCH
    // NOTE: A quick experiment to see if prefetching helps, didn't show any positive effect on my test system
    if (view)
    {
        WIN32_MEMORY_RANGE_ENTRY prefetch_range = { (PVOID)view, (SIZE_T)size };
        PrefetchVirtualMemory(GetCurrentProcess(), 1, &prefetch_range, 0);
    }
#endif

    return view;
}

void MappedFileOpsWindows::UnmapView(const char* view, size_t)
{
    // Size argument not needed on Windows
    if (IsValid() && view)
    {
        UnmapViewOfFile(view);
    }
}

#else // ie. !WIN32

MappedFileOpsPosix::MappedFileOpsPosix()
{
    offset_alignment_ = sysconf(_SC_PAGE_SIZE);
}

MappedFileOpsPosix::~MappedFileOpsPosix()
{
    Close();
}

bool MappedFileOpsPosix::Open(const std::string& filename)
{
    // Don't double open is in the contract
    assert(!IsValid());

    // Create a file descriptor for the file to be mappped
    fd_ = open(filename.c_str(), O_RDONLY);
    if (fd_ == -1)
    {
        return false;
    }

    // Get the file size
    struct stat file_stat_info;
    if (fstat(fd_, &file_stat_info) == -1)
    {
        // Hmmm... can't stat it... somethings wrong.  Give up.
        close(fd_);
        fd_ = -1;
        return false;
    }
    file_size_ = file_stat_info.st_size;

    return true;
}

void MappedFileOpsPosix::Close()
{
    if (IsValid())
    {
        close(fd_);
        fd_ = -1;
    }
}

const char* MappedFileOpsPosix::MapView(int64_t offset, size_t size)
{
    if (!IsValid())
    {
        return nullptr;
    }

    // Get virtual address of mapped view
    void* view = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd_, offset);

    if (view == MAP_FAILED)
    {
        return nullptr;
    }

    return static_cast<const char*>(view);
}

void MappedFileOpsPosix::UnmapView(const char* view, size_t size)
{
    if (IsValid() && view)
    {
        // Unmap the viewed virtual address
        munmap(static_cast<void*>(const_cast<char*>(view)), size);
    }
}

#endif // WIN32

bool MappedRange::Contains(int64_t access_offset) const
{
    auto relative_offset = RelativeOffset(access_offset);
    return (0 <= relative_offset) && (relative_offset < size);
}
bool MappedRange::Contains(const MappedRange& range) const
{
    if (!Contains(range.offset))
    {
        return false;
    }

    // One or zero sized accesses don't need another check
    if (range.size > 1)
    {
        // More than one bytes access, the last byte also needs to be InView
        // But we can use the one that doesn't check for validity again
        if (!Contains(range.offset + range.size - 1))
            return false;
    }

    return true;
}
// Only call this if in range
const char* MappedView::GetDataAbsolute(int64_t absolute_offset) const
{
    assert(Contains(absolute_offset));
    return data_ + RelativeOffset(absolute_offset);
}

// Only call this if in range
void MappedView::CopyDataAbsolute(void* buffer, const MappedRange& absolute_range) const
{
    assert(Contains(absolute_range));
    memcpy(buffer, GetDataAbsolute(absolute_range.offset), absolute_range.size);
}

// Mapped Views can only be moved not copied
MappedView::MappedView(MappedView&& other) noexcept :
    mapped_file_(std::move(other.mapped_file_)), data_(other.data_), range_(other.range_)
{
    // Mark other as invalid, other.mapped_file_ is already null'd by the move
    other.data_ = nullptr;
}

// Mapped Views can only be moved not copied
MappedView& MappedView::operator=(MappedView&& other) noexcept
{
    if (this == &other)
    {
        // If they're the same we're done
        return *this;
    }

    if (IsValid())
    {
        // We currently own a view, deal with it
        // The IsValid check is actually redundant, as Reset *also* checks current, but
        // it's clearer and less fragile this way and the compiler is going to optimize it away, anyhow
        Reset();
    }
    // Reset should have cleared these
    assert(!mapped_file_);
    assert(!data_);

    mapped_file_ = std::move(other.mapped_file_);
    data_        = other.data_;
    range_       = other.range_;

    // Mark other as invalid, other.mapped_file_ is already null'd by the move
    // Do not Reset() other as that would close the view we are moving
    other.data_ = nullptr;

    return *this;
}

MappedView::~MappedView()
{
    Reset();
}

// access_offset is from beginning of file
bool MappedView::Contains(int64_t access_offset) const
{
    return IsValid() && range_.Contains(access_offset);
}

MappedFile::MappedFilePtr MappedFile::Open(const std::string& filename)
{
    MappedFilePtr mapped_file = MappedFilePtr(new MappedFile(filename));
    bool          success     = mapped_file->Open();
    if (!success)
    {
        mapped_file.reset();
    }

    return mapped_file;
}

MappedFile::MappedViewPtr MappedFile::MapView(const MappedRange& range)
{
    if (!IsValid() || ((range.offset % GetOffsetAlignment()) != 0) || ((range.offset + range.size > GetFileSize())))
    {
        return MappedViewPtr();
    }

    const char* data = Base::MapView(range.offset, range.size);
    if (data != nullptr)
    {
        return MappedViewPtr(new MappedView(shared_from_this(), data, range));
    }
    return MappedViewPtr();
}

// Find an aligned range at least as big as the size hint that includes the given range
// It is possible that the resulting range will not include the input range IFF
// the input range exceeds the file bounds.  Callers should check.
MappedRange MappedFile::ComputeContainingRange(const MappedRange& range, size_t size_hint)
{
    // Alignment is much, much less than uint32_t max
    const int64_t  alignment = GetOffsetAlignment();
    const uint64_t file_size = GetFileSize();

    // Limit legal size to include padding effects
    constexpr size_t size_type_max = std::numeric_limits<size_t>::max();
    assert(alignment < (size_type_max >> 2)); // alignment small relative to size_t
    const size_t size_max = size_type_max - 2 * alignment;

    if ((range.offset < 0) || (range.offset >= file_size) || (range.size > size_max))
    {
        // No possible view
        return MappedRange{};
    }

    // Limit size hint
    size_hint = std::min(size_max, size_hint);

    // Find a suitable starting offset, floored to the near multiple of alignment
    // less than input range (noting alignent less than size_type_max
    size_t  prepad         = range.offset % alignment;
    int64_t aligned_offset = range.offset - prepad;

    // Guaranteed not to overflow because of size_max check above and prepad < alignment
    size_t padded_size = range.size + static_cast<size_t>(prepad);

    size_t reqd_size = std::max<size_t>(size_hint, padded_size);

    size_t post_pad = alignment - (reqd_size % alignment);
    if (post_pad == alignment)
    {
        post_pad = 0;
    }

    size_t aligned_size = reqd_size + post_pad;
    aligned_size        = std::min<uint64_t>(aligned_size, (file_size - aligned_offset));

    return MappedRange{ aligned_offset, aligned_size };
}

// Utility MapViewFactory for creating views that contain a given access range, but
// that are also suitably sizes for subsequent accesses.
//
// If no containing range exists, return an empty view pointer
MappedFile::MappedViewPtr MappedFile::MapContainingView(const MappedRange& range, size_t size_hint)
{
    MappedRange containing_range = ComputeContainingRange(range, size_hint);
    if (containing_range.Contains(range))
    {
        return MapView(containing_range);
    }
    return MappedViewPtr();
}

void MappedView::Reset()
{
    if (mapped_file_ && data_)
    {
#if MAPPEDFILE_ASYNC_UNMAP
        MappedFile::UnmapViewAsync(std::move(mapped_file_), data_, range_.size);
#else
        mapped_file_->UnmapView(data_, range_.size);
        mapped_file_.reset();
#endif
        data_ = nullptr;
    }
}

bool MappedFileInputStream::Open(const std::string& filename)
{
    if (IsOpen())
    {
        Close();
    }

    mapped_file_ = MappedFile::Open(filename);
    read_pos_    = 0;

    return IsOpen();
}

void MappedFileInputStream::Close()
{
    mapped_file_.reset();
}

// Unlike FStream negative new locations are truncated to [0, file_size] (yes you can seek to eof)
bool MappedFileInputStream::FileSeek(int64_t offset, util::platform::FileSeekOrigin origin)
{
    if (!IsOpen())
        return false;

    const int64_t file_size = mapped_file_->GetFileSize();
    // Determine where we want to set readpos_ to
    int64_t new_pos;
    switch (origin)
    {
        case platform::FileSeekOrigin::FileSeekCurrent:
            new_pos = read_pos_ + offset;
            break;
        case platform::FileSeekOrigin::FileSeekSet:
            new_pos = offset;
            break;
        case platform::FileSeekOrigin::FileSeekEnd:
            // Note that offset from end of file are correctly negative.
            // 0 puts one at EOF
            new_pos = offset + file_size;
            break;
        default:
            new_pos = read_pos_;
    }

    // Bound new pos to [0, file_size]
    read_pos_ = std::max<int64_t>(0, std::min<int64_t>(new_pos, file_size));

    return true;
}

bool MappedFileInputStream::ReadBytes(void* buffer, size_t bytes)
{
    if (bytes == 0)
        return true;

    MappedRange read_range = SetupForRead(bytes);
    // Empty ranges means setup for read failed.
    if (read_range.IsEmpty())
        return false;

    // The read range is now in the current view
    current_view_->CopyDataAbsolute(buffer, read_range);
    read_pos_ += bytes;
    return true;
}

util::MappedSpan MappedFileInputStream::ReadSpan(const size_t bytes)
{
    MappedRange read_range = SetupForRead(bytes);
    if (read_range.IsEmpty())
    {
        return MappedSpan();
    }

    // Read range is in current view create the managed span and return it
    read_pos_ += read_range.size;
    return MappedSpan(current_view_, read_range);
}

MappedRange MappedFileInputStream::SetupForRead(size_t bytes)
{
    // NOTE: Don't do Open, Error or Eof checks here, as the constituent parts do the
    // right thing in those cases.  Invalid file, EOF, or bogus read_pos_ will all result
    // in an empty MappedRange being returned.

    MappedRange read_range{ read_pos_, bytes };
    if (!InCurrentView(read_range))
    {
        // We need a new view for this range
        // Note that read_pos_ might be in current view, but since we're going to need
        // create a new view to complete the access, might as well do it, and not have
        // to managed "straddle logic"
        UpdateCurrentView(read_range);
        if (!InCurrentView(read_range))
        {
            // The requested read cannot be mapped, likely EOF
            return MappedRange(); // Cannot map requested byte range
        }
    }
    return read_range;
}

// This will update the current_view_ to include the access_offset
// *ONLY* call it if !InCurrentView
void MappedFileInputStream::UpdateCurrentView(const MappedRange& range)
{
    // There are several reasons this can fail.
    assert(IsOpen());
    current_view_ = mapped_file_->MapContainingView(range, kViewSize);

    if (!current_view_)
    {
        // Failed to map a view containing the requested range
        if ((range.offset + range.size) > mapped_file_->GetFileSize())
        {
            // We're trying to read past the end of the file, set read_pos_ to EOF
            read_pos_ = mapped_file_->GetFileSize();
        }
    }
}

bool FStreamFileInputStream::Open(const std::string& filename)
{
    if (IsOpen())
    {
        Close();
    }

    const int  result  = util::platform::FileOpen(&fd_, filename.c_str(), "rb");
    const bool success = result == 0;

    if (success)
    {
        filename_ = filename;
    }
    return success;
}

void FStreamFileInputStream::Close()
{
    if (fd_)
    {
        util::platform::FileClose(fd_);
        fd_ = nullptr;
    }
}

bool FStreamFileInputStream::FileSeek(int64_t offset, util::platform::FileSeekOrigin origin)
{
    if (fd_)
    {
        return util::platform::FileSeek(fd_, offset, origin);
    }
    return false;
}

bool FStreamFileInputStream::ReadBytes(void* buffer, size_t bytes)
{
    assert(fd_);
    return util::platform::FileRead(buffer, bytes, fd_);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
