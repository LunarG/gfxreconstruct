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
#ifndef GFXRECON_UTIL_FILE_INPUT_STREAM_H
#define GFXRECON_UTIL_FILE_INPUT_STREAM_H

#if !defined(WIN32)
#include <fcntl.h>
#endif

// Control the use of async unmap of mapped views.
#define MAPPEDFILE_ASYNC_UNMAP 1

#include "util/platform.h"
#if MAPPEDFILE_ASYNC_UNMAP
#include "util/threadpool.h"
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if defined(WIN32)
class MappedFileOpsWindows
{
  public:
    int64_t  GetOffsetAlignment() const { return offset_alignment_; }
    bool     IsValid() const { return mapping_handle_ != nullptr; }
    uint64_t GetFileSize() const { return file_size_; }

  protected:
    MappedFileOpsWindows();
    ~MappedFileOpsWindows();
    bool        Open(const std::string& filename);
    void        Close();
    const char* MapView(int64_t offset, size_t size);
    void        UnmapView(const char* view, size_t);

  private:
    uint64_t file_size_      = 0;
    HANDLE   mapping_handle_ = nullptr;
    int64_t  offset_alignment_;
};
using MappedFileOps = MappedFileOpsWindows;
#else
class MappedFileOpsPosix
{
  public:
    int64_t  GetOffsetAlignment() const { return offset_alignment_; }
    bool     IsValid() const { return fd_ != -1; }
    uint64_t GetFileSize() const { return file_size_; }

  protected:
    MappedFileOpsPosix();
    ~MappedFileOpsPosix();
    bool        Open(const std::string& filename);
    void        Close();
    const char* MapView(int64_t offset, size_t size);
    void        UnmapView(const char* view, size_t size);

  private:
    uint64_t file_size_ = 0;
    int      fd_        = -1;
    int64_t  offset_alignment_;
};

using MappedFileOps = MappedFileOpsPosix;

#endif

// The Platform Independent interface for memory mapped file management
class MappedFile;
struct MappedRange
{
    int64_t offset = 0;
    size_t  size   = 0U;

    int64_t RelativeOffset(int64_t absolute_offset) const { return absolute_offset - offset; }
    bool    IsEmpty() const { return size == 0; }
    bool    Contains(int64_t access_offset) const;
    bool    Contains(const MappedRange& range) const;
};

// MappedView acts a unique pointer to a view.  It can only be created by a MappedFile object
// The shared_ptr are used to ensure views cannot outlive the file mapping
class MappedView
{
  public:
    using MappedFilePtr = std::shared_ptr<MappedFile>;

    const char* GetData() const { return data_; }

    // Only call these only if in range
    const char* GetDataAbsolute(int64_t absolute_offset) const;
    void        CopyDataAbsolute(void* buffer, const MappedRange& absolute_range) const;

    const MappedRange& GetRange() const { return range_; }
    explicit           operator bool() const { return data_ != nullptr && mapped_file_; }
    bool               IsValid() const { return static_cast<bool>(*this); }

    // Alternate STL style interface...
    const char* data() const { return data_; }
    size_t      size() const { return range_.size; }
    int64_t     offset() const { return range_.offset; }
    bool        has_value() const { return static_cast<bool>(*this); }

    // Mapped Views can only be moved not copied
    MappedView(MappedView&& other) noexcept;

    // Mapped Views can only be moved not copied
    MappedView& operator=(MappedView&& other) noexcept;
    void        Reset();

    MappedView()                             = delete;
    MappedView(const MappedView&)            = delete;
    MappedView& operator=(const MappedView&) = delete;

    ~MappedView();
    ; // May need to tell mapped_file_ to clean up the view

    friend MappedFile;

    // access_offset and access.offset are from beginning of file
    bool Contains(int64_t access_offset) const;
    bool Contains(const MappedRange& access) const { return IsValid() && range_.Contains(access); }

  private:
    MappedView(const MappedFilePtr& mapped_file, const char* data, const MappedRange& range) :
        mapped_file_(mapped_file), data_(data), range_(range)
    {}

    // access_offset is from beginning of file
    int64_t RelativeOffset(int64_t absolute_offset) const { return range_.RelativeOffset(absolute_offset); }

    MappedFilePtr mapped_file_;
    const char*   data_  = nullptr;
    MappedRange   range_ = { 0, 0 };
};

// MappedFile is the plaform independent implementation of the memory mapped (read-only) file access
class MappedFile : public MappedFileOps, public std::enable_shared_from_this<MappedFile>
{
  public:
    using Base          = MappedFileOps;
    using MappedFilePtr = MappedView::MappedFilePtr;
    using MappedViewPtr = std::shared_ptr<MappedView>;

    static MappedFilePtr Open(const std::string& filename);
    MappedViewPtr        MapView(const MappedRange& range);
    MappedRange          ComputeContainingRange(const MappedRange& range, size_t size_hint);

