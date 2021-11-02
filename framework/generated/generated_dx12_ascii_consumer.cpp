/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

/*
** This file is generated from dx12_ascii_consumer_body_generator.py.
**
*/

#include "generated_dx12_ascii_consumer.h"
#include "generated_dx12_convert_to_texts.h"
#include "decode/custom_dx12_struct_ascii_consumers.h"
#include "decode/dx12_enum_util.h"
#include "util/interception/injection.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_FRAME_STATISTICS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_FRAME_STATISTICS{\n";
    oss << indent2 << value->decoded_value->PresentCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PresentRefreshCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SyncRefreshCount;
    oss << ",\n";

    oss << indent2 << value->SyncQPCTime->decoded_value->QuadPart;
    oss << ",\n";

    oss << indent2 << value->SyncGPUTime->decoded_value->QuadPart;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_MAPPED_RECT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_MAPPED_RECT{\n";
    oss << indent2 << value->decoded_value->Pitch;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pBits, indent2.c_str()))
    {
        oss << indent2 << *value->pBits.GetPointer();
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_LUID* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "LUID{\n";
    oss << indent2 << value->decoded_value->LowPart;
    oss << ",\n";

    oss << indent2 << value->decoded_value->HighPart;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_ADAPTER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_ADAPTER_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Description, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Description.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->VendorId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DeviceId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SubSysId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Revision;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedVideoMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedSystemMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SharedSystemMemory;
    oss << ",\n";

    WriteStructString(oss, value->AdapterLuid, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTPUT_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTPUT_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->DeviceName, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->DeviceName.GetPointer()) << "\"";
    }
    oss << ",\n";

    WriteStructString(oss, value->DesktopCoordinates, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->AttachedToDesktop, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Rotation);
    oss << ",\n";

    oss << indent2 << value->Monitor;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SHARED_RESOURCE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SHARED_RESOURCE{\n";
    oss << indent2 << value->Handle;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SURFACE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SURFACE_DESC{\n";
    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SWAP_CHAIN_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SWAP_CHAIN_DESC{\n";
    WriteStructString(oss, value->BufferDesc, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->BufferUsage;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BufferCount;
    oss << ",\n";

    oss << indent2 << value->OutputWindow;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Windowed, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SwapEffect);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Flags;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_ADAPTER_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_ADAPTER_DESC1{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Description, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Description.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->VendorId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DeviceId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SubSysId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Revision;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedVideoMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedSystemMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SharedSystemMemory;
    oss << ",\n";

    WriteStructString(oss, value->AdapterLuid, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->Flags;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_DISPLAY_COLOR_SPACE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_DISPLAY_COLOR_SPACE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->PrimaryCoordinates, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->PrimaryCoordinates, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->WhitePoints, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->WhitePoints, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTDUPL_MOVE_RECT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTDUPL_MOVE_RECT{\n";
    WriteStructString(oss, value->SourcePoint, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DestinationRect, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTDUPL_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTDUPL_DESC{\n";
    WriteStructString(oss, value->ModeDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Rotation);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->DesktopImageInSystemMemory, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTDUPL_POINTER_POSITION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTDUPL_POINTER_POSITION{\n";
    WriteStructString(oss, value->Position, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Visible, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTDUPL_POINTER_SHAPE_INFO{\n";
    oss << indent2 << value->decoded_value->Type;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Pitch;
    oss << ",\n";

    WriteStructString(oss, value->HotSpot, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTDUPL_FRAME_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTDUPL_FRAME_INFO{\n";
    oss << indent2 << value->LastPresentTime->decoded_value->QuadPart;
    oss << ",\n";

    oss << indent2 << value->LastMouseUpdateTime->decoded_value->QuadPart;
    oss << ",\n";

    oss << indent2 << value->decoded_value->AccumulatedFrames;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->RectsCoalesced, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->ProtectedContentMaskedOut, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->PointerPosition, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->TotalMetadataBufferSize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PointerShapeBufferSize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_MODE_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_MODE_DESC1{\n";
    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    WriteStructString(oss, value->RefreshRate, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ScanlineOrdering);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Scaling);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Stereo, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SWAP_CHAIN_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SWAP_CHAIN_DESC1{\n";
    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Stereo, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->BufferUsage;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BufferCount;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Scaling);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SwapEffect);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AlphaMode);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Flags;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SWAP_CHAIN_FULLSCREEN_DESC{\n";
    WriteStructString(oss, value->RefreshRate, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ScanlineOrdering);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Scaling);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Windowed, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_PRESENT_PARAMETERS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_PRESENT_PARAMETERS{\n";
    oss << indent2 << value->decoded_value->DirtyRectsCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pDirtyRects, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pDirtyRects, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pScrollRect, indent2.c_str()))
    {
        WriteStructString(oss, value->pScrollRect->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pScrollOffset, indent2.c_str()))
    {
        WriteStructString(oss, value->pScrollOffset->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_ADAPTER_DESC2* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_ADAPTER_DESC2{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Description, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Description.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->VendorId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DeviceId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SubSysId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Revision;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedVideoMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedSystemMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SharedSystemMemory;
    oss << ",\n";

    WriteStructString(oss, value->AdapterLuid, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->Flags;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->GraphicsPreemptionGranularity);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ComputePreemptionGranularity);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_MATRIX_3X2_F* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_MATRIX_3X2_F{\n";
    oss << indent2 << value->decoded_value->_11;
    oss << ",\n";

    oss << indent2 << value->decoded_value->_12;
    oss << ",\n";

    oss << indent2 << value->decoded_value->_21;
    oss << ",\n";

    oss << indent2 << value->decoded_value->_22;
    oss << ",\n";

    oss << indent2 << value->decoded_value->_31;
    oss << ",\n";

    oss << indent2 << value->decoded_value->_32;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_DECODE_SWAP_CHAIN_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_DECODE_SWAP_CHAIN_DESC{\n";
    oss << indent2 << value->decoded_value->Flags;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_FRAME_STATISTICS_MEDIA* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_FRAME_STATISTICS_MEDIA{\n";
    oss << indent2 << value->decoded_value->PresentCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PresentRefreshCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SyncRefreshCount;
    oss << ",\n";

    oss << indent2 << value->SyncQPCTime->decoded_value->QuadPart;
    oss << ",\n";

    oss << indent2 << value->SyncGPUTime->decoded_value->QuadPart;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->CompositionMode);
    oss << ",\n";

    oss << indent2 << value->decoded_value->ApprovedPresentDuration;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_QUERY_VIDEO_MEMORY_INFO{\n";
    oss << indent2 << value->decoded_value->Budget;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CurrentUsage;
    oss << ",\n";

    oss << indent2 << value->decoded_value->AvailableForReservation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CurrentReservation;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_HDR_METADATA_HDR10* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_HDR_METADATA_HDR10{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->RedPrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->RedPrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->GreenPrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->GreenPrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->BluePrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->BluePrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->WhitePoint, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->WhitePoint, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxMasteringLuminance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinMasteringLuminance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxContentLightLevel;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxFrameAverageLightLevel;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_HDR_METADATA_HDR10PLUS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_HDR_METADATA_HDR10PLUS{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Data, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->Data, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_ADAPTER_DESC3* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_ADAPTER_DESC3{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Description, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Description.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->VendorId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DeviceId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SubSysId;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Revision;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedVideoMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DedicatedSystemMemory;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SharedSystemMemory;
    oss << ",\n";

    WriteStructString(oss, value->AdapterLuid, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->GraphicsPreemptionGranularity);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ComputePreemptionGranularity);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_OUTPUT_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_OUTPUT_DESC1{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->DeviceName, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->DeviceName.GetPointer()) << "\"";
    }
    oss << ",\n";

    WriteStructString(oss, value->DesktopCoordinates, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->AttachedToDesktop, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Rotation);
    oss << ",\n";

    oss << indent2 << value->Monitor;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BitsPerColor;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ColorSpace);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->RedPrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->RedPrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->GreenPrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->GreenPrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->BluePrimary, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->BluePrimary, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->WhitePoint, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->WhitePoint, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinLuminance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxLuminance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxFullFrameLuminance;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_RATIONAL* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_RATIONAL{\n";
    oss << indent2 << value->decoded_value->Numerator;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Denominator;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_SAMPLE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_SAMPLE_DESC{\n";
    oss << indent2 << value->decoded_value->Count;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Quality;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_RGB* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_RGB{\n";
    oss << indent2 << value->decoded_value->Red;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Green;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Blue;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3DCOLORVALUE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3DCOLORVALUE{\n";
    oss << indent2 << value->decoded_value->r;
    oss << ",\n";

    oss << indent2 << value->decoded_value->g;
    oss << ",\n";

    oss << indent2 << value->decoded_value->b;
    oss << ",\n";

    oss << indent2 << value->decoded_value->a;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_GAMMA_CONTROL* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_GAMMA_CONTROL{\n";
    WriteStructString(oss, value->Scale, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->Offset, indent2.c_str());
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->GammaCurve, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->GammaCurve, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_GAMMA_CONTROL_CAPABILITIES{\n";
    WriteBOOLString(oss, value->decoded_value->ScaleAndOffsetSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxConvertedValue;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinConvertedValue;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumGammaControlPoints;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->ControlPointPositions, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->ControlPointPositions, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_MODE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_MODE_DESC{\n";
    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    WriteStructString(oss, value->RefreshRate, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ScanlineOrdering);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Scaling);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_JPEG_DC_HUFFMAN_TABLE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_JPEG_DC_HUFFMAN_TABLE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->CodeCounts, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->CodeCounts, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->CodeValues, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->CodeValues, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_JPEG_AC_HUFFMAN_TABLE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_JPEG_AC_HUFFMAN_TABLE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->CodeCounts, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->CodeCounts, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->CodeValues, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->CodeValues, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_DXGI_JPEG_QUANTIZATION_TABLE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "DXGI_JPEG_QUANTIZATION_TABLE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Elements, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->Elements, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_COMMAND_QUEUE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_COMMAND_QUEUE_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Priority;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_INPUT_ELEMENT_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INPUT_ELEMENT_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->SemanticName, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->SemanticName.GetPointer() << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->SemanticIndex;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << value->decoded_value->InputSlot;
    oss << ",\n";

    oss << indent2 << value->decoded_value->AlignedByteOffset;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->InputSlotClass);
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceDataStepRate;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SO_DECLARATION_ENTRY* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SO_DECLARATION_ENTRY{\n";
    oss << indent2 << value->decoded_value->Stream;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->SemanticName, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->SemanticName.GetPointer() << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->SemanticIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartComponent;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ComponentCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->OutputSlot;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_VIEWPORT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VIEWPORT{\n";
    oss << indent2 << value->decoded_value->TopLeftX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->TopLeftY;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinDepth;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxDepth;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BOX* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BOX{\n";
    oss << indent2 << value->decoded_value->left;
    oss << ",\n";

    oss << indent2 << value->decoded_value->top;
    oss << ",\n";

    oss << indent2 << value->decoded_value->front;
    oss << ",\n";

    oss << indent2 << value->decoded_value->right;
    oss << ",\n";

    oss << indent2 << value->decoded_value->bottom;
    oss << ",\n";

    oss << indent2 << value->decoded_value->back;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEPTH_STENCILOP_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEPTH_STENCILOP_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->StencilFailOp);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->StencilDepthFailOp);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->StencilPassOp);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->StencilFunc);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEPTH_STENCIL_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEPTH_STENCIL_DESC{\n";
    WriteBOOLString(oss, value->decoded_value->DepthEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DepthWriteMask);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DepthFunc);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->StencilEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->StencilReadMask);
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->StencilWriteMask);
    oss << ",\n";

    WriteStructString(oss, value->FrontFace, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->BackFace, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEPTH_STENCIL_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEPTH_STENCIL_DESC1{\n";
    WriteBOOLString(oss, value->decoded_value->DepthEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DepthWriteMask);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DepthFunc);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->StencilEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->StencilReadMask);
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->StencilWriteMask);
    oss << ",\n";

    WriteStructString(oss, value->FrontFace, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->BackFace, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->DepthBoundsTestEnable, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_TARGET_BLEND_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_TARGET_BLEND_DESC{\n";
    WriteBOOLString(oss, value->decoded_value->BlendEnable, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->LogicOpEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SrcBlend);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DestBlend);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->BlendOp);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SrcBlendAlpha);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DestBlendAlpha);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->BlendOpAlpha);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->LogicOp);
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->RenderTargetWriteMask);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BLEND_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BLEND_DESC{\n";
    WriteBOOLString(oss, value->decoded_value->AlphaToCoverageEnable, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->IndependentBlendEnable, indent2.c_str());
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->RenderTarget, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->RenderTarget, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RASTERIZER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RASTERIZER_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->FillMode);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->CullMode);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->FrontCounterClockwise, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthBias;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthBiasClamp;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SlopeScaledDepthBias;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->DepthClipEnable, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->MultisampleEnable, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->AntialiasedLineEnable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->ForcedSampleCount;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ConservativeRaster);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SHADER_BYTECODE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SHADER_BYTECODE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->pShaderBytecode, indent2.c_str()))
    {
        oss << indent2 << "pShaderBytecode" << " /* value = " << static_cast<uint16_t>(*value->pShaderBytecode.GetPointer()) << " */";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->BytecodeLength;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_STREAM_OUTPUT_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STREAM_OUTPUT_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, value->pSODeclaration, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pSODeclaration, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumEntries;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pBufferStrides, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->pBufferStrides, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumStrides;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RasterizedStream;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_INPUT_LAYOUT_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INPUT_LAYOUT_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, value->pInputElementDescs, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pInputElementDescs, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumElements;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_CACHED_PIPELINE_STATE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_CACHED_PIPELINE_STATE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->pCachedBlob, indent2.c_str()))
    {
        oss << indent2 << "pCachedBlob" << " /* value = " << static_cast<uint16_t>(*value->pCachedBlob.GetPointer()) << " */";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->CachedBlobSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GRAPHICS_PIPELINE_STATE_DESC{\n";
    WriteHandleId(oss, value->pRootSignature, indent2.c_str(), "ID3D12RootSignature");
    oss << ",\n";

    WriteStructString(oss, value->VS, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->PS, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DS, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->HS, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->GS, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->StreamOutput, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->BlendState, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->SampleMask;
    oss << ",\n";

    WriteStructString(oss, value->RasterizerState, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DepthStencilState, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->InputLayout, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->IBStripCutValue);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->PrimitiveTopologyType);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumRenderTargets;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->RTVFormats, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->RTVFormats, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DSVFormat);
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << ",\n";

    WriteStructString(oss, value->CachedPSO, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_COMPUTE_PIPELINE_STATE_DESC{\n";
    WriteHandleId(oss, value->pRootSignature, indent2.c_str(), "ID3D12RootSignature");
    oss << ",\n";

    WriteStructString(oss, value->CS, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << ",\n";

    WriteStructString(oss, value->CachedPSO, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RT_FORMAT_ARRAY* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RT_FORMAT_ARRAY{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->RTFormats, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->RTFormats, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumRenderTargets;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS{\n";
    WriteBOOLString(oss, value->decoded_value->DoublePrecisionFloatShaderOps, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->OutputMergerLogicOp, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->MinPrecisionSupport);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->TiledResourcesTier);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ResourceBindingTier);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->PSSpecifiedStencilRefSupported, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->TypedUAVLoadAdditionalFormats, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->ROVsSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ConservativeRasterizationTier);
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxGPUVirtualAddressBitsPerResource;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->StandardSwizzle64KBSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->CrossNodeSharingTier);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->CrossAdapterRowMajorTextureSupported, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ResourceHeapTier);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS1{\n";
    WriteBOOLString(oss, value->decoded_value->WaveOps, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->WaveLaneCountMin;
    oss << ",\n";

    oss << indent2 << value->decoded_value->WaveLaneCountMax;
    oss << ",\n";

    oss << indent2 << value->decoded_value->TotalLaneCount;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->ExpandedComputeResourceStates, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Int64ShaderOps, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS2* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS2{\n";
    WriteBOOLString(oss, value->decoded_value->DepthBoundsTestSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ProgrammableSamplePositionsTier);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_ROOT_SIGNATURE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_ROOT_SIGNATURE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->HighestVersion);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_ARCHITECTURE{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->TileBasedRenderer, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->UMA, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->CacheCoherentUMA, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_ARCHITECTURE1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_ARCHITECTURE1{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->TileBasedRenderer, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->UMA, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->CacheCoherentUMA, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->IsolatedMMU, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_FEATURE_LEVELS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_FEATURE_LEVELS{\n";
    oss << indent2 << value->decoded_value->NumFeatureLevels;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pFeatureLevelsRequested, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pFeatureLevelsRequested, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->MaxSupportedFeatureLevel);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_SHADER_MODEL* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_SHADER_MODEL{\n";
    oss << indent2 << ConverttoText(value->decoded_value->HighestShaderModel);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_FORMAT_SUPPORT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_FORMAT_SUPPORT{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Support1);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Support2);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << value->decoded_value->SampleCount;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumQualityLevels;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_FORMAT_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_FORMAT_INFO{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->PlaneCount);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT{\n";
    oss << indent2 << value->decoded_value->MaxGPUVirtualAddressBitsPerResource;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxGPUVirtualAddressBitsPerProcess;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_SHADER_CACHE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_SHADER_CACHE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->SupportFlags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY{\n";
    oss << indent2 << ConverttoText(value->decoded_value->CommandListType);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Priority;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->PriorityForTypeIsSupported, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS3* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS3{\n";
    WriteBOOLString(oss, value->decoded_value->CopyQueueTimestampQueriesSupported, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->CastingFullyTypedFormatSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->WriteBufferImmediateSupportFlags);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ViewInstancingTier);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->BarycentricsSupported, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_EXISTING_HEAPS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_EXISTING_HEAPS{\n";
    WriteBOOLString(oss, value->decoded_value->Supported, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS4* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS4{\n";
    WriteBOOLString(oss, value->decoded_value->MSAA64KBAlignedTextureSupported, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SharedResourceCompatibilityTier);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->Native16BitShaderOpsSupported, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_SERIALIZATION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_SERIALIZATION{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->HeapSerializationTier);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_CROSS_NODE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_CROSS_NODE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->SharingTier);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->AtomicShaderInstructions, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS5* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS5{\n";
    WriteBOOLString(oss, value->decoded_value->SRVOnlyTiledResourceTier3, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->RenderPassesTier);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->RaytracingTier);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS6* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS6{\n";
    WriteBOOLString(oss, value->decoded_value->AdditionalShadingRatesSupported, indent2.c_str());
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->PerPrimitiveShadingRateSupportedWithViewportIndexing, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->VariableShadingRateTier);
    oss << ",\n";

    oss << indent2 << value->decoded_value->ShadingRateImageTileSize;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->BackgroundProcessingSupported, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_D3D12_OPTIONS7* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_D3D12_OPTIONS7{\n";
    oss << indent2 << ConverttoText(value->decoded_value->MeshShaderTier);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->SamplerFeedbackTier);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_QUERY_META_COMMAND* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_QUERY_META_COMMAND{\n";
    oss << indent2 << ConverttoText(*value->CommandId->decoded_value);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pQueryInputData, indent2.c_str()))
    {
        oss << indent2 << "pQueryInputData" << " /* value = " << static_cast<uint16_t>(*value->pQueryInputData.GetPointer()) << " */";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->QueryInputDataSizeInBytes;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pQueryOutputData, indent2.c_str()))
    {
        oss << indent2 << "pQueryOutputData" << " /* value = " << static_cast<uint16_t>(*value->pQueryOutputData.GetPointer()) << " */";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->QueryOutputDataSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_ALLOCATION_INFO{\n";
    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Alignment;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_ALLOCATION_INFO1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_ALLOCATION_INFO1{\n";
    oss << indent2 << value->decoded_value->Offset;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Alignment;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_HEAP_PROPERTIES* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_HEAP_PROPERTIES{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->CPUPageProperty);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->MemoryPoolPreference);
    oss << ",\n";

    oss << indent2 << value->decoded_value->CreationNodeMask;
    oss << ",\n";

    oss << indent2 << value->decoded_value->VisibleNodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_HEAP_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_HEAP_DESC{\n";
    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    WriteStructString(oss, value->Properties, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->Alignment;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_MIP_REGION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_MIP_REGION{\n";
    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Depth;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Dimension);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Alignment;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthOrArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Layout);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_DESC1{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Dimension);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Alignment;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthOrArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    WriteStructString(oss, value->SampleDesc, indent2.c_str());
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Layout);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    WriteStructString(oss, value->SamplerFeedbackMipRegion, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEPTH_STENCIL_VALUE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEPTH_STENCIL_VALUE{\n";
    oss << indent2 << value->decoded_value->Depth;
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->Stencil);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RANGE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RANGE{\n";
    oss << indent2 << value->decoded_value->Begin;
    oss << ",\n";

    oss << indent2 << value->decoded_value->End;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RANGE_UINT64* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RANGE_UINT64{\n";
    oss << indent2 << value->decoded_value->Begin;
    oss << ",\n";

    oss << indent2 << value->decoded_value->End;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SUBRESOURCE_RANGE_UINT64* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBRESOURCE_RANGE_UINT64{\n";
    oss << indent2 << value->decoded_value->Subresource;
    oss << ",\n";

    WriteStructString(oss, value->Range, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SUBRESOURCE_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBRESOURCE_INFO{\n";
    oss << indent2 << value->decoded_value->Offset;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RowPitch;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthPitch;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TILED_RESOURCE_COORDINATE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TILED_RESOURCE_COORDINATE{\n";
    oss << indent2 << value->decoded_value->X;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Y;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Z;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Subresource;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TILE_REGION_SIZE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TILE_REGION_SIZE{\n";
    oss << indent2 << value->decoded_value->NumTiles;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->UseBox, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Depth;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SUBRESOURCE_TILING* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBRESOURCE_TILING{\n";
    oss << indent2 << value->decoded_value->WidthInTiles;
    oss << ",\n";

    oss << indent2 << value->decoded_value->HeightInTiles;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthInTiles;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartTileIndexInOverallResource;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TILE_SHAPE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TILE_SHAPE{\n";
    oss << indent2 << value->decoded_value->WidthInTexels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->HeightInTexels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DepthInTexels;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_PACKED_MIP_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_PACKED_MIP_INFO{\n";
    oss << indent2 << static_cast<uint16_t>(value->decoded_value->NumStandardMips);
    oss << ",\n";

    oss << indent2 << static_cast<uint16_t>(value->decoded_value->NumPackedMips);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumTilesForPackedMips;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartTileIndexInOverallResource;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_TRANSITION_BARRIER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_TRANSITION_BARRIER{\n";
    WriteHandleId(oss, value->pResource, indent2.c_str(), "ID3D12Resource");
    oss << ",\n";

    oss << indent2 << value->decoded_value->Subresource;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->StateBefore);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->StateAfter);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_ALIASING_BARRIER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_ALIASING_BARRIER{\n";
    WriteHandleId(oss, value->pResourceBefore, indent2.c_str(), "ID3D12Resource");
    oss << ",\n";

    WriteHandleId(oss, value->pResourceAfter, indent2.c_str(), "ID3D12Resource");
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RESOURCE_UAV_BARRIER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RESOURCE_UAV_BARRIER{\n";
    WriteHandleId(oss, value->pResource, indent2.c_str(), "ID3D12Resource");
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SUBRESOURCE_FOOTPRINT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBRESOURCE_FOOTPRINT{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Depth;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RowPitch;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_PLACED_SUBRESOURCE_FOOTPRINT{\n";
    oss << indent2 << value->decoded_value->Offset;
    oss << ",\n";

    WriteStructString(oss, value->Footprint, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SAMPLE_POSITION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SAMPLE_POSITION{\n";
    oss << indent2 << static_cast<int16_t>(value->decoded_value->X);
    oss << ",\n";

    oss << indent2 << static_cast<int16_t>(value->decoded_value->Y);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_VIEW_INSTANCE_LOCATION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VIEW_INSTANCE_LOCATION{\n";
    oss << indent2 << value->decoded_value->ViewportArrayIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RenderTargetArrayIndex;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_VIEW_INSTANCING_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VIEW_INSTANCING_DESC{\n";
    oss << indent2 << value->decoded_value->ViewInstanceCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pViewInstanceLocations, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pViewInstanceLocations, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BUFFER_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUFFER_SRV{\n";
    oss << indent2 << value->decoded_value->FirstElement;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumElements;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StructureByteStride;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_ARRAY_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_ARRAY_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_ARRAY_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_ARRAY_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX3D_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX3D_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEXCUBE_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEXCUBE_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEXCUBE_ARRAY_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEXCUBE_ARRAY_SRV{\n";
    oss << indent2 << value->decoded_value->MostDetailedMip;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLevels;
    oss << ",\n";

    oss << indent2 << value->decoded_value->First2DArrayFace;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumCubes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ResourceMinLODClamp;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_SRV{\n";
    oss << indent2 << value->decoded_value->UnusedField_NothingToDefine;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_ARRAY_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_ARRAY_SRV{\n";
    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV{\n";
    oss << indent2 << value->decoded_value->Location;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_CONSTANT_BUFFER_VIEW_DESC{\n";
    oss << indent2 << value->decoded_value->BufferLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SAMPLER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SAMPLER_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Filter);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressU);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressV);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressW);
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLODBias;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxAnisotropy;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ComparisonFunc);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->BorderColor, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->BorderColor, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinLOD;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxLOD;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BUFFER_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUFFER_UAV{\n";
    oss << indent2 << value->decoded_value->FirstElement;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumElements;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StructureByteStride;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CounterOffsetInBytes;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_UAV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_ARRAY_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_ARRAY_UAV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_UAV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_ARRAY_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_ARRAY_UAV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX3D_UAV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX3D_UAV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstWSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->WSize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BUFFER_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUFFER_RTV{\n";
    oss << indent2 << value->decoded_value->FirstElement;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumElements;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_RTV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_ARRAY_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_ARRAY_RTV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_RTV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_RTV{\n";
    oss << indent2 << value->decoded_value->UnusedField_NothingToDefine;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_ARRAY_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_ARRAY_RTV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PlaneSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_ARRAY_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_ARRAY_RTV{\n";
    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX3D_RTV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX3D_RTV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstWSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->WSize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_DSV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX1D_ARRAY_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX1D_ARRAY_DSV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_DSV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2D_ARRAY_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2D_ARRAY_DSV{\n";
    oss << indent2 << value->decoded_value->MipSlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_DSV{\n";
    oss << indent2 << value->decoded_value->UnusedField_NothingToDefine;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_TEX2DMS_ARRAY_DSV* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_TEX2DMS_ARRAY_DSV{\n";
    oss << indent2 << value->decoded_value->FirstArraySlice;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ArraySize;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DESCRIPTOR_HEAP_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DESCRIPTOR_HEAP_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumDescriptors;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DESCRIPTOR_RANGE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DESCRIPTOR_RANGE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->RangeType);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumDescriptors;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BaseShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << ",\n";

    oss << indent2 << value->decoded_value->OffsetInDescriptorsFromTableStart;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_DESCRIPTOR_TABLE{\n";
    oss << indent2 << value->decoded_value->NumDescriptorRanges;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pDescriptorRanges, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pDescriptorRanges, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_CONSTANTS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_CONSTANTS{\n";
    oss << indent2 << value->decoded_value->ShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Num32BitValues;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_DESCRIPTOR* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_DESCRIPTOR{\n";
    oss << indent2 << value->decoded_value->ShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_STATIC_SAMPLER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STATIC_SAMPLER_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Filter);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressU);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressV);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AddressW);
    oss << ",\n";

    oss << indent2 << value->decoded_value->MipLODBias;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxAnisotropy;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ComparisonFunc);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->BorderColor);
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinLOD;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxLOD;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ShaderVisibility);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_SIGNATURE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_SIGNATURE_DESC{\n";
    oss << indent2 << value->decoded_value->NumParameters;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pParameters, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pParameters, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumStaticSamplers;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pStaticSamplers, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pStaticSamplers, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DESCRIPTOR_RANGE1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DESCRIPTOR_RANGE1{\n";
    oss << indent2 << ConverttoText(value->decoded_value->RangeType);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumDescriptors;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BaseShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << value->decoded_value->OffsetInDescriptorsFromTableStart;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_DESCRIPTOR_TABLE1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_DESCRIPTOR_TABLE1{\n";
    oss << indent2 << value->decoded_value->NumDescriptorRanges;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pDescriptorRanges, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pDescriptorRanges, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_DESCRIPTOR1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_DESCRIPTOR1{\n";
    oss << indent2 << value->decoded_value->ShaderRegister;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RegisterSpace;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_ROOT_SIGNATURE_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_ROOT_SIGNATURE_DESC1{\n";
    oss << indent2 << value->decoded_value->NumParameters;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pParameters, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pParameters, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumStaticSamplers;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pStaticSamplers, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pStaticSamplers, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GPU_DESCRIPTOR_HANDLE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GPU_DESCRIPTOR_HANDLE{\n";
    oss << indent2 << value->decoded_value->ptr;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DISCARD_REGION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DISCARD_REGION{\n";
    oss << indent2 << value->decoded_value->NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pRects, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pRects, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->FirstSubresource;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumSubresources;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_QUERY_HEAP_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_QUERY_HEAP_DESC{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->Count;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_QUERY_DATA_PIPELINE_STATISTICS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_QUERY_DATA_PIPELINE_STATISTICS{\n";
    oss << indent2 << value->decoded_value->IAVertices;
    oss << ",\n";

    oss << indent2 << value->decoded_value->IAPrimitives;
    oss << ",\n";

    oss << indent2 << value->decoded_value->VSInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->GSInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->GSPrimitives;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CPrimitives;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PSInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->HSInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DSInvocations;
    oss << ",\n";

    oss << indent2 << value->decoded_value->CSInvocations;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_QUERY_DATA_SO_STATISTICS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_QUERY_DATA_SO_STATISTICS{\n";
    oss << indent2 << value->decoded_value->NumPrimitivesWritten;
    oss << ",\n";

    oss << indent2 << value->decoded_value->PrimitivesStorageNeeded;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STREAM_OUTPUT_BUFFER_VIEW{\n";
    oss << indent2 << value->decoded_value->BufferLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BufferFilledSizeLocation;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRAW_ARGUMENTS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRAW_ARGUMENTS{\n";
    oss << indent2 << value->decoded_value->VertexCountPerInstance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartVertexLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartInstanceLocation;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRAW_INDEXED_ARGUMENTS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRAW_INDEXED_ARGUMENTS{\n";
    oss << indent2 << value->decoded_value->IndexCountPerInstance;
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartIndexLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BaseVertexLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StartInstanceLocation;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DISPATCH_ARGUMENTS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DISPATCH_ARGUMENTS{\n";
    oss << indent2 << value->decoded_value->ThreadGroupCountX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ThreadGroupCountY;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ThreadGroupCountZ;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_VERTEX_BUFFER_VIEW* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_VERTEX_BUFFER_VIEW{\n";
    oss << indent2 << value->decoded_value->BufferLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StrideInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_INDEX_BUFFER_VIEW* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INDEX_BUFFER_VIEW{\n";
    oss << indent2 << value->decoded_value->BufferLocation;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_COMMAND_SIGNATURE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_COMMAND_SIGNATURE_DESC{\n";
    oss << indent2 << value->decoded_value->ByteStride;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumArgumentDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pArgumentDescs, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pArgumentDescs, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_WRITEBUFFERIMMEDIATE_PARAMETER{\n";
    oss << indent2 << value->decoded_value->Dest;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Value;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Support);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_PROTECTED_RESOURCE_SESSION_DESC{\n";
    oss << indent2 << value->decoded_value->NodeMask;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_META_COMMAND_PARAMETER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_META_COMMAND_PARAMETER_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Name, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Name.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->RequiredResourceState);
    oss << ",\n";

    oss << indent2 << value->decoded_value->StructureOffset;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_META_COMMAND_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_META_COMMAND_DESC{\n";
    oss << indent2 << ConverttoText(*value->Id->decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->Name, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Name.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->InitializationDirtyState);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ExecutionDirtyState);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_STATE_OBJECT_CONFIG* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_STATE_OBJECT_CONFIG{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GLOBAL_ROOT_SIGNATURE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GLOBAL_ROOT_SIGNATURE{\n";
    WriteHandleId(oss, value->pGlobalRootSignature, indent2.c_str(), "ID3D12RootSignature");
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_LOCAL_ROOT_SIGNATURE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_LOCAL_ROOT_SIGNATURE{\n";
    WriteHandleId(oss, value->pLocalRootSignature, indent2.c_str(), "ID3D12RootSignature");
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_NODE_MASK* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_NODE_MASK{\n";
    oss << indent2 << value->decoded_value->NodeMask;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_EXPORT_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_EXPORT_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Name, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->Name.GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->ExportToRename, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->ExportToRename.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DXIL_LIBRARY_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DXIL_LIBRARY_DESC{\n";
    WriteStructString(oss, value->DXILLibrary, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumExports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pExports, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pExports, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_EXISTING_COLLECTION_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_EXISTING_COLLECTION_DESC{\n";
    WriteHandleId(oss, value->pExistingCollection, indent2.c_str(), "ID3D12StateObject");
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumExports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pExports, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pExports, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->SubobjectToAssociate, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->SubobjectToAssociate.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumExports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pExports, indent2.c_str()))
    {
        WriteArrayWStringsString(oss, &value->pExports, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_HIT_GROUP_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_HIT_GROUP_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->HitGroupExport, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->HitGroupExport.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->AnyHitShaderImport, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->AnyHitShaderImport.GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->ClosestHitShaderImport, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->ClosestHitShaderImport.GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->IntersectionShaderImport, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->IntersectionShaderImport.GetPointer()) << "\"";
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_SHADER_CONFIG* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_SHADER_CONFIG{\n";
    oss << indent2 << value->decoded_value->MaxPayloadSizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxAttributeSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_PIPELINE_CONFIG{\n";
    oss << indent2 << value->decoded_value->MaxTraceRecursionDepth;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_PIPELINE_CONFIG1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_PIPELINE_CONFIG1{\n";
    oss << indent2 << value->decoded_value->MaxTraceRecursionDepth;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE{\n";
    oss << indent2 << value->decoded_value->StartAddress;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StrideInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GPU_VIRTUAL_ADDRESS_RANGE{\n";
    oss << indent2 << value->decoded_value->StartAddress;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE{\n";
    oss << indent2 << value->decoded_value->StartAddress;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->StrideInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC{\n";
    oss << indent2 << value->decoded_value->Transform3x4;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->IndexFormat);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->VertexFormat);
    oss << ",\n";

    oss << indent2 << value->decoded_value->IndexCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->VertexCount;
    oss << ",\n";

    oss << indent2 << value->decoded_value->IndexBuffer;
    oss << ",\n";

    WriteStructString(oss, value->VertexBuffer, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_AABB* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_AABB{\n";
    oss << indent2 << value->decoded_value->MinX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinY;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MinZ;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxY;
    oss << ",\n";

    oss << indent2 << value->decoded_value->MaxZ;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_GEOMETRY_AABBS_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_GEOMETRY_AABBS_DESC{\n";
    oss << indent2 << value->decoded_value->AABBCount;
    oss << ",\n";

    WriteStructString(oss, value->AABBs, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC{\n";
    oss << indent2 << value->decoded_value->DestBuffer;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->InfoType);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC{\n";
    oss << indent2 << value->decoded_value->CompactedSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC{\n";
    oss << indent2 << value->decoded_value->DecodedSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Type);
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumDescs;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC{\n";
    oss << indent2 << value->decoded_value->SerializedSizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumBottomLevelAccelerationStructurePointers;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER{\n";
    oss << indent2 << ConverttoText(*value->DriverOpaqueGUID->decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->DriverOpaqueVersioningData, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->DriverOpaqueVersioningData, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER{\n";
    WriteStructString(oss, value->DriverMatchingIdentifier, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->SerializedSizeInBytesIncludingHeader;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DeserializedSizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumBottomLevelAccelerationStructurePointersAfterHeader;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC{\n";
    oss << indent2 << value->decoded_value->CurrentSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_INSTANCE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_INSTANCE_DESC{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Transform, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->Transform, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceID;
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceMask;
    oss << ",\n";

    oss << indent2 << value->decoded_value->InstanceContributionToHitGroupIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Flags;
    oss << ",\n";

    oss << indent2 << value->decoded_value->AccelerationStructure;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC{\n";
    oss << indent2 << value->decoded_value->DestAccelerationStructureData;
    oss << ",\n";

    WriteStructString(oss, value->Inputs, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->SourceAccelerationStructureData;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ScratchAccelerationStructureData;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO{\n";
    oss << indent2 << value->decoded_value->ResultDataMaxSizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ScratchDataSizeInBytes;
    oss << ",\n";

    oss << indent2 << value->decoded_value->UpdateScratchDataSizeInBytes;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_AUTO_BREADCRUMB_NODE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_AUTO_BREADCRUMB_NODE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->pCommandListDebugNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->pCommandListDebugNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandListDebugNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->pCommandListDebugNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandQueueDebugNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->pCommandQueueDebugNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandQueueDebugNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->pCommandQueueDebugNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    WriteHandleId(oss, value->pCommandList, indent2.c_str(), "ID3D12GraphicsCommandList");
    oss << ",\n";

    WriteHandleId(oss, value->pCommandQueue, indent2.c_str(), "ID3D12CommandQueue");
    oss << ",\n";

    oss << indent2 << value->decoded_value->BreadcrumbCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pLastBreadcrumbValue, indent2.c_str()))
    {
        oss << indent2 << *value->pLastBreadcrumbValue.GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandHistory, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pCommandHistory, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pNext, indent2.c_str()))
    {
        WriteStructString(oss, value->pNext->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_BREADCRUMB_CONTEXT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_BREADCRUMB_CONTEXT{\n";
    oss << indent2 << value->decoded_value->BreadcrumbIndex;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pContextString, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->pContextString.GetPointer()) << "\"";
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_AUTO_BREADCRUMB_NODE1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_AUTO_BREADCRUMB_NODE1{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->pCommandListDebugNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->pCommandListDebugNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandListDebugNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->pCommandListDebugNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandQueueDebugNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->pCommandQueueDebugNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandQueueDebugNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->pCommandQueueDebugNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    WriteHandleId(oss, value->pCommandList, indent2.c_str(), "ID3D12GraphicsCommandList");
    oss << ",\n";

    WriteHandleId(oss, value->pCommandQueue, indent2.c_str(), "ID3D12CommandQueue");
    oss << ",\n";

    oss << indent2 << value->decoded_value->BreadcrumbCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pLastBreadcrumbValue, indent2.c_str()))
    {
        oss << indent2 << *value->pLastBreadcrumbValue.GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCommandHistory, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pCommandHistory, indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pNext, indent2.c_str()))
    {
        WriteStructString(oss, value->pNext->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->BreadcrumbContextsCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pBreadcrumbContexts, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pBreadcrumbContexts, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEVICE_REMOVED_EXTENDED_DATA{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pHeadAutoBreadcrumbNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadAutoBreadcrumbNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_ALLOCATION_NODE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_ALLOCATION_NODE{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->ObjectNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->ObjectNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->ObjectNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->ObjectNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AllocationType);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pNext, indent2.c_str()))
    {
        WriteStructString(oss, value->pNext->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_ALLOCATION_NODE1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_ALLOCATION_NODE1{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->ObjectNameA, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->ObjectNameA.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->ObjectNameW, indent2.c_str()))
    {
        oss << indent2 << "\"" << util::interception::WideStringToString(value->ObjectNameW.GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->AllocationType);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pNext, indent2.c_str()))
    {
        WriteStructString(oss, value->pNext->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    WriteHandleId(oss, value->pObject, indent2.c_str(), "IUnknown");
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT{\n";
    if (WriteCheckPointerDecoderNull(oss, value->pHeadAutoBreadcrumbNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadAutoBreadcrumbNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1{\n";
    if (WriteCheckPointerDecoderNull(oss, value->pHeadAutoBreadcrumbNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadAutoBreadcrumbNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_PAGE_FAULT_OUTPUT{\n";
    oss << indent2 << value->decoded_value->PageFaultVA;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pHeadExistingAllocationNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadExistingAllocationNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pHeadRecentFreedAllocationNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadRecentFreedAllocationNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DRED_PAGE_FAULT_OUTPUT1{\n";
    oss << indent2 << value->decoded_value->PageFaultVA;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pHeadExistingAllocationNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadExistingAllocationNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pHeadRecentFreedAllocationNode, indent2.c_str()))
    {
        WriteStructString(oss, value->pHeadRecentFreedAllocationNode->GetMetaStructPointer(), indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEVICE_REMOVED_EXTENDED_DATA1{\n";
    oss << indent2 << enumutil::GetResultValueString(value->decoded_value->DeviceRemovedReason);
    oss << ",\n";

    WriteStructString(oss, value->AutoBreadcrumbsOutput, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->PageFaultOutput, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEVICE_REMOVED_EXTENDED_DATA2* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEVICE_REMOVED_EXTENDED_DATA2{\n";
    oss << indent2 << enumutil::GetResultValueString(value->decoded_value->DeviceRemovedReason);
    oss << ",\n";

    WriteStructString(oss, value->AutoBreadcrumbsOutput, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->PageFaultOutput, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Count;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES{\n";
    oss << indent2 << value->decoded_value->NodeIndex;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Count;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pTypes, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, value->pTypes, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_PROTECTED_RESOURCE_SESSION_DESC1{\n";
    oss << indent2 << value->decoded_value->NodeMask;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Flags);
    oss << ",\n";

    oss << indent2 << ConverttoText(*value->ProtectionType->decoded_value);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS{\n";
    WriteStructString(oss, value->ClearValue, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS{\n";
    oss << indent2 << value->decoded_value->SrcSubresource;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DstSubresource;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DstX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->DstY;
    oss << ",\n";

    WriteStructString(oss, value->SrcRect, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS{\n";
    WriteHandleId(oss, value->pSrcResource, indent2.c_str(), "ID3D12Resource");
    oss << ",\n";

    WriteHandleId(oss, value->pDstResource, indent2.c_str(), "ID3D12Resource");
    oss << ",\n";

    oss << indent2 << value->decoded_value->SubresourceCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, value->pSubresourceParameters, indent2.c_str()))
    {
        WriteArrayStructsString(oss, value->pSubresourceParameters, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Format);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ResolveMode);
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->PreserveResolveSource, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_RENDER_TARGET_DESC{\n";
    WriteStructString(oss, value->cpuDescriptor, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->BeginningAccess, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->EndingAccess, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_RENDER_PASS_DEPTH_STENCIL_DESC{\n";
    WriteStructString(oss, value->cpuDescriptor, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DepthBeginningAccess, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->StencilBeginningAccess, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DepthEndingAccess, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->StencilEndingAccess, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DISPATCH_RAYS_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DISPATCH_RAYS_DESC{\n";
    WriteStructString(oss, value->RayGenerationShaderRecord, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->MissShaderTable, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->HitGroupTable, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->CallableShaderTable, indent2.c_str());
    oss << ",\n";

    oss << indent2 << value->decoded_value->Width;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Height;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Depth;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_SUBRESOURCE_DATA* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_SUBRESOURCE_DATA{\n";
    oss << indent2 << value->pData;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RowPitch;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SlicePitch;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_MEMCPY_DEST* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_MEMCPY_DEST{\n";
    oss << indent2 << value->pData;
    oss << ",\n";

    oss << indent2 << value->decoded_value->RowPitch;
    oss << ",\n";

    oss << indent2 << value->decoded_value->SlicePitch;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DISPATCH_MESH_ARGUMENTS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DISPATCH_MESH_ARGUMENTS{\n";
    oss << indent2 << value->decoded_value->ThreadGroupCountX;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ThreadGroupCountY;
    oss << ",\n";

    oss << indent2 << value->decoded_value->ThreadGroupCountZ;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D_SHADER_MACRO* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D_SHADER_MACRO{\n";
    if (WriteCheckPointerDecoderNull(oss, &value->Name, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->Name.GetPointer() << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->Definition, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->Definition.GetPointer() << "\"";
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS{\n";
    oss << indent2 << value->decoded_value->MaxMessagesPerCommandList;
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->DefaultShaderPatchMode);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->PipelineStateCreateFlags);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR{\n";
    oss << indent2 << value->decoded_value->SlowdownFactor;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS{\n";
    oss << indent2 << ConverttoText(value->decoded_value->ShaderPatchMode);
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_MESSAGE* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_MESSAGE{\n";
    oss << indent2 << ConverttoText(value->decoded_value->Category);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->Severity);
    oss << ",\n";

    oss << indent2 << ConverttoText(value->decoded_value->ID);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pDescription, indent2.c_str()))
    {
        oss << indent2 << "\"" << value->pDescription.GetPointer() << "\"";
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->DescriptionByteLength;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_INFO_QUEUE_FILTER_DESC* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INFO_QUEUE_FILTER_DESC{\n";
    oss << indent2 << value->decoded_value->NumCategories;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pCategoryList, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pCategoryList, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumSeverities;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pSeverityList, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pSeverityList, indent2.c_str());
    }
    oss << ",\n";

    oss << indent2 << value->decoded_value->NumIDs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pIDList, indent2.c_str()))
    {
        WriteArrayConvertsString(oss, &value->pIDList, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_D3D12_INFO_QUEUE_FILTER* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "D3D12_INFO_QUEUE_FILTER{\n";
    WriteStructString(oss, value->AllowList, indent2.c_str());
    oss << ",\n";

    WriteStructString(oss, value->DenyList, indent2.c_str());
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_GUID* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "GUID{\n";
    oss << indent2 << value->decoded_value->Data1;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Data2;
    oss << ",\n";

    oss << indent2 << value->decoded_value->Data3;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->Data4, indent2.c_str()))
    {
        WriteArrayValuesString(oss, &value->Data4, indent2.c_str());
    }
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_tagRECT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "tagRECT{\n";
    oss << indent2 << value->decoded_value->left;
    oss << ",\n";

    oss << indent2 << value->decoded_value->top;
    oss << ",\n";

    oss << indent2 << value->decoded_value->right;
    oss << ",\n";

    oss << indent2 << value->decoded_value->bottom;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded_tagPOINT* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "tagPOINT{\n";
    oss << indent2 << value->decoded_value->x;
    oss << ",\n";

    oss << indent2 << value->decoded_value->y;
    oss << "}";

}

void WriteStructString(std::ostringstream& oss, const Decoded__SECURITY_ATTRIBUTES* value, const char* indent, const bool prefix, const bool output)
{
    std::string indent2 = indent;
    indent2.append("    ");
    std::string indent_first = indent;
    if (prefix)
    {
        indent_first = "   ";
    }
    std::string output_string = "";
    if (output)
    {
        output_string = "/* out */ ";
    }
    oss << indent_first << output_string << "_SECURITY_ATTRIBUTES{\n";
    oss << indent2 << value->decoded_value->nLength;
    oss << ",\n";

    oss << indent2 << value->lpSecurityDescriptor;
    oss << ",\n";

    WriteBOOLString(oss, value->decoded_value->bInheritHandle, indent2.c_str());
    oss << "}";

}

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        WriteHandleId(oss, *ppFactory->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_CreateDXGIFactory1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        WriteHandleId(oss, *ppFactory->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIObject");
    oss << "->";
    oss << "SetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        format::HandleId pUnknown)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIObject");
    oss << "->";
    oss << "SetPrivateDataInterface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    WriteHandleId(oss, pUnknown, "    ", "IUnknown", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIObject");
    oss << "->";
    oss << "GetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDataSize, "    ", false))
    {
        oss << "    " << *pDataSize->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_GetParent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIObject");
    oss << "->";
    oss << "GetParent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppParent, "    ", true))
    {
        WriteHandleId(oss, *ppParent->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDeviceSubObject_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDeviceSubObject");
    oss << "->";
    oss << "GetDevice(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDevice, "    ", true))
    {
        WriteHandleId(oss, *ppDevice->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_GetSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pSharedHandle)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource");
    oss << "->";
    oss << "GetSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pSharedHandle, "    ", true))
    {
        oss << "    " << "&" << "pSharedHandle" << " /* address = " << *pSharedHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_GetUsage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_USAGE>* pUsage)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource");
    oss << "->";
    oss << "GetUsage(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pUsage, "    ", false))
    {
        oss << "    " << *pUsage->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_SetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT EvictionPriority)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource");
    oss << "->";
    oss << "SetEvictionPriority(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << EvictionPriority;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_GetEvictionPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pEvictionPriority)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource");
    oss << "->";
    oss << "GetEvictionPriority(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pEvictionPriority, "    ", true))
    {
        oss << "    " << "&" << *pEvictionPriority->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_AcquireSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key,
        DWORD dwMilliseconds)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIKeyedMutex");
    oss << "->";
    oss << "AcquireSync(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Key;
    oss << ",\n";

    oss << "    " << dwMilliseconds;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Key)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIKeyedMutex");
    oss << "->";
    oss << "ReleaseSync(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Key;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_SURFACE_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface");
    oss << "->";
    oss << "Map(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MAPPED_RECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pLockedRect, "    ", true))
    {
        WriteStructString(oss, pLockedRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    oss << "    " << MapFlags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface");
    oss << "->";
    oss << "Unmap(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface1_GetDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Discard,
        PointerDecoder<uint64_t, void*>* phdc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface1");
    oss << "->";
    oss << "GetDC(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Discard, "    ", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, phdc, "    ", true))
    {
        oss << "    " << "&" << "phdc" << " /* address = " << *phdc->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface1_ReleaseDC(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface1");
    oss << "->";
    oss << "ReleaseDC(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDirtyRect, "    ", false))
    {
        WriteStructString(oss, pDirtyRect->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter_EnumOutputs(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter");
    oss << "->";
    oss << "EnumOutputs(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Output;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutput, "    ", true))
    {
        WriteHandleId(oss, *ppOutput->GetPointer(), "    ", "IDXGIOutput", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_ADAPTER_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter");
    oss << "->";
    oss << "CheckInterfaceSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*InterfaceName.decoded_value);
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ LARGE_INTEGER{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pUMDVersion, "    ", true))
    {
        oss << "    " << "&" << pUMDVersion->GetPointer()->QuadPart;
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_OUTPUT_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplayModeList(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetDisplayModeList(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(EnumFormat);
    oss << ",\n";

    oss << "    " << Flags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumModes, "    ", false))
    {
        oss << "    " << *pNumModes->GetPointer();
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MODE_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteArrayStructsString(oss, pDesc, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "FindClosestMatchingMode(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pModeToMatch, "    ", false))
    {
        WriteStructString(oss, pModeToMatch->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MODE_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pClosestMatch, "    ", true))
    {
        WriteStructString(oss, pClosestMatch->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    WriteHandleId(oss, pConcernedDevice, "    ", "IUnknown", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_WaitForVBlank(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "WaitForVBlank(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_TakeOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        BOOL Exclusive)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "TakeOwnership(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    WriteBOOLString(oss, Exclusive, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_ReleaseOwnership(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "ReleaseOwnership(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetGammaControlCapabilities(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_GAMMA_CONTROL_CAPABILITIES{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pGammaCaps, "    ", true))
    {
        WriteStructString(oss, pGammaCaps->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_SetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "SetGammaControl(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pArray, "    ", false))
    {
        WriteStructString(oss, pArray->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControl(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetGammaControl(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_GAMMA_CONTROL{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pArray, "    ", true))
    {
        WriteStructString(oss, pArray->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_SetDisplaySurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pScanoutSurface)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "SetDisplaySurface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pScanoutSurface, "    ", "IDXGISurface", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetDisplaySurfaceData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDestination, "    ", "IDXGISurface", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput");
    oss << "->";
    oss << "GetFrameStatistics(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_FRAME_STATISTICS{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT Flags)
{
    OverridePresent(
        object_id,
        return_value,
        SyncInterval,
        Flags);
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetBuffer(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Buffer;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        WriteHandleId(oss, *ppSurface->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_SetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Fullscreen,
        format::HandleId pTarget)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "SetFullscreenState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Fullscreen, "    ", false);
    oss << ",\n";

    WriteHandleId(oss, pTarget, "    ", "IDXGIOutput", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFullscreenState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetFullscreenState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFullscreen, "    ", true))
    {
        oss << "    " << "&" << *pFullscreen->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppTarget, "    ", true))
    {
        WriteHandleId(oss, *ppTarget->GetPointer(), "    ", "IDXGIOutput", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_SWAP_CHAIN_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeBuffers(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "ResizeBuffers(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << BufferCount;
    oss << ",\n";

    oss << "    " << Width;
    oss << ",\n";

    oss << "    " << Height;
    oss << ",\n";

    oss << "    " << ConverttoText(NewFormat);
    oss << ",\n";

    oss << "    " << SwapChainFlags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeTarget(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "ResizeTarget(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pNewTargetParameters, "    ", false))
    {
        WriteStructString(oss, pNewTargetParameters->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetContainingOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetContainingOutput(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutput, "    ", true))
    {
        WriteHandleId(oss, *ppOutput->GetPointer(), "    ", "IDXGIOutput", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFrameStatistics(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetFrameStatistics(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_FRAME_STATISTICS{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetLastPresentCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pLastPresentCount)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain");
    oss << "->";
    oss << "GetLastPresentCount(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLastPresentCount, "    ", true))
    {
        oss << "    " << "&" << *pLastPresentCount->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_EnumAdapters(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory");
    oss << "->";
    oss << "EnumAdapters(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Adapter;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppAdapter->GetPointer(), "    ", "IDXGIAdapter", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_MakeWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory");
    oss << "->";
    oss << "MakeWindowAssociation(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << WindowHandle;
    oss << ",\n";

    oss << "    " << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_GetWindowAssociation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pWindowHandle)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory");
    oss << "->";
    oss << "GetWindowAssociation(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pWindowHandle, "    ", true))
    {
        oss << "    " << "&" << "pWindowHandle" << " /* address = " << *pWindowHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSwapChain(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory");
    oss << "->";
    oss << "CreateSwapChain(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGISwapChain", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory");
    oss << "->";
    oss << "CreateSoftwareAdapter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Module;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppAdapter->GetPointer(), "    ", "IDXGIAdapter", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_GetAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice");
    oss << "->";
    oss << "GetAdapter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAdapter, "    ", true))
    {
        WriteHandleId(oss, *pAdapter->GetPointer(), "    ", "IDXGIAdapter", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_CreateSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
        HandlePointerDecoder<IDXGISurface*>* ppSurface)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice");
    oss << "->";
    oss << "CreateSurface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << NumSurfaces;
    oss << ",\n";

    oss << "    " << Usage;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSharedResource, "    ", false))
    {
        WriteStructString(oss, pSharedResource->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        WriteHandleId(oss, *ppSurface->GetPointer(), "    ", "IDXGISurface", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_QueryResourceResidency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice");
    oss << "->";
    oss << "QueryResourceResidency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IUnknown", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResidencyStatus, "    ", true))
    {
        WriteArrayConvertsString(oss, pResidencyStatus, "    ", true);
    }
    oss << ",\n";

    oss << "    " << NumResources;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        INT Priority)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice");
    oss << "->";
    oss << "SetGPUThreadPriority(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Priority;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<INT>* pPriority)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice");
    oss << "->";
    oss << "GetGPUThreadPriority(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pPriority, "    ", true))
    {
        oss << "    " << "&" << *pPriority->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory1_EnumAdapters1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory1");
    oss << "->";
    oss << "EnumAdapters1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Adapter;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppAdapter->GetPointer(), "    ", "IDXGIAdapter1", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory1_IsCurrent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory1");
    oss << "->";
    oss << "IsCurrent(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter1");
    oss << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_ADAPTER_DESC1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice1");
    oss << "->";
    oss << "SetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << MaxLatency;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice1");
    oss << "->";
    oss << "GetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMaxLatency, "    ", true))
    {
        oss << "    " << "&" << *pMaxLatency->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDisplayControl");
    oss << "->";
    oss << "IsStereoEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL enabled)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDisplayControl");
    oss << "->";
    oss << "SetStereoEnabled(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, enabled, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "AcquireNextFrame(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << TimeoutInMilliseconds;
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_OUTDUPL_FRAME_INFO{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pFrameInfo, "    ", true))
    {
        WriteStructString(oss, pFrameInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDesktopResource, "    ", true))
    {
        WriteHandleId(oss, *ppDesktopResource->GetPointer(), "    ", "IDXGIResource", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "GetFrameDirtyRects(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << DirtyRectsBufferSize;
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ tagRECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDirtyRectsBuffer, "    ", true))
    {
        WriteArrayStructsString(oss, pDirtyRectsBuffer, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDirtyRectsBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pDirtyRectsBufferSizeRequired->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "GetFrameMoveRects(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << MoveRectsBufferSize;
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_OUTDUPL_MOVE_RECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pMoveRectBuffer, "    ", true))
    {
        WriteArrayStructsString(oss, pMoveRectBuffer, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMoveRectsBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pMoveRectsBufferSizeRequired->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "GetFramePointerShape(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << PointerShapeBufferSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPointerShapeBuffer, "    ", true))
    {
        oss << "    " << "&" << "pPointerShapeBuffer" << " /* value = " << static_cast<uint16_t>(*pPointerShapeBuffer->GetPointer()) << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPointerShapeBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pPointerShapeBufferSizeRequired->GetPointer();
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_OUTDUPL_POINTER_SHAPE_INFO{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pPointerShapeInfo, "    ", true))
    {
        WriteStructString(oss, pPointerShapeInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "MapDesktopSurface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MAPPED_RECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pLockedRect, "    ", true))
    {
        WriteStructString(oss, pLockedRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "UnMapDesktopSurface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutputDuplication");
    oss << "->";
    oss << "ReleaseFrame(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface2_GetResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISurface2");
    oss << "->";
    oss << "GetResource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppParentResource, "    ", true))
    {
        WriteHandleId(oss, *ppParentResource->GetPointer(), "    ", "void", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSubresourceIndex, "    ", true))
    {
        oss << "    " << "&" << *pSubresourceIndex->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource1");
    oss << "->";
    oss << "CreateSubresourceSurface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << index;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        WriteHandleId(oss, *ppSurface->GetPointer(), "    ", "IDXGISurface2", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIResource1");
    oss << "->";
    oss << "CreateSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAttributes, "    ", false))
    {
        WriteStructString(oss, pAttributes->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << dwAccess;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, lpName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(lpName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHandle, "    ", true))
    {
        oss << "    " << "&" << "pHandle" << " /* address = " << *pHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice2_OfferResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice2");
    oss << "->";
    oss << "OfferResources(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Priority);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice2_ReclaimResources(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice2");
    oss << "->";
    oss << "ReclaimResources(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDiscarded, "    ", true))
    {
        WriteArrayBOOLsString(oss, pDiscarded, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice2");
    oss << "->";
    oss << "EnqueueSetEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_SWAP_CHAIN_DESC1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetFullscreenDesc(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_SWAP_CHAIN_FULLSCREEN_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetHwnd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint64_t, void*>* pHwnd)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetHwnd(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHwnd, "    ", true))
    {
        oss << "    " << "&" << "pHwnd" << " /* address = " << *pHwnd->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetCoreWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetCoreWindow(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*refiid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppUnk, "    ", true))
    {
        WriteHandleId(oss, *ppUnk->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_Present1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    OverridePresent1(
        object_id,
        return_value,
        SyncInterval,
        PresentFlags,
        pPresentParameters);
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "IsTemporaryMonoSupported(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetRestrictToOutput(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppRestrictToOutput, "    ", true))
    {
        WriteHandleId(oss, *ppRestrictToOutput->GetPointer(), "    ", "IDXGIOutput", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "SetBackgroundColor(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pColor, "    ", false))
    {
        WriteStructString(oss, pColor->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetBackgroundColor(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3DCOLORVALUE{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pColor, "    ", true))
    {
        WriteStructString(oss, pColor->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MODE_ROTATION Rotation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "SetRotation(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Rotation);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRotation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain1");
    oss << "->";
    oss << "GetRotation(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRotation, "    ", true))
    {
        oss << "    " << "&" << ConverttoText(*pRotation->GetPointer());
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "IsWindowedStereoEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hWnd,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "CreateSwapChainForHwnd(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    oss << "    " << hWnd;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFullscreenDesc, "    ", false))
    {
        WriteStructString(oss, pFullscreenDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pRestrictToOutput, "    ", "IDXGIOutput", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGISwapChain1", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        format::HandleId pWindow,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "CreateSwapChainForCoreWindow(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    WriteHandleId(oss, pWindow, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pRestrictToOutput, "    ", "IDXGIOutput", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGISwapChain1", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "GetSharedResourceAdapterLuid(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hResource;
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ LUID{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pLuid, "    ", true))
    {
        WriteStructString(oss, pLuid->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "RegisterStereoStatusWindow(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << WindowHandle;
    oss << ",\n";

    oss << "    " << wMsg;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "RegisterStereoStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "UnregisterStereoStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "RegisterOcclusionStatusWindow(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << WindowHandle;
    oss << ",\n";

    oss << "    " << wMsg;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "RegisterOcclusionStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "UnregisterOcclusionStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory2");
    oss << "->";
    oss << "CreateSwapChainForComposition(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pRestrictToOutput, "    ", "IDXGIOutput", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGISwapChain1", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter2_GetDesc2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter2");
    oss << "->";
    oss << "GetDesc2(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_ADAPTER_DESC2{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput1");
    oss << "->";
    oss << "GetDisplayModeList1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(EnumFormat);
    oss << ",\n";

    oss << "    " << Flags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumModes, "    ", false))
    {
        oss << "    " << *pNumModes->GetPointer();
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MODE_DESC1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteArrayStructsString(oss, pDesc, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput1");
    oss << "->";
    oss << "FindClosestMatchingMode1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pModeToMatch, "    ", false))
    {
        WriteStructString(oss, pModeToMatch->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MODE_DESC1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pClosestMatch, "    ", true))
    {
        WriteStructString(oss, pClosestMatch->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    WriteHandleId(oss, pConcernedDevice, "    ", "IUnknown", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDestination)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput1");
    oss << "->";
    oss << "GetDisplaySurfaceData1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDestination, "    ", "IDXGIResource", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_DuplicateOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput1");
    oss << "->";
    oss << "DuplicateOutput(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutputDuplication, "    ", true))
    {
        WriteHandleId(oss, *ppOutputDuplication->GetPointer(), "    ", "IDXGIOutputDuplication", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory2(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory2(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Flags;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        WriteHandleId(oss, *ppFactory->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_DXGIGetDebugInterface1(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug)
{
    std::ostringstream oss;
    oss << "DXGIGetDebugInterface1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Flags;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDebug, "    ", true))
    {
        WriteHandleId(oss, *pDebug->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice3_Trim(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice3");
    oss << "->";
    oss << "Trim(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "SetSourceSize(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Width;
    oss << ",\n";

    oss << "    " << Height;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetSourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "GetSourceSize(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pWidth, "    ", true))
    {
        oss << "    " << "&" << *pWidth->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeight, "    ", true))
    {
        oss << "    " << "&" << *pHeight->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT MaxLatency)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "SetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << MaxLatency;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pMaxLatency)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "GetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMaxLatency, "    ", true))
    {
        oss << "    " << "&" << *pMaxLatency->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "GetFrameLatencyWaitableObject(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "SetMatrixTransform(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMatrix, "    ", false))
    {
        WriteStructString(oss, pMatrix->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain2");
    oss << "->";
    oss << "GetMatrixTransform(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_MATRIX_3X2_F{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pMatrix, "    ", true))
    {
        WriteStructString(oss, pMatrix->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput2_SupportsOverlays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput2");
    oss << "->";
    oss << "SupportsOverlays(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory3_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory3");
    oss << "->";
    oss << "GetCreationFlags(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "PresentBuffer(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << BufferToPresent;
    oss << ",\n";

    oss << "    " << SyncInterval;
    oss << ",\n";

    oss << "    " << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "SetSourceRect(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRect, "    ", false))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "SetTargetRect(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRect, "    ", false))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Width,
        UINT Height)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "SetDestSize(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Width;
    oss << ",\n";

    oss << "    " << Height;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "GetSourceRect(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ tagRECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pRect, "    ", true))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "GetTargetRect(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ tagRECT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pRect, "    ", true))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "GetDestSize(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pWidth, "    ", true))
    {
        oss << "    " << "&" << *pWidth->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeight, "    ", true))
    {
        oss << "    " << "&" << *pHeight->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "SetColorSpace(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(ColorSpace);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDecodeSwapChain");
    oss << "->";
    oss << "GetColorSpace(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactoryMedia");
    oss << "->";
    oss << "CreateSwapChainForCompositionSurfaceHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    oss << "    " << hSurface;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pRestrictToOutput, "    ", "IDXGIOutput", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGISwapChain1", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
        format::HandleId pYuvDecodeBuffers,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactoryMedia");
    oss << "->";
    oss << "CreateDecodeSwapChainForCompositionSurfaceHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    oss << "    " << hSurface;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pYuvDecodeBuffers, "    ", "IDXGIResource", false);
    oss << ",\n";

    WriteHandleId(oss, pRestrictToOutput, "    ", "IDXGIOutput", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        WriteHandleId(oss, *ppSwapChain->GetPointer(), "    ", "IDXGIDecodeSwapChain", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChainMedia");
    oss << "->";
    oss << "GetFrameStatisticsMedia(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_FRAME_STATISTICS_MEDIA{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Duration)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChainMedia");
    oss << "->";
    oss << "SetPresentDuration(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Duration;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChainMedia");
    oss << "->";
    oss << "CheckPresentDurationSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << DesiredPresentDuration;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestSmallerPresentDuration, "    ", true))
    {
        oss << "    " << "&" << *pClosestSmallerPresentDuration->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestLargerPresentDuration, "    ", true))
    {
        oss << "    " << "&" << *pClosestLargerPresentDuration->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT EnumFormat,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput3");
    oss << "->";
    oss << "CheckOverlaySupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(EnumFormat);
    oss << ",\n";

    WriteHandleId(oss, pConcernedDevice, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain3");
    oss << "->";
    oss << "GetCurrentBackBufferIndex(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain3");
    oss << "->";
    oss << "CheckColorSpaceSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(ColorSpace);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pColorSpaceSupport, "    ", true))
    {
        oss << "    " << "&" << *pColorSpaceSupport->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_SetColorSpace1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain3");
    oss << "->";
    oss << "SetColorSpace1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(ColorSpace);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        PointerDecoder<UINT>* pCreationNodeMask,
        HandlePointerDecoder<IUnknown*>* ppPresentQueue)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain3");
    oss << "->";
    oss << "ResizeBuffers1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << BufferCount;
    oss << ",\n";

    oss << "    " << Width;
    oss << ",\n";

    oss << "    " << Height;
    oss << ",\n";

    oss << "    " << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << SwapChainFlags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCreationNodeMask, "    ", false))
    {
        WriteArrayValuesString(oss, pCreationNodeMask, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPresentQueue, "    ", false))
    {
        WriteArrayClassesString(oss, ppPresentQueue, "IUnknown", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput4");
    oss << "->";
    oss << "CheckOverlayColorSpaceSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << ConverttoText(ColorSpace);
    oss << ",\n";

    WriteHandleId(oss, pConcernedDevice, "    ", "IUnknown", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory4");
    oss << "->";
    oss << "EnumAdapterByLuid(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &AdapterLuid, "    ", false, false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppvAdapter->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory4");
    oss << "->";
    oss << "EnumWarpAdapter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppvAdapter->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "RegisterHardwareContentProtectionTeardownStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "UnregisterHardwareContentProtectionTeardownStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "QueryVideoMemoryInfo(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NodeIndex;
    oss << ",\n";

    oss << "    " << ConverttoText(MemorySegmentGroup);
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_QUERY_VIDEO_MEMORY_INFO{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pVideoMemoryInfo, "    ", true))
    {
        WriteStructString(oss, pVideoMemoryInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "SetVideoMemoryReservation(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NodeIndex;
    oss << ",\n";

    oss << "    " << ConverttoText(MemorySegmentGroup);
    oss << ",\n";

    oss << "    " << Reservation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "RegisterVideoMemoryBudgetChangeNotificationEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter3");
    oss << "->";
    oss << "UnregisterVideoMemoryBudgetChangeNotification(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIOutput5_DuplicateOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        PointerDecoder<DXGI_FORMAT>* pSupportedFormats,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput5");
    oss << "->";
    oss << "DuplicateOutput1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDevice, "    ", "IUnknown", false);
    oss << ",\n";

    oss << "    " << Flags;
    oss << ",\n";

    oss << "    " << SupportedFormatsCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSupportedFormats, "    ", false))
    {
        WriteArrayConvertsString(oss, pSupportedFormats, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutputDuplication, "    ", true))
    {
        WriteHandleId(oss, *ppOutputDuplication->GetPointer(), "    ", "IDXGIOutputDuplication", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGISwapChain4");
    oss << "->";
    oss << "SetHDRMetaData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << Size;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMetaData, "    ", false))
    {
        oss << "    " << "pMetaData" << " /* value = " << static_cast<uint16_t>(*pMetaData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice4_OfferResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice4");
    oss << "->";
    oss << "OfferResources1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Priority);
    oss << ",\n";

    oss << "    " << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice4_ReclaimResources1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIDevice4");
    oss << "->";
    oss << "ReclaimResources1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResults, "    ", true))
    {
        WriteArrayConvertsString(oss, pResults, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_DXGIDeclareAdapterRemovalSupport(
        const ApiCallInfo& call_info,
        HRESULT return_value)
{
    std::ostringstream oss;
    oss << "DXGIDeclareAdapterRemovalSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter4_GetDesc3(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIAdapter4");
    oss << "->";
    oss << "GetDesc3(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_ADAPTER_DESC3{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput6_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput6");
    oss << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ DXGI_OUTPUT_DESC1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIOutput6");
    oss << "->";
    oss << "CheckHardwareCompositionSupport(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory6");
    oss << "->";
    oss << "EnumAdapterByGpuPreference(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Adapter;
    oss << ",\n";

    oss << "    " << ConverttoText(GpuPreference);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        WriteHandleId(oss, *ppvAdapter->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory7");
    oss << "->";
    oss << "RegisterAdaptersChangedEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        DWORD dwCookie)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IDXGIFactory7");
    oss << "->";
    oss << "UnregisterAdaptersChangedEvent(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_D3D12SerializeRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    std::ostringstream oss;
    oss << "D3D12SerializeRootSignature(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRootSignature, "    ", false))
    {
        WriteStructString(oss, pRootSignature->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Version);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        WriteHandleId(oss, *ppBlob->GetPointer(), "    ", "ID3D10Blob", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppErrorBlob, "    ", true))
    {
        WriteHandleId(oss, *ppErrorBlob->GetPointer(), "    ", "ID3D10Blob", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    std::ostringstream oss;
    oss << "D3D12CreateRootSignatureDeserializer(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << SrcDataSizeInBytes;
    oss << ",\n";

    oss << "    " << ConverttoText(*pRootSignatureDeserializerInterface.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppRootSignatureDeserializer, "    ", true))
    {
        WriteHandleId(oss, *ppRootSignatureDeserializer->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12SerializeVersionedRootSignature(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    std::ostringstream oss;
    oss << "D3D12SerializeVersionedRootSignature(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRootSignature, "    ", false))
    {
        WriteStructString(oss, pRootSignature->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        WriteHandleId(oss, *ppBlob->GetPointer(), "    ", "ID3D10Blob", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppErrorBlob, "    ", true))
    {
        WriteHandleId(oss, *ppErrorBlob->GetPointer(), "    ", "ID3D10Blob", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    std::ostringstream oss;
    oss << "D3D12CreateVersionedRootSignatureDeserializer(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << SrcDataSizeInBytes;
    oss << ",\n";

    oss << "    " << ConverttoText(*pRootSignatureDeserializerInterface.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppRootSignatureDeserializer, "    ", true))
    {
        WriteHandleId(oss, *ppRootSignatureDeserializer->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateDevice(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        format::HandleId pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    std::ostringstream oss;
    oss << "D3D12CreateDevice(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pAdapter, "    ", "IUnknown", false);
    oss << ",\n";

    oss << "    " << ConverttoText(MinimumFeatureLevel);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDevice, "    ", true))
    {
        WriteHandleId(oss, *ppDevice->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12GetDebugInterface(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    std::ostringstream oss;
    oss << "D3D12GetDebugInterface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvDebug, "    ", true))
    {
        WriteHandleId(oss, *ppvDebug->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12EnableExperimentalFeatures(
        const ApiCallInfo& call_info,
        HRESULT return_value,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    std::ostringstream oss;
    oss << "D3D12EnableExperimentalFeatures(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumFeatures;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pIIDs, "    ", false))
    {
        WriteArrayConvertsString(oss, pIIDs, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pConfigurationStructs, "    ", false))
    {
        oss << "    " << "pConfigurationStructs" << " /* value = " << static_cast<uint16_t>(*pConfigurationStructs->GetPointer()) << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pConfigurationStructSizes, "    ", false))
    {
        WriteArrayValuesString(oss, pConfigurationStructSizes, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_GetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Object");
    oss << "->";
    oss << "GetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDataSize, "    ", false))
    {
        oss << "    " << *pDataSize->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Object");
    oss << "->";
    oss << "SetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateDataInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID guid,
        format::HandleId pData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Object");
    oss << "->";
    oss << "SetPrivateDataInterface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    WriteHandleId(oss, pData, "    ", "IUnknown", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_SetName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Object");
    oss << "->";
    oss << "SetName(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceChild_GetDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceChild");
    oss << "->";
    oss << "GetDevice(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvDevice, "    ", true))
    {
        WriteHandleId(oss, *ppvDevice->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12RootSignatureDeserializer");
    oss << "->";
    oss << "GetRootSignatureDesc(\n    /* ";

    oss << "return = " ;
    if (WriteCheckPointerDecoderNull(oss, return_value, "                ", false))
    {
        WriteStructString(oss, return_value->GetMetaStructPointer(), "                ", true, false);
    }
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12VersionedRootSignatureDeserializer");
    oss << "->";
    oss << "GetRootSignatureDescAtVersion(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(convertToVersion);
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_VERSIONED_ROOT_SIGNATURE_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, ppDesc, "    ", true))
    {
        WriteStructString(oss, ppDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12VersionedRootSignatureDeserializer");
    oss << "->";
    oss << "GetUnconvertedRootSignatureDesc(\n    /* ";

    oss << "return = " ;
    if (WriteCheckPointerDecoderNull(oss, return_value, "                ", false))
    {
        WriteStructString(oss, return_value->GetMetaStructPointer(), "                ", true, false);
    }
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Heap_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Heap");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_Map(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "Map(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Subresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pReadRange, "    ", false))
    {
        WriteStructString(oss, pReadRange->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppData, "    ", true))
    {
        oss << "    " << "&" << "ppData" << " /* address = " << *ppData->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_Unmap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "Unmap(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Subresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pWrittenRange, "    ", false))
    {
        WriteStructString(oss, pWrittenRange->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "GetGPUVirtualAddress(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_WriteToSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT DstSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
        uint64_t pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "WriteToSubresource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << DstSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDstBox, "    ", false))
    {
        WriteStructString(oss, pDstBox->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << pSrcData;
    oss << ",\n";

    oss << "    " << SrcRowPitch;
    oss << ",\n";

    oss << "    " << SrcDepthPitch;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_ReadFromSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "ReadFromSubresource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "&" << pDstData;
    oss << ",\n";

    oss << "    " << DstRowPitch;
    oss << ",\n";

    oss << "    " << DstDepthPitch;
    oss << ",\n";

    oss << "    " << SrcSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcBox, "    ", false))
    {
        WriteStructString(oss, pSrcBox->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetHeapProperties(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource");
    oss << "->";
    oss << "GetHeapProperties(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_HEAP_PROPERTIES{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", true))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapFlags, "    ", true))
    {
        oss << "    " << "&" << ConverttoText(*pHeapFlags->GetPointer());
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandAllocator_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandAllocator");
    oss << "->";
    oss << "Reset(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_GetCompletedValue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Fence");
    oss << "->";
    oss << "GetCompletedValue(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_SetEventOnCompletion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value,
        uint64_t hEvent)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Fence");
    oss << "->";
    oss << "SetEventOnCompletion(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Value;
    oss << ",\n";

    oss << "    " << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 Value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Fence");
    oss << "->";
    oss << "Signal(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence1_GetCreationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_FENCE_FLAGS return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Fence1");
    oss << "->";
    oss << "GetCreationFlags(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineState_GetCachedBlob(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineState");
    oss << "->";
    oss << "GetCachedBlob(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        WriteHandleId(oss, *ppBlob->GetPointer(), "    ", "ID3D10Blob", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DescriptorHeap");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DescriptorHeap");
    oss << "->";
    oss << "GetCPUDescriptorHandleForHeapStart(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DescriptorHeap");
    oss << "->";
    oss << "GetGPUDescriptorHandleForHeapStart(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandList_GetType(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandList");
    oss << "->";
    oss << "GetType(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Close(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "Close(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Reset(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pAllocator,
        format::HandleId pInitialState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "Reset(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pAllocator, "    ", "ID3D12CommandAllocator", false);
    oss << ",\n";

    WriteHandleId(oss, pInitialState, "    ", "ID3D12PipelineState", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ClearState(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pPipelineState, "    ", "ID3D12PipelineState", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "DrawInstanced(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << VertexCountPerInstance;
    oss << ",\n";

    oss << "    " << InstanceCount;
    oss << ",\n";

    oss << "    " << StartVertexLocation;
    oss << ",\n";

    oss << "    " << StartInstanceLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "DrawIndexedInstanced(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << IndexCountPerInstance;
    oss << ",\n";

    oss << "    " << InstanceCount;
    oss << ",\n";

    oss << "    " << StartIndexLocation;
    oss << ",\n";

    oss << "    " << BaseVertexLocation;
    oss << ",\n";

    oss << "    " << StartInstanceLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "Dispatch(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ThreadGroupCountX;
    oss << ",\n";

    oss << "    " << ThreadGroupCountY;
    oss << ",\n";

    oss << "    " << ThreadGroupCountZ;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "CopyBufferRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << DstOffset;
    oss << ",\n";

    WriteHandleId(oss, pSrcBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << SrcOffset;
    oss << ",\n";

    oss << "    " << NumBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "CopyTextureRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDst, "    ", false))
    {
        WriteStructString(oss, pDst->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << DstX;
    oss << ",\n";

    oss << "    " << DstY;
    oss << ",\n";

    oss << "    " << DstZ;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrc, "    ", false))
    {
        WriteStructString(oss, pSrc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcBox, "    ", false))
    {
        WriteStructString(oss, pSrcBox->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        format::HandleId pSrcResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "CopyResource(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    WriteHandleId(oss, pSrcResource, "    ", "ID3D12Resource", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTiledResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
        format::HandleId pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "CopyTiles(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pTiledResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTileRegionStartCoordinate, "    ", false))
    {
        WriteStructString(oss, pTileRegionStartCoordinate->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTileRegionSize, "    ", false))
    {
        WriteStructString(oss, pTileRegionSize->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << BufferStartOffsetInBytes;
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ResolveSubresource(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << DstSubresource;
    oss << ",\n";

    WriteHandleId(oss, pSrcResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << SrcSubresource;
    oss << ",\n";

    oss << "    " << ConverttoText(Format);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "IASetPrimitiveTopology(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(PrimitiveTopology);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "RSSetViewports(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumViewports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViewports, "    ", false))
    {
        WriteArrayStructsString(oss, pViewports, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "RSSetScissorRects(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4])
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "OMSetBlendFactor(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, BlendFactor, "    ", false))
    {
        WriteArrayValuesString(oss, BlendFactor, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StencilRef)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "OMSetStencilRef(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << StencilRef;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetPipelineState(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pPipelineState, "    ", "ID3D12PipelineState", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumBarriers,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ResourceBarrier(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumBarriers;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pBarriers, "    ", false))
    {
        WriteArrayStructsString(oss, pBarriers, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pCommandList)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ExecuteBundle(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pCommandList, "    ", "ID3D12GraphicsCommandList", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetDescriptorHeaps(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumDescriptorHeaps;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDescriptorHeaps, "    ", false))
    {
        WriteArrayClassesString(oss, ppDescriptorHeaps, "ID3D12DescriptorHeap", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRootSignature(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pRootSignature, "    ", "ID3D12RootSignature", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRootSignature(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pRootSignature, "    ", "ID3D12RootSignature", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRootDescriptorTable(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    WriteStructString(oss, &BaseDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRootDescriptorTable(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    WriteStructString(oss, &BaseDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRoot32BitConstant(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << SrcData;
    oss << ",\n";

    oss << "    " << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRoot32BitConstant(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << SrcData;
    oss << ",\n";

    oss << "    " << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRoot32BitConstants(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << Num32BitValuesToSet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRoot32BitConstants(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << Num32BitValuesToSet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRootConstantBufferView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRootConstantBufferView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRootShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRootShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetComputeRootUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetGraphicsRootUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << RootParameterIndex;
    oss << ",\n";

    oss << "    " << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "IASetIndexBuffer(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pView, "    ", false))
    {
        WriteStructString(oss, pView->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "IASetVertexBuffers(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << StartSlot;
    oss << ",\n";

    oss << "    " << NumViews;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViews, "    ", false))
    {
        WriteArrayStructsString(oss, pViews, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SOSetTargets(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << StartSlot;
    oss << ",\n";

    oss << "    " << NumViews;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViews, "    ", false))
    {
        WriteArrayStructsString(oss, pViews, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "OMSetRenderTargets(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumRenderTargetDescriptors;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRenderTargetDescriptors, "    ", false))
    {
        WriteArrayStructsString(oss, pRenderTargetDescriptors, "    ", false);
    }
    oss << ",\n";

    WriteBOOLString(oss, RTsSingleHandleToDescriptorRange, "    ", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDepthStencilDescriptor, "    ", false))
    {
        WriteStructString(oss, pDepthStencilDescriptor->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ClearDepthStencilView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &DepthStencilView, "    ", false, false);
    oss << ",\n";

    oss << "    " << ConverttoText(ClearFlags);
    oss << ",\n";

    oss << "    " << Depth;
    oss << ",\n";

    oss << "    " << static_cast<uint16_t>(Stencil);
    oss << ",\n";

    oss << "    " << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ClearRenderTargetView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &RenderTargetView, "    ", false, false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ColorRGBA, "    ", false))
    {
        WriteArrayValuesString(oss, ColorRGBA, "    ", false);
    }
    oss << ",\n";

    oss << "    " << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<UINT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ClearUnorderedAccessViewUint(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &ViewGPUHandleInCurrentHeap, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &ViewCPUHandle, "    ", false, false);
    oss << ",\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Values, "    ", false))
    {
        WriteArrayValuesString(oss, Values, "    ", false);
    }
    oss << ",\n";

    oss << "    " << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<FLOAT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ClearUnorderedAccessViewFloat(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &ViewGPUHandleInCurrentHeap, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &ViewCPUHandle, "    ", false, false);
    oss << ",\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Values, "    ", false))
    {
        WriteArrayValuesString(oss, Values, "    ", false);
    }
    oss << ",\n";

    oss << "    " << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "DiscardResource(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRegion, "    ", false))
    {
        WriteStructString(oss, pRegion->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "BeginQuery(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pQueryHeap, "    ", "ID3D12QueryHeap", false);
    oss << ",\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << Index;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "EndQuery(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pQueryHeap, "    ", "ID3D12QueryHeap", false);
    oss << ",\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << Index;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        format::HandleId pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ResolveQueryData(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pQueryHeap, "    ", "ID3D12QueryHeap", false);
    oss << ",\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << StartIndex;
    oss << ",\n";

    oss << "    " << NumQueries;
    oss << ",\n";

    WriteHandleId(oss, pDestinationBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << AlignedDestinationBufferOffset;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetPredication(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << AlignedBufferOffset;
    oss << ",\n";

    oss << "    " << ConverttoText(Operation);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "SetMarker(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "BeginEvent(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "EndEvent(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pCommandSignature,
        UINT MaxCommandCount,
        format::HandleId pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        format::HandleId pCountBuffer,
        UINT64 CountBufferOffset)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList");
    oss << "->";
    oss << "ExecuteIndirect(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pCommandSignature, "    ", "ID3D12CommandSignature", false);
    oss << ",\n";

    oss << "    " << MaxCommandCount;
    oss << ",\n";

    WriteHandleId(oss, pArgumentBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << ArgumentBufferOffset;
    oss << ",\n";

    WriteHandleId(oss, pCountBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << CountBufferOffset;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "AtomicCopyBufferUINT(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << DstOffset;
    oss << ",\n";

    WriteHandleId(oss, pSrcBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << SrcOffset;
    oss << ",\n";

    oss << "    " << Dependencies;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDependentResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppDependentResources, "ID3D12Resource", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDependentSubresourceRanges, "    ", false))
    {
        WriteArrayStructsString(oss, pDependentSubresourceRanges, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "AtomicCopyBufferUINT64(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << DstOffset;
    oss << ",\n";

    WriteHandleId(oss, pSrcBuffer, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << SrcOffset;
    oss << ",\n";

    oss << "    " << Dependencies;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDependentResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppDependentResources, "ID3D12Resource", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDependentSubresourceRanges, "    ", false))
    {
        WriteArrayStructsString(oss, pDependentSubresourceRanges, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "OMSetDepthBounds(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Min;
    oss << ",\n";

    oss << "    " << Max;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "SetSamplePositions(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumSamplesPerPixel;
    oss << ",\n";

    oss << "    " << NumPixels;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSamplePositions, "    ", false))
    {
        WriteArrayStructsString(oss, pSamplePositions, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_tagRECT>* pSrcRect,
        DXGI_FORMAT Format,
        D3D12_RESOLVE_MODE ResolveMode)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "ResolveSubresourceRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << DstSubresource;
    oss << ",\n";

    oss << "    " << DstX;
    oss << ",\n";

    oss << "    " << DstY;
    oss << ",\n";

    WriteHandleId(oss, pSrcResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << SrcSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcRect, "    ", false))
    {
        WriteStructString(oss, pSrcRect->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << ConverttoText(ResolveMode);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Mask)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList1");
    oss << "->";
    oss << "SetViewInstanceMask(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Mask;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList2");
    oss << "->";
    oss << "WriteBufferImmediate(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Count;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pParams, "    ", false))
    {
        WriteArrayStructsString(oss, pParams, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pModes, "    ", false))
    {
        WriteArrayConvertsString(oss, pModes, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT NumResourceRegions,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pResourceRegionStartCoordinates,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pResourceRegionSizes,
        format::HandleId pHeap,
        UINT NumRanges,
        PointerDecoder<D3D12_TILE_RANGE_FLAGS>* pRangeFlags,
        PointerDecoder<UINT>* pHeapRangeStartOffsets,
        PointerDecoder<UINT>* pRangeTileCounts,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "UpdateTileMappings(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << NumResourceRegions;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceRegionStartCoordinates, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceRegionStartCoordinates, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceRegionSizes, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceRegionSizes, "    ", false);
    }
    oss << ",\n";

    WriteHandleId(oss, pHeap, "    ", "ID3D12Heap", false);
    oss << ",\n";

    oss << "    " << NumRanges;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRangeFlags, "    ", false))
    {
        WriteArrayConvertsString(oss, pRangeFlags, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapRangeStartOffsets, "    ", false))
    {
        WriteArrayValuesString(oss, pHeapRangeStartOffsets, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRangeTileCounts, "    ", false))
    {
        WriteArrayValuesString(oss, pRangeTileCounts, "    ", false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pDstResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
        format::HandleId pSrcResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "CopyTileMappings(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pDstResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDstRegionStartCoordinate, "    ", false))
    {
        WriteStructString(oss, pDstRegionStartCoordinate->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pSrcResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcRegionStartCoordinate, "    ", false))
    {
        WriteStructString(oss, pSrcRegionStartCoordinate->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRegionSize, "    ", false))
    {
        WriteStructString(oss, pRegionSize->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "ExecuteCommandLists(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumCommandLists;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandLists, "    ", false))
    {
        WriteArrayClassesString(oss, ppCommandLists, "ID3D12CommandList", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_SetMarker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "SetMarker(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_BeginEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "BeginEvent(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_EndEvent(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "EndEvent(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Signal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "Signal(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pFence, "    ", "ID3D12Fence", false);
    oss << ",\n";

    oss << "    " << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Wait(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pFence,
        UINT64 Value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "Wait(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pFence, "    ", "ID3D12Fence", false);
    oss << ",\n";

    oss << "    " << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pFrequency)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "GetTimestampFrequency(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFrequency, "    ", true))
    {
        oss << "    " << "&" << *pFrequency->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "GetClockCalibration(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pGpuTimestamp, "    ", true))
    {
        oss << "    " << "&" << *pGpuTimestamp->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCpuTimestamp, "    ", true))
    {
        oss << "    " << "&" << *pCpuTimestamp->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_COMMAND_QUEUE_DESC return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12CommandQueue");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetNodeCount(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetNodeCount(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateCommandQueue(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandQueue, "    ", true))
    {
        WriteHandleId(oss, *ppCommandQueue->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandAllocator(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateCommandAllocator(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(type);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandAllocator, "    ", true))
    {
        WriteHandleId(oss, *ppCommandAllocator->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateGraphicsPipelineState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateComputePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateComputePipelineState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandList(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        format::HandleId pCommandAllocator,
        format::HandleId pInitialState,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateCommandList(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << nodeMask;
    oss << ",\n";

    oss << "    " << ConverttoText(type);
    oss << ",\n";

    WriteHandleId(oss, pCommandAllocator, "    ", "ID3D12CommandAllocator", false);
    oss << ",\n";

    WriteHandleId(oss, pInitialState, "    ", "ID3D12PipelineState", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandList, "    ", true))
    {
        WriteHandleId(oss, *ppCommandList->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateDescriptorHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateDescriptorHeap(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDescriptorHeapDesc, "    ", false))
    {
        WriteStructString(oss, pDescriptorHeapDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetDescriptorHandleIncrementSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(DescriptorHeapType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateRootSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateRootSignature(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << nodeMask;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pBlobWithRootSignature, "    ", false))
    {
        oss << "    " << "pBlobWithRootSignature" << " /* value = " << static_cast<uint16_t>(*pBlobWithRootSignature->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << blobLengthInBytes;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvRootSignature, "    ", true))
    {
        WriteHandleId(oss, *ppvRootSignature->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateConstantBufferView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateConstantBufferView(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateShaderResourceView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        format::HandleId pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    WriteHandleId(oss, pCounterResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateRenderTargetView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateRenderTargetView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateDepthStencilView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateDepthStencilView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateSampler(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateSampler(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptors(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDestDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
        PointerDecoder<UINT>* pDestDescriptorRangeSizes,
        UINT NumSrcDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
        PointerDecoder<UINT>* pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CopyDescriptors(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumDestDescriptorRanges;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDestDescriptorRangeStarts, "    ", false))
    {
        WriteArrayStructsString(oss, pDestDescriptorRangeStarts, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDestDescriptorRangeSizes, "    ", false))
    {
        WriteArrayValuesString(oss, pDestDescriptorRangeSizes, "    ", false);
    }
    oss << ",\n";

    oss << "    " << NumSrcDescriptorRanges;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcDescriptorRangeStarts, "    ", false))
    {
        WriteArrayStructsString(oss, pSrcDescriptorRangeStarts, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcDescriptorRangeSizes, "    ", false))
    {
        WriteArrayValuesString(oss, pSrcDescriptorRangeSizes, "    ", false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(DescriptorHeapsType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CopyDescriptorsSimple(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumDescriptors;
    oss << ",\n";

    WriteStructString(oss, &DestDescriptorRangeStart, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &SrcDescriptorRangeStart, "    ", false, false);
    oss << ",\n";

    oss << "    " << ConverttoText(DescriptorHeapsType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetResourceAllocationInfo(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << visibleMask;
    oss << ",\n";

    oss << "    " << numResourceDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceDescs, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetCustomHeapProperties(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_HEAP_PROPERTIES return_value,
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetCustomHeapProperties(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << nodeMask;
    oss << ",\n";

    oss << "    " << ConverttoText(heapType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommittedResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateCommittedResource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateHeap(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreatePlacedResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreatePlacedResource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pHeap, "    ", "ID3D12Heap", false);
    oss << ",\n";

    oss << "    " << HeapOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateReservedResource(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateReservedResource(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD Access,
        WStringDecoder* Name,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pObject, "    ", "ID3D12DeviceChild", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pAttributes, "    ", false))
    {
        WriteStructString(oss, pAttributes->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << Access;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHandle, "    ", true))
    {
        oss << "    " << "&" << "pHandle" << " /* address = " << *pHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandle(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "OpenSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NTHandle;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvObj, "    ", true))
    {
        WriteHandleId(oss, *ppvObj->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandleByName(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* Name,
        DWORD Access,
        PointerDecoder<uint64_t, void*>* pNTHandle)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "OpenSharedHandleByName(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << "    " << Access;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNTHandle, "    ", true))
    {
        oss << "    " << "&" << "pNTHandle" << " /* address = " << *pNTHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_MakeResident(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "MakeResident(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_Evict(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "Evict(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateFence(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << InitialValue;
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFence, "    ", true))
    {
        WriteHandleId(oss, *ppFence->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetDeviceRemovedReason(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetCopyableFootprints(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetCopyableFootprints(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDesc, "    ", false))
    {
        WriteStructString(oss, pResourceDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << FirstSubresource;
    oss << ",\n";

    oss << "    " << NumSubresources;
    oss << ",\n";

    oss << "    " << BaseOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pLayouts, "    ", true))
    {
        WriteArrayStructsString(oss, pLayouts, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumRows, "    ", true))
    {
        WriteArrayValuesString(oss, pNumRows, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRowSizeInBytes, "    ", true))
    {
        WriteArrayValuesString(oss, pRowSizeInBytes, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTotalBytes, "    ", true))
    {
        oss << "    " << "&" << *pTotalBytes->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateQueryHeap(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateQueryHeap(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_SetStablePowerState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        BOOL Enable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "SetStablePowerState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandSignature(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        format::HandleId pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "CreateCommandSignature(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pRootSignature, "    ", "ID3D12RootSignature", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvCommandSignature, "    ", true))
    {
        WriteHandleId(oss, *ppvCommandSignature->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceTiling(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTiledResource,
        PointerDecoder<UINT>* pNumTilesForEntireResource,
        StructPointerDecoder<Decoded_D3D12_PACKED_MIP_INFO>* pPackedMipDesc,
        StructPointerDecoder<Decoded_D3D12_TILE_SHAPE>* pStandardTileShapeForNonPackedMips,
        PointerDecoder<UINT>* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_TILING>* pSubresourceTilingsForNonPackedMips)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetResourceTiling(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pTiledResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumTilesForEntireResource, "    ", true))
    {
        oss << "    " << "&" << *pNumTilesForEntireResource->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPackedMipDesc, "    ", true))
    {
        WriteStructString(oss, pPackedMipDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pStandardTileShapeForNonPackedMips, "    ", true))
    {
        WriteStructString(oss, pStandardTileShapeForNonPackedMips->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumSubresourceTilings, "    ", false))
    {
        oss << "    " << *pNumSubresourceTilings->GetPointer();
    }
    oss << ",\n";

    oss << "    " << FirstSubresourceTilingToGet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSubresourceTilingsForNonPackedMips, "    ", true))
    {
        WriteArrayStructsString(oss, pSubresourceTilingsForNonPackedMips, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetAdapterLuid(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device");
    oss << "->";
    oss << "GetAdapterLuid(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        format::HandleId pPipeline)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary");
    oss << "->";
    oss << "StorePipeline(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    WriteHandleId(oss, pPipeline, "    ", "ID3D12PipelineState", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary");
    oss << "->";
    oss << "LoadGraphicsPipeline(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary");
    oss << "->";
    oss << "LoadComputePipeline(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary");
    oss << "->";
    oss << "GetSerializedSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_Serialize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary");
    oss << "->";
    oss << "Serialize(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12PipelineLibrary1");
    oss << "->";
    oss << "LoadPipeline(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T BlobLength,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineLibrary)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device1");
    oss << "->";
    oss << "CreatePipelineLibrary(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLibraryBlob, "    ", false))
    {
        oss << "    " << "pLibraryBlob" << " /* value = " << static_cast<uint16_t>(*pLibraryBlob->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << BlobLength;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineLibrary, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineLibrary->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        HandlePointerDecoder<ID3D12Fence*>* ppFences,
        PointerDecoder<UINT64>* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        uint64_t hEvent)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device1");
    oss << "->";
    oss << "SetEventOnMultipleFenceCompletion(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppFences, "    ", false))
    {
        WriteArrayClassesString(oss, ppFences, "ID3D12Fence", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFenceValues, "    ", false))
    {
        WriteArrayValuesString(oss, pFenceValues, "    ", false);
    }
    oss << ",\n";

    oss << "    " << NumFences;
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_SetResidencyPriority(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device1");
    oss << "->";
    oss << "SetResidencyPriority(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPriorities, "    ", false))
    {
        WriteArrayConvertsString(oss, pPriorities, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device2_CreatePipelineState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device2");
    oss << "->";
    oss << "CreatePipelineState(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        WriteHandleId(oss, *ppPipelineState->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device3");
    oss << "->";
    oss << "OpenExistingHeapFromAddress(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << pAddress;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device3");
    oss << "->";
    oss << "OpenExistingHeapFromFileMapping(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << hFileMapping;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_EnqueueMakeResident(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        format::HandleId pFenceToSignal,
        UINT64 FenceValueToSignal)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device3");
    oss << "->";
    oss << "EnqueueMakeResident(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ",\n";

    WriteHandleId(oss, pFenceToSignal, "    ", "ID3D12Fence", false);
    oss << ",\n";

    oss << "    " << FenceValueToSignal;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12ProtectedSession");
    oss << "->";
    oss << "GetStatusFence(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFence, "    ", true))
    {
        WriteHandleId(oss, *ppFence->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12ProtectedSession");
    oss << "->";
    oss << "GetSessionStatus(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12ProtectedResourceSession");
    oss << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommandList1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "CreateCommandList1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << nodeMask;
    oss << ",\n";

    oss << "    " << ConverttoText(type);
    oss << ",\n";

    oss << "    " << ConverttoText(flags);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandList, "    ", true))
    {
        WriteHandleId(oss, *ppCommandList->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "CreateProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSession, "    ", true))
    {
        WriteHandleId(oss, *ppSession->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommittedResource1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "CreateCommittedResource1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pProtectedSession, "    ", "ID3D12ProtectedResourceSession", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateHeap1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "CreateHeap1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pProtectedSession, "    ", "ID3D12ProtectedResourceSession", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        WriteHandleId(oss, *ppvHeap->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateReservedResource1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "CreateReservedResource1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pProtectedSession, "    ", "ID3D12ProtectedResourceSession", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device4");
    oss << "->";
    oss << "GetResourceAllocationInfo1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << visibleMask;
    oss << ",\n";

    oss << "    " << numResourceDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceDescs, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceAllocationInfo1, "    ", true))
    {
        WriteArrayStructsString(oss, pResourceAllocationInfo1, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12LifetimeOwner");
    oss << "->";
    oss << "LifetimeStateUpdated(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(NewState);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_LUID return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SwapChainAssistant");
    oss << "->";
    oss << "GetLUID(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SwapChainAssistant");
    oss << "->";
    oss << "GetSwapChainObject(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppv, "    ", true))
    {
        WriteHandleId(oss, *ppv->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SwapChainAssistant");
    oss << "->";
    oss << "GetCurrentResourceAndCommandQueue(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riidQueue.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvQueue, "    ", true))
    {
        WriteHandleId(oss, *ppvQueue->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SwapChainAssistant");
    oss << "->";
    oss << "InsertImplicitSync(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pObject)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12LifetimeTracker");
    oss << "->";
    oss << "DestroyOwnedObject(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pObject, "    ", "ID3D12DeviceChild", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        PointerDecoder<uint8_t>* return_value,
        WStringDecoder* pExportName)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12StateObjectProperties");
    oss << "->";
    oss << "GetShaderIdentifier(\n    /* ";

    oss << "return = " ;
    if (WriteCheckPointerDecoderNull(oss, return_value, "                ", false))
    {
        oss << "return_value" << " /* value = " << static_cast<uint16_t>(*return_value->GetPointer()) << " */";
    }
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pExportName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pExportName->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        WStringDecoder* pExportName)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12StateObjectProperties");
    oss << "->";
    oss << "GetShaderStackSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pExportName, "    ", false))
    {
        oss << "    " << "\"" << util::interception::WideStringToString(pExportName->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12StateObjectProperties");
    oss << "->";
    oss << "GetPipelineStackSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12StateObjectProperties");
    oss << "->";
    oss << "SetPipelineStackSize(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << PipelineStackSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "CreateLifetimeTracker(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pOwner, "    ", "ID3D12LifetimeOwner", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvTracker, "    ", true))
    {
        WriteHandleId(oss, *ppvTracker->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_RemoveDevice(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "RemoveDevice(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "EnumerateMetaCommands(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pNumMetaCommands, "    ", false))
    {
        oss << "    " << *pNumMetaCommands->GetPointer();
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_META_COMMAND_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pDescs, "    ", true))
    {
        WriteArrayStructsString(oss, pDescs, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        PointerDecoder<UINT>* pTotalStructureSizeInBytes,
        PointerDecoder<UINT>* pParameterCount,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "EnumerateMetaCommandParameters(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*CommandId.decoded_value);
    oss << ",\n";

    oss << "    " << ConverttoText(Stage);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTotalStructureSizeInBytes, "    ", true))
    {
        oss << "    " << "&" << *pTotalStructureSizeInBytes->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pParameterCount, "    ", false))
    {
        oss << "    " << *pParameterCount->GetPointer();
    }
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_META_COMMAND_PARAMETER_DESC{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pParameterDescs, "    ", true))
    {
        WriteArrayStructsString(oss, pParameterDescs, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID CommandId,
        UINT NodeMask,
        PointerDecoder<uint8_t>* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppMetaCommand)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "CreateMetaCommand(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*CommandId.decoded_value);
    oss << ",\n";

    oss << "    " << NodeMask;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCreationParametersData, "    ", false))
    {
        oss << "    " << "pCreationParametersData" << " /* value = " << static_cast<uint16_t>(*pCreationParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << CreationParametersDataSizeInBytes;
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppMetaCommand, "    ", true))
    {
        WriteHandleId(oss, *ppMetaCommand->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "CreateStateObject(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppStateObject, "    ", true))
    {
        WriteHandleId(oss, *ppStateObject->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "GetRaytracingAccelerationStructurePrebuildInfo(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pInfo, "    ", true))
    {
        WriteStructString(oss, pInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device5");
    oss << "->";
    oss << "CheckDriverMatchingIdentifier(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(SerializedDataType);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pIdentifierToCheck, "    ", false))
    {
        WriteStructString(oss, pIdentifierToCheck->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedDataSettings");
    oss << "->";
    oss << "SetAutoBreadcrumbsEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedDataSettings");
    oss << "->";
    oss << "SetPageFaultEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedDataSettings");
    oss << "->";
    oss << "SetWatsonDumpEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedDataSettings1");
    oss << "->";
    oss << "SetBreadcrumbContextEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedData");
    oss << "->";
    oss << "GetAutoBreadcrumbsOutput(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedData");
    oss << "->";
    oss << "GetPageFaultAllocationOutput(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_DRED_PAGE_FAULT_OUTPUT{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedData1");
    oss << "->";
    oss << "GetAutoBreadcrumbsOutput1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DeviceRemovedExtendedData1");
    oss << "->";
    oss << "GetPageFaultAllocationOutput1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_DRED_PAGE_FAULT_OUTPUT1{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        uint64_t hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device6");
    oss << "->";
    oss << "SetBackgroundProcessingMode(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Mode);
    oss << ",\n";

    oss << "    " << ConverttoText(MeasurementsAction);
    oss << ",\n";

    oss << "    " << hEventToSignalUponCompletion;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pbFurtherMeasurementsDesired, "    ", true))
    {
        oss << "    " << "&" << *pbFurtherMeasurementsDesired->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12ProtectedResourceSession1");
    oss << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device7_AddToStateObject(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device7");
    oss << "->";
    oss << "AddToStateObject(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAddition, "    ", false))
    {
        WriteStructString(oss, pAddition->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pStateObjectToGrowFrom, "    ", "ID3D12StateObject", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppNewStateObject, "    ", true))
    {
        WriteHandleId(oss, *ppNewStateObject->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device7");
    oss << "->";
    oss << "CreateProtectedResourceSession1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSession, "    ", true))
    {
        WriteHandleId(oss, *ppSession->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device8");
    oss << "->";
    oss << "GetResourceAllocationInfo2(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << visibleMask;
    oss << ",\n";

    oss << "    " << numResourceDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceDescs, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceAllocationInfo1, "    ", true))
    {
        WriteArrayStructsString(oss, pResourceAllocationInfo1, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_CreateCommittedResource2(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device8");
    oss << "->";
    oss << "CreateCommittedResource2(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    WriteHandleId(oss, pProtectedSession, "    ", "ID3D12ProtectedResourceSession", false);
    oss << ",\n";

    oss << "    " << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_CreatePlacedResource1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device8");
    oss << "->";
    oss << "CreatePlacedResource1(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pHeap, "    ", "ID3D12Heap", false);
    oss << ",\n";

    oss << "    " << HeapOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        WriteHandleId(oss, *ppvResource->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pTargetedResource,
        format::HandleId pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device8");
    oss << "->";
    oss << "CreateSamplerFeedbackUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pTargetedResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    WriteHandleId(oss, pFeedbackResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Device8");
    oss << "->";
    oss << "GetCopyableFootprints1(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDesc, "    ", false))
    {
        WriteStructString(oss, pResourceDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << FirstSubresource;
    oss << ",\n";

    oss << "    " << NumSubresources;
    oss << ",\n";

    oss << "    " << BaseOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pLayouts, "    ", true))
    {
        WriteArrayStructsString(oss, pLayouts, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumRows, "    ", true))
    {
        WriteArrayValuesString(oss, pNumRows, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRowSizeInBytes, "    ", true))
    {
        WriteArrayValuesString(oss, pRowSizeInBytes, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTotalBytes, "    ", true))
    {
        oss << "    " << "&" << *pTotalBytes->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource1");
    oss << "->";
    oss << "GetProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppProtectedSession, "    ", true))
    {
        WriteHandleId(oss, *ppProtectedSession->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource2_GetDesc1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Resource2");
    oss << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &return_value, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Heap1");
    oss << "->";
    oss << "GetProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppProtectedSession, "    ", true))
    {
        WriteHandleId(oss, *ppProtectedSession->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pProtectedResourceSession)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList3");
    oss << "->";
    oss << "SetProtectedResourceSession(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pProtectedResourceSession, "    ", "ID3D12ProtectedResourceSession", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12MetaCommand");
    oss << "->";
    oss << "GetRequiredParameterResourceSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Stage);
    oss << ",\n";

    oss << "    " << ParameterIndex;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "BeginRenderPass(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << NumRenderTargets;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRenderTargets, "    ", false))
    {
        WriteArrayStructsString(oss, pRenderTargets, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDepthStencil, "    ", false))
    {
        WriteStructString(oss, pDepthStencil->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "EndRenderPass(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "InitializeMetaCommand(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pMetaCommand, "    ", "ID3D12MetaCommand", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pInitializationParametersData, "    ", false))
    {
        oss << "    " << "pInitializationParametersData" << " /* value = " << static_cast<uint16_t>(*pInitializationParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << InitializationParametersDataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "ExecuteMetaCommand(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pMetaCommand, "    ", "ID3D12MetaCommand", false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pExecutionParametersData, "    ", false))
    {
        oss << "    " << "pExecutionParametersData" << " /* value = " << static_cast<uint16_t>(*pExecutionParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << ExecutionParametersDataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "BuildRaytracingAccelerationStructure(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << NumPostbuildInfoDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPostbuildInfoDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pPostbuildInfoDescs, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "EmitRaytracingAccelerationStructurePostbuildInfo(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << NumSourceAccelerationStructures;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSourceAccelerationStructureData, "    ", false))
    {
        WriteArrayValuesString(oss, pSourceAccelerationStructureData, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "CopyRaytracingAccelerationStructure(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << DestAccelerationStructureData;
    oss << ",\n";

    oss << "    " << SourceAccelerationStructureData;
    oss << ",\n";

    oss << "    " << ConverttoText(Mode);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pStateObject)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "SetPipelineState1(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pStateObject, "    ", "ID3D12StateObject", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList4");
    oss << "->";
    oss << "DispatchRays(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bEnable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Tools");
    oss << "->";
    oss << "EnableShaderInstrumentation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Tools");
    oss << "->";
    oss << "ShaderInstrumentationEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList5");
    oss << "->";
    oss << "RSSetShadingRate(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(baseShadingRate);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, combiners, "    ", false))
    {
        WriteArrayConvertsString(oss, combiners, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId shadingRateImage)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList5");
    oss << "->";
    oss << "RSSetShadingRateImage(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, shadingRateImage, "    ", "ID3D12Resource", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12GraphicsCommandList6");
    oss << "->";
    oss << "DispatchMesh(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ThreadGroupCountX;
    oss << ",\n";

    oss << "    " << ThreadGroupCountY;
    oss << ",\n";

    oss << "    " << ThreadGroupCountZ;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferPointer(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        uint64_t return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D10Blob");
    oss << "->";
    oss << "GetBufferPointer(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        SIZE_T return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D10Blob");
    oss << "->";
    oss << "GetBufferSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3DDestructionNotifier");
    oss << "->";
    oss << "RegisterDestructionCallback(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "callbackFn /* address = " << callbackFn << " */";
    oss << ",\n";

    oss << "    " << pData;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCallbackID, "    ", true))
    {
        oss << "    " << "&" << *pCallbackID->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT callbackID)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3DDestructionNotifier");
    oss << "->";
    oss << "UnregisterDestructionCallback(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << callbackID;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D12Debug_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug");
    oss << "->";
    oss << "EnableDebugLayer(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug1");
    oss << "->";
    oss << "EnableDebugLayer(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug1");
    oss << "->";
    oss << "SetEnableGPUBasedValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug1");
    oss << "->";
    oss << "SetEnableSynchronizedCommandQueueValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug2");
    oss << "->";
    oss << "SetGPUBasedValidationFlags(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug3");
    oss << "->";
    oss << "SetEnableGPUBasedValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug3");
    oss << "->";
    oss << "SetEnableSynchronizedCommandQueueValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12Debug3");
    oss << "->";
    oss << "SetGPUBasedValidationFlags(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice1");
    oss << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice1");
    oss << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice1");
    oss << "->";
    oss << "ReportLiveDeviceObjects(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice");
    oss << "->";
    oss << "SetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Mask);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice");
    oss << "->";
    oss << "GetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_RLDO_FLAGS Flags)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice");
    oss << "->";
    oss << "ReportLiveDeviceObjects(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice2");
    oss << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugDevice2");
    oss << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandQueue");
    oss << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << Subresource;
    oss << ",\n";

    oss << "    " << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList1");
    oss << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << Subresource;
    oss << ",\n";

    oss << "    " << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList1");
    oss << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList1");
    oss << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList");
    oss << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << Subresource;
    oss << ",\n";

    oss << "    " << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_FEATURE Mask)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList");
    oss << "->";
    oss << "SetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Mask);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList");
    oss << "->";
    oss << "GetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << ConverttoText(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList2");
    oss << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12DebugCommandList2");
    oss << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_Present(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        uint64_t window)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SharingContract");
    oss << "->";
    oss << "Present(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pResource, "    ", "ID3D12Resource", false);
    oss << ",\n";

    oss << "    " << Subresource;
    oss << ",\n";

    oss << "    " << window;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        format::HandleId pFence,
        UINT64 FenceValue)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SharingContract");
    oss << "->";
    oss << "SharedFenceSignal(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteHandleId(oss, pFence, "    ", "ID3D12Fence", false);
    oss << ",\n";

    oss << "    " << FenceValue;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SharingContract");
    oss << "->";
    oss << "BeginCapturableWork(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*guid.decoded_value);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_EndCapturableWork(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        Decoded_GUID guid)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12SharingContract");
    oss << "->";
    oss << "EndCapturableWork(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*guid.decoded_value);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageCountLimit)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "SetMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << MessageCountLimit;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "ClearStoredMessages(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        UINT64 MessageIndex,
        StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
        PointerDecoder<SIZE_T>* pMessageByteLength)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetMessage(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << MessageIndex;
    oss << ",\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_MESSAGE{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pMessage, "    ", true))
    {
        WriteArrayStructsString(oss, pMessage, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMessageByteLength, "    ", false))
    {
        oss << "    " << *pMessageByteLength->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetNumMessagesAllowedByStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetNumMessagesDeniedByStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetNumStoredMessages(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetNumStoredMessagesAllowedByRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetNumMessagesDiscardedByMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT64 return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "AddStorageFilterEntries(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", false))
    {
        WriteStructString(oss, pFilter->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_INFO_QUEUE_FILTER{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", true))
    {
        WriteArrayStructsString(oss, pFilter, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFilterByteLength, "    ", false))
    {
        oss << "    " << *pFilterByteLength->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "ClearStorageFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushEmptyStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushCopyOfStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", false))
    {
        WriteStructString(oss, pFilter->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PopStorageFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetStorageFilterStackSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "AddRetrievalFilterEntries(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", false))
    {
        WriteStructString(oss, pFilter->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (return_value != S_OK)
    {
        oss << "    " << "/* out */ D3D12_INFO_QUEUE_FILTER{/* not encoded due to return value */}";
    }
    else if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", true))
    {
        WriteArrayStructsString(oss, pFilter, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFilterByteLength, "    ", false))
    {
        oss << "    " << *pFilterByteLength->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "ClearRetrievalFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushEmptyRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushCopyOfRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PushRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", false))
    {
        WriteStructString(oss, pFilter->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
        const ApiCallInfo& call_info,
        format::HandleId object_id)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "PopRetrievalFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        UINT return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetRetrievalFilterStackSize(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        StringDecoder* pDescription)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "AddMessage(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Category);
    oss << ",\n";

    oss << "    " << ConverttoText(Severity);
    oss << ",\n";

    oss << "    " << ConverttoText(ID);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDescription, "    ", false))
    {
        oss << "    " << "\"" << pDescription->GetPointer() << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        StringDecoder* pDescription)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "AddApplicationMessage(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Severity);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDescription, "    ", false))
    {
        oss << "    " << "\"" << pDescription->GetPointer() << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "SetBreakOnCategory(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Category);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "SetBreakOnSeverity(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Severity);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        D3D12_MESSAGE_ID ID,
        BOOL bEnable)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "SetBreakOnID(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(ID);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_CATEGORY Category)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetBreakOnCategory(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Category);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_SEVERITY Severity)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetBreakOnSeverity(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(Severity);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value,
        D3D12_MESSAGE_ID ID)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetBreakOnID(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(ID);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL bMute)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "SetMuteDebugOutput(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, bMute, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        BOOL return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "ID3D12InfoQueue");
    oss << "->";
    oss << "GetMuteDebugOutput(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, return_value, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IUnknown_QueryInterface(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        HRESULT return_value,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IUnknown");
    oss << "->";
    oss << "QueryInterface(\n    /* ";

    oss << "return = " ;
    oss << enumutil::GetResultValueString(return_value);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvObject, "    ", true))
    {
        WriteHandleId(oss, *ppvObject->GetPointer(), "    ", "void", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IUnknown_AddRef(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IUnknown");
    oss << "->";
    oss << "AddRef(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IUnknown_Release(
        const ApiCallInfo& call_info,
        format::HandleId object_id,
        ULONG return_value)
{
    std::ostringstream oss;
    WriteHandleId(oss, object_id, "", "IUnknown");
    oss << "->";
    oss << "Release(\n    /* ";

    oss << "return = " ;
    oss << return_value;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}




GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
