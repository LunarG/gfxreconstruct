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

#ifndef GFXRECON_INFO_API_GENERATOR_H
#define GFXRECON_INFO_API_GENERATOR_H

#include "decode/file_processor.h"
#include "format/format.h"
#include "util/argument_parser.h"
#include "util/defines.h"

#include "info_writer.h"

#include <nlohmann/json.hpp>

#include <functional>
#include <iomanip>
#include <memory>
#include <sstream>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

class InfoApiGenerator
{
  public:
    // Static methods for handling an automatic mechanism for registering
    // child classes with this base class.

    // Define a method that can be used casts a child unique_ptr to parent
    // so it can be included in a std::vector we'll call the registry.
    using BaseApiGeneratorPtr = std::function<std::unique_ptr<InfoApiGenerator>()>;
    static void RegisterGenerator(BaseApiGeneratorPtr gen_ptr) { GetRegisteredGenerators().push_back(gen_ptr); }
    static std::vector<BaseApiGeneratorPtr>& GetRegisteredGenerators()
    {
        static std::vector<BaseApiGeneratorPtr> registered_Generators_;
        return registered_Generators_;
    }

    enum class OutputSelectionFlags : std::uint32_t
    {
        kNoInfo          = 0x00000000,
        kFileInfo        = 0x00000001,
        kExeInfo         = 0x00000002,
        kEnvironmentInfo = 0x00000004,
        kApiAgnosticInfo = 0x00000008,
        kApiGeneralInfo  = 0x00000010,

        kDefaultInfo = kApiAgnosticInfo | kApiGeneralInfo,

        // API-specific reserved section
        kApiSpecific_Begin = 0x00010000,
        kApiSpecific_1     = kApiSpecific_Begin, // Reserved and used
        kApiSpecific_2     = kApiSpecific_Begin | 0x0001,
        kApiSpecific_3     = kApiSpecific_Begin | 0x0002,
        kApiSpecific_4     = kApiSpecific_Begin | 0x0004,
        kApiSpecific_5     = kApiSpecific_Begin | 0x0008,
        kApiSpecific_6     = kApiSpecific_Begin | 0x0010,
        kApiSpecific_7     = kApiSpecific_Begin | 0x0020,
        kApiSpecific_8     = kApiSpecific_Begin | 0x0040,
        kApiSpecific_9     = kApiSpecific_Begin | 0x0080,

        kAllInfo = 0xFFFFFFFF,

        // We require API info if not outputting only file, exe, and/or environment info.
        kRequiresApiInfo = (kAllInfo & ~(kFileInfo | kExeInfo | kEnvironmentInfo))
    };

    virtual ~InfoApiGenerator() = default;

    // Simple "getter" style methods
    virtual format::ApiFamilyId ApiFamilyId() const = 0;
    virtual std::string         ApiLabel() const    = 0;
    virtual bool                ApiWasDetected()    = 0;
    virtual std::string         ApiCompiledHeaderVersionString() const { return ""; }
    virtual uint32_t            GetBlankFrameCount() const { return 0; }
    virtual uint32_t            GetFrameStart() const { return 0; }
    virtual bool                ApiDesiresSingleLineFrameOutput() const { return false; }

    // A few "setter" style methods
    void         SetWriter(InfoWriter* writer) { info_writer_ = writer; }
    virtual void SetFrameMarkerUsage(bool uses) { uses_frame_markers_ = uses; }
    virtual void SetDriverInfoString(const std::string& driver_info) { driver_info_ = driver_info; }

    // API-specific command-line methods (default is do nothing and return true if required)
    virtual void UpdateValidCommandLineOptionsArgs(std::string& options, std::string& arguments)
    {
        GFXRECON_UNREFERENCED_PARAMETER(options);
        GFXRECON_UNREFERENCED_PARAMETER(arguments);
    }
    virtual void OutputCommandLineUsage() {}
    virtual bool CheckCommandLine(gfxrecon::util::ArgumentParser* arg_parser)
    {
        GFXRECON_UNREFERENCED_PARAMETER(arg_parser);
        return true;
    }

    // Method to register this API's decoder elements with the containers
    // FileProcessor
    virtual void RegisterApiDecodeComponents(gfxrecon::decode::FileProcessor& file_processor) = 0;

    // Output methods
    void                   SetOutputFlags(OutputSelectionFlags flags) { output_flags_ = flags; }
    virtual void           PrintInfo()    = 0;
    virtual nlohmann::json GenerateJson() = 0;

  protected:
    inline void WriteOutput(const std::string& message) { info_writer_->Print(message); }

    OutputSelectionFlags output_flags_{ OutputSelectionFlags::kDefaultInfo };
    bool                 uses_frame_markers_{ false };
    std::string          driver_info_;
    InfoWriter*          info_writer_{ nullptr };
};

constexpr InfoApiGenerator::OutputSelectionFlags operator|(InfoApiGenerator::OutputSelectionFlags a,
                                                           InfoApiGenerator::OutputSelectionFlags b)
{
    return static_cast<InfoApiGenerator::OutputSelectionFlags>(static_cast<uint32_t>(a) | static_cast<uint32_t>(b));
}

constexpr InfoApiGenerator::OutputSelectionFlags operator&(InfoApiGenerator::OutputSelectionFlags a,
                                                           InfoApiGenerator::OutputSelectionFlags b)
{
    return static_cast<InfoApiGenerator::OutputSelectionFlags>(static_cast<uint32_t>(a) & static_cast<uint32_t>(b));
}

constexpr InfoApiGenerator::OutputSelectionFlags operator^(InfoApiGenerator::OutputSelectionFlags a,
                                                           InfoApiGenerator::OutputSelectionFlags b)
{
    return static_cast<InfoApiGenerator::OutputSelectionFlags>(static_cast<uint32_t>(a) ^ static_cast<uint32_t>(b));
}

constexpr InfoApiGenerator::OutputSelectionFlags operator~(InfoApiGenerator::OutputSelectionFlags a)
{
    return static_cast<InfoApiGenerator::OutputSelectionFlags>(~static_cast<uint32_t>(a));
}

constexpr InfoApiGenerator::OutputSelectionFlags& operator|=(InfoApiGenerator::OutputSelectionFlags& a,
                                                             InfoApiGenerator::OutputSelectionFlags  b)
{
    a = a | b;
    return a;
}

constexpr InfoApiGenerator::OutputSelectionFlags& operator&=(InfoApiGenerator::OutputSelectionFlags& a,
                                                             InfoApiGenerator::OutputSelectionFlags  b)
{
    a = a & b;
    return a;
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INFO_API_GENERATOR_H