    // Utility MapViewFactory for creating views that contain a given access range, but
    // that are also suitably sizes for subsequent accesses.
    //
    // If no containing range exists, return an empty view pointer
    MappedViewPtr MapContainingView(const MappedRange& range, size_t size_hint);

    const std::string& GetFilename() const { return filename_; }

    friend MappedView;

  protected:
#if MAPPEDFILE_ASYNC_UNMAP
    static void UnmapViewAsync(MappedFilePtr&& view_owner, const char* data, size_t size)
    {
        // Offload the unmap to a thread pool to avoid blocking the main thread

        // Note: Since the lambda construction will null out view_owner, we need to get a reference to the
        //       thread pool before the move happens
        ThreadPool& unmap_pool_ref = view_owner->unmap_pool_;
        unmap_pool_ref.post([view_owner = std::move(view_owner), data, size]() { view_owner->UnmapView(data, size); });
    }
    MappedFile(const std::string& filename) : filename_(filename), unmap_pool_(2) {}
#else
    MappedFile(const std::string& filename) : filename_(filename) {}
#endif
    void UnmapView(const char* data, size_t size)
    {
        Base::UnmapView(data, size);
    }
    bool Open()
    {
        return Base::Open(filename_);
    }

    const std::string filename_;
#if MAPPEDFILE_ASYNC_UNMAP
    ThreadPool unmap_pool_;
#endif
};

class MappedSpan
{
  public:
    // STL style interface
    const char* data() const noexcept { return data_; }
    size_t      size() const noexcept { return size_; }
    bool        empty() const noexcept { return !data_ || size_ == 0; }

    const char* GetData() const noexcept { return data(); }
    size_t      GetSize() const noexcept { return size(); }
    bool        IsValid() const noexcept { return !empty(); }

    MappedSpan(const MappedFile::MappedViewPtr& view, const MappedRange& range) :
        view_(view), data_(view && view->Contains(range) ? view->GetDataAbsolute(range.offset) : nullptr),
        size_(data_ ? range.size : 0)
    {}
    MappedSpan() = default;

  private:
    MappedFile::MappedViewPtr view_;           // To ensure data_ doesn't dangle
    const char* const         data_ = nullptr; // Start of span relative to view_;
    const size_t              size_ = 0U;      //  Length of the span
};

class MappedFileInputStream
{
  public:
    std::string           GetFilename() const { return mapped_file_ ? mapped_file_->GetFilename() : std::string(); }
    constexpr static bool HasReadSpanSupport() { return true; }
    bool                  IsOpen() const { return mapped_file_ && mapped_file_->IsValid(); }
    bool                  IsEof() const { return IsOpen() && (read_pos_ == mapped_file_->GetFileSize()); }
    bool IsError() const { return IsOpen() && ((read_pos_ < 0) || (read_pos_ > mapped_file_->GetFileSize())); }
    bool IsValid() const { return IsOpen() && !IsEof() && !IsError(); }

    bool Open(const std::string& filename);
    void Close();

    // Unlike FStream negative new locations are truncated to [0, file_size] (yes you can seek to eof)
    bool       FileSeek(int64_t offset, util::platform::FileSeekOrigin origin);
    bool       ReadBytes(void* buffer, size_t bytes);
    MappedSpan ReadSpan(const size_t bytes);

    explicit operator bool() const { return IsOpen(); }

  protected:
    bool InCurrentView(const MappedRange& range) { return current_view_.get() && current_view_->Contains(range); }
    MappedRange SetupForRead(size_t bytes);
    // This will update the current_view_ to include the access_offset
    // *ONLY* call it if !InCurrentView
    void UpdateCurrentView(const MappedRange& range);

    MappedFile::MappedFilePtr mapped_file_;
    MappedFile::MappedViewPtr current_view_;
    int64_t                   read_pos_;
    static constexpr size_t   kMib      = 1u << 20;
    static constexpr size_t   kViewSize = 32 * kMib;
};

class FStreamFileInputStream
{
  public:
    constexpr static bool HasReadSpanSupport() { return false; }
    std::string           GetFilename() const { return filename_; }

    bool IsOpen() const { return fd_ != nullptr; }
    bool IsEof() const { return IsOpen() && (feof(fd_) != 0); }
    bool IsError() const { return IsOpen() && (ferror(fd_) != 0); }
    bool IsValid() const { return IsOpen() && !IsEof() && !IsError(); }

    bool Open(const std::string& filename);
    void Close();
    bool FileSeek(int64_t offset, util::platform::FileSeekOrigin origin);
    bool ReadBytes(void* buffer, size_t bytes);
    // NOTE: ReadSpan is not supported in FStreamFileInputStream, a SFINAE to eliminate it from cross referencing
    // MappedSpan would be cleaner
    MappedSpan ReadSpan(const size_t bytes) { return MappedSpan(); }

    explicit operator bool() const { return IsOpen(); }

  protected:
    std::string filename_;
    FILE*       fd_{ nullptr };
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_FILE_INPUT_STREAM_H
