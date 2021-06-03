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
        oss << indent2 << *value->pBits.GetPointer() << " /* address = " << value->pBits.GetPointer() << " */";
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
    oss << indent2 << "ID3D12RootSignature_id" << value->pRootSignature;
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
    oss << indent2 << "ID3D12RootSignature_id" << value->pRootSignature;
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
    oss << indent2 << "ID3D12Resource_id" << value->pResource;
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
    oss << indent2 << "ID3D12Resource_id" << value->pResourceBefore;
    oss << ",\n";

    oss << indent2 << "ID3D12Resource_id" << value->pResourceAfter;
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
    oss << indent2 << "ID3D12Resource_id" << value->pResource;
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
    oss << indent2 << "ID3D12RootSignature_id" << value->pGlobalRootSignature;
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
    oss << indent2 << "ID3D12RootSignature_id" << value->pLocalRootSignature;
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
    oss << indent2 << "ID3D12StateObject_id" << value->pExistingCollection;
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

    oss << indent2 << "ID3D12GraphicsCommandList_id" << value->pCommandList;
    oss << ",\n";

    oss << indent2 << "ID3D12CommandQueue_id" << value->pCommandQueue;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BreadcrumbCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pLastBreadcrumbValue, indent2.c_str()))
    {
        oss << indent2 << *value->pLastBreadcrumbValue.GetPointer() << " /* address = " << value->pLastBreadcrumbValue.GetPointer() << " */";
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

    oss << indent2 << "ID3D12GraphicsCommandList_id" << value->pCommandList;
    oss << ",\n";

    oss << indent2 << "ID3D12CommandQueue_id" << value->pCommandQueue;
    oss << ",\n";

    oss << indent2 << value->decoded_value->BreadcrumbCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, &value->pLastBreadcrumbValue, indent2.c_str()))
    {
        oss << indent2 << *value->pLastBreadcrumbValue.GetPointer() << " /* address = " << value->pLastBreadcrumbValue.GetPointer() << " */";
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

    oss << indent2 << "IUnknown_id" << value->pObject;
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
    oss << indent2 << "ID3D12Resource_id" << value->pSrcResource;
    oss << ",\n";

    oss << indent2 << "ID3D12Resource_id" << value->pDstResource;
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
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppFactory->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_CreateDXGIFactory1(
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppFactory->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    oss << "IDXGIObject_id" << object_id << "->";
    oss << "SetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        format::HandleId pUnknown)
{
    std::ostringstream oss;
    oss << "IDXGIObject_id" << object_id << "->";
    oss << "SetPrivateDataInterface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    oss << "    " << "" << pUnknown;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIObject_GetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    oss << "IDXGIObject_id" << object_id << "->";
    oss << "GetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*Name.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDataSize, "    ", false))
    {
        oss << "    " << "" << *pDataSize->GetPointer() << " /* address = " << pDataSize->GetPointer() << " */";
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
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent)
{
    std::ostringstream oss;
    oss << "IDXGIObject_id" << object_id << "->";
    oss << "GetParent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppParent, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppParent->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDeviceSubObject_GetDevice(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    std::ostringstream oss;
    oss << "IDXGIDeviceSubObject_id" << object_id << "->";
    oss << "GetDevice(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDevice, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppDevice->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_GetSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint64_t, void*>* pSharedHandle)
{
    std::ostringstream oss;
    oss << "IDXGIResource_id" << object_id << "->";
    oss << "GetSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<DXGI_USAGE>* pUsage)
{
    std::ostringstream oss;
    oss << "IDXGIResource_id" << object_id << "->";
    oss << "GetUsage(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pUsage, "    ", false))
    {
        oss << "    " << "" << *pUsage->GetPointer() << " /* address = " << pUsage->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_SetEvictionPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT EvictionPriority)
{
    std::ostringstream oss;
    oss << "IDXGIResource_id" << object_id << "->";
    oss << "SetEvictionPriority(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << EvictionPriority;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource_GetEvictionPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pEvictionPriority)
{
    std::ostringstream oss;
    oss << "IDXGIResource_id" << object_id << "->";
    oss << "GetEvictionPriority(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pEvictionPriority, "    ", true))
    {
        oss << "    " << "&" << *pEvictionPriority->GetPointer() << " /* address = " << pEvictionPriority->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_AcquireSync(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Key,
        DWORD dwMilliseconds)
{
    std::ostringstream oss;
    oss << "IDXGIKeyedMutex_id" << object_id << "->";
    oss << "AcquireSync(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Key;
    oss << ",\n";

    oss << "    " << "" << dwMilliseconds;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Key)
{
    std::ostringstream oss;
    oss << "IDXGIKeyedMutex_id" << object_id << "->";
    oss << "ReleaseSync(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Key;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGISurface_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_Map(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags)
{
    std::ostringstream oss;
    oss << "IDXGISurface_id" << object_id << "->";
    oss << "Map(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLockedRect, "    ", true))
    {
        WriteStructString(oss, pLockedRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    oss << "    " << "" << MapFlags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface_Unmap(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGISurface_id" << object_id << "->";
    oss << "Unmap(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface1_GetDC(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Discard,
        PointerDecoder<uint64_t, void*>* phdc)
{
    std::ostringstream oss;
    oss << "IDXGISurface1_id" << object_id << "->";
    oss << "GetDC(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect)
{
    std::ostringstream oss;
    oss << "IDXGISurface1_id" << object_id << "->";
    oss << "ReleaseDC(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter_id" << object_id << "->";
    oss << "EnumOutputs(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Output;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutput, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutput_id" << *ppOutput->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter_id" << object_id << "->";
    oss << "CheckInterfaceSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*InterfaceName.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pUMDVersion, "    ", true))
    {
        oss << "    " << "&" << pUMDVersion->GetPointer()->QuadPart;
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplayModeList(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetDisplayModeList(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(EnumFormat);
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumModes, "    ", false))
    {
        oss << "    " << "" << *pNumModes->GetPointer() << " /* address = " << pNumModes->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteArrayStructsString(oss, pDesc, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "FindClosestMatchingMode(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pModeToMatch, "    ", false))
    {
        WriteStructString(oss, pModeToMatch->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestMatch, "    ", true))
    {
        WriteStructString(oss, pClosestMatch->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    oss << "    " << "" << pConcernedDevice;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_WaitForVBlank(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "WaitForVBlank(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_TakeOwnership(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        BOOL Exclusive)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "TakeOwnership(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    WriteBOOLString(oss, Exclusive, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_ReleaseOwnership(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "ReleaseOwnership(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetGammaControlCapabilities(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pGammaCaps, "    ", true))
    {
        WriteStructString(oss, pGammaCaps->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_SetGammaControl(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "SetGammaControl(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetGammaControl(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pArray, "    ", true))
    {
        WriteStructString(oss, pArray->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_SetDisplaySurface(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pScanoutSurface)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "SetDisplaySurface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pScanoutSurface;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDestination)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetDisplaySurfaceData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDestination;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    std::ostringstream oss;
    oss << "IDXGIOutput_id" << object_id << "->";
    oss << "GetFrameStatistics(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_Present(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT SyncInterval,
        UINT Flags)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "Present(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << SyncInterval;
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetBuffer(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetBuffer(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Buffer;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppSurface->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_SetFullscreenState(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Fullscreen,
        format::HandleId pTarget)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "SetFullscreenState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Fullscreen, "    ", false);
    oss << ",\n";

    oss << "    " << "" << pTarget;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFullscreenState(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetFullscreenState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFullscreen, "    ", true))
    {
        oss << "    " << "&" << *pFullscreen->GetPointer() << " /* address = " << pFullscreen->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppTarget, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutput_id" << *ppTarget->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeBuffers(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "ResizeBuffers(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << BufferCount;
    oss << ",\n";

    oss << "    " << "" << Width;
    oss << ",\n";

    oss << "    " << "" << Height;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(NewFormat);
    oss << ",\n";

    oss << "    " << "" << SwapChainFlags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_ResizeTarget(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "ResizeTarget(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetContainingOutput(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutput, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutput_id" << *ppOutput->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetFrameStatistics(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain_GetLastPresentCount(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pLastPresentCount)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain_id" << object_id << "->";
    oss << "GetLastPresentCount(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLastPresentCount, "    ", true))
    {
        oss << "    " << "&" << *pLastPresentCount->GetPointer() << " /* address = " << pLastPresentCount->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_EnumAdapters(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory_id" << object_id << "->";
    oss << "EnumAdapters(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Adapter;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        oss << "    " << "&" << "IDXGIAdapter_id" << *ppAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_MakeWindowAssociation(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t WindowHandle,
        UINT Flags)
{
    std::ostringstream oss;
    oss << "IDXGIFactory_id" << object_id << "->";
    oss << "MakeWindowAssociation(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << WindowHandle;
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_GetWindowAssociation(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint64_t, void*>* pWindowHandle)
{
    std::ostringstream oss;
    oss << "IDXGIFactory_id" << object_id << "->";
    oss << "GetWindowAssociation(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactory_id" << object_id << "->";
    oss << "CreateSwapChain(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGISwapChain_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory_id" << object_id << "->";
    oss << "CreateSoftwareAdapter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Module;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        oss << "    " << "&" << "IDXGIAdapter_id" << *ppAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_GetAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIDevice_id" << object_id << "->";
    oss << "GetAdapter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAdapter, "    ", true))
    {
        oss << "    " << "&" << "IDXGIAdapter_id" << *pAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_CreateSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
        HandlePointerDecoder<IDXGISurface*>* ppSurface)
{
    std::ostringstream oss;
    oss << "IDXGIDevice_id" << object_id << "->";
    oss << "CreateSurface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << NumSurfaces;
    oss << ",\n";

    oss << "    " << "" << Usage;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSharedResource, "    ", false))
    {
        WriteStructString(oss, pSharedResource->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        oss << "    " << "&" << "IDXGISurface_id" << *ppSurface->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_QueryResourceResidency(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources)
{
    std::ostringstream oss;
    oss << "IDXGIDevice_id" << object_id << "->";
    oss << "QueryResourceResidency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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

    oss << "    " << "" << NumResources;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        INT Priority)
{
    std::ostringstream oss;
    oss << "IDXGIDevice_id" << object_id << "->";
    oss << "SetGPUThreadPriority(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Priority;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<INT>* pPriority)
{
    std::ostringstream oss;
    oss << "IDXGIDevice_id" << object_id << "->";
    oss << "GetGPUThreadPriority(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pPriority, "    ", true))
    {
        oss << "    " << "&" << *pPriority->GetPointer() << " /* address = " << pPriority->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory1_EnumAdapters1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory1_id" << object_id << "->";
    oss << "EnumAdapters1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Adapter;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppAdapter, "    ", true))
    {
        oss << "    " << "&" << "IDXGIAdapter1_id" << *ppAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory1_IsCurrent(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIFactory1_id" << object_id << "->";
    oss << "IsCurrent(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter1_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter1_id" << object_id << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MaxLatency)
{
    std::ostringstream oss;
    oss << "IDXGIDevice1_id" << object_id << "->";
    oss << "SetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << MaxLatency;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pMaxLatency)
{
    std::ostringstream oss;
    oss << "IDXGIDevice1_id" << object_id << "->";
    oss << "GetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMaxLatency, "    ", true))
    {
        oss << "    " << "&" << *pMaxLatency->GetPointer() << " /* address = " << pMaxLatency->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIDisplayControl_id" << object_id << "->";
    oss << "IsStereoEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
        format::HandleId object_id,
        BOOL enabled)
{
    std::ostringstream oss;
    oss << "IDXGIDisplayControl_id" << object_id << "->";
    oss << "SetStereoEnabled(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, enabled, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
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
        format::HandleId object_id,
        HRESULT returnValue,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "AcquireNextFrame(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << TimeoutInMilliseconds;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFrameInfo, "    ", true))
    {
        WriteStructString(oss, pFrameInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDesktopResource, "    ", true))
    {
        oss << "    " << "&" << "IDXGIResource_id" << *ppDesktopResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "GetFrameDirtyRects(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << DirtyRectsBufferSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDirtyRectsBuffer, "    ", true))
    {
        WriteArrayStructsString(oss, pDirtyRectsBuffer, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDirtyRectsBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pDirtyRectsBufferSizeRequired->GetPointer() << " /* address = " << pDirtyRectsBufferSizeRequired->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "GetFrameMoveRects(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << MoveRectsBufferSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMoveRectBuffer, "    ", true))
    {
        WriteArrayStructsString(oss, pMoveRectBuffer, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMoveRectsBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pMoveRectsBufferSizeRequired->GetPointer() << " /* address = " << pMoveRectsBufferSizeRequired->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "GetFramePointerShape(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << PointerShapeBufferSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPointerShapeBuffer, "    ", true))
    {
        oss << "    " << "&" << "pPointerShapeBuffer" << " /* value = " << static_cast<uint16_t>(*pPointerShapeBuffer->GetPointer()) << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPointerShapeBufferSizeRequired, "    ", true))
    {
        oss << "    " << "&" << *pPointerShapeBufferSizeRequired->GetPointer() << " /* address = " << pPointerShapeBufferSizeRequired->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPointerShapeInfo, "    ", true))
    {
        WriteStructString(oss, pPointerShapeInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "MapDesktopSurface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLockedRect, "    ", true))
    {
        WriteStructString(oss, pLockedRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "UnMapDesktopSurface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIOutputDuplication_id" << object_id << "->";
    oss << "ReleaseFrame(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISurface2_GetResource(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex)
{
    std::ostringstream oss;
    oss << "IDXGISurface2_id" << object_id << "->";
    oss << "GetResource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppParentResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppParentResource->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSubresourceIndex, "    ", true))
    {
        oss << "    " << "&" << *pSubresourceIndex->GetPointer() << " /* address = " << pSubresourceIndex->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface)
{
    std::ostringstream oss;
    oss << "IDXGIResource1_id" << object_id << "->";
    oss << "CreateSubresourceSurface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << index;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSurface, "    ", true))
    {
        oss << "    " << "&" << "IDXGISurface2_id" << *ppSurface->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIResource1_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    std::ostringstream oss;
    oss << "IDXGIResource1_id" << object_id << "->";
    oss << "CreateSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAttributes, "    ", false))
    {
        WriteStructString(oss, pAttributes->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << dwAccess;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, lpName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(lpName->GetPointer()) << "\"";
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
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    std::ostringstream oss;
    oss << "IDXGIDevice2_id" << object_id << "->";
    oss << "OfferResources(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Priority);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice2_ReclaimResources(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded)
{
    std::ostringstream oss;
    oss << "IDXGIDevice2_id" << object_id << "->";
    oss << "ReclaimResources(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumResources;
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
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent)
{
    std::ostringstream oss;
    oss << "IDXGIDevice2_id" << object_id << "->";
    oss << "EnqueueSetEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetFullscreenDesc(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetHwnd(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint64_t, void*>* pHwnd)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetHwnd(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetCoreWindow(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*refiid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppUnk, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppUnk->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_Present1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "Present1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << SyncInterval;
    oss << ",\n";

    oss << "    " << "" << PresentFlags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPresentParameters, "    ", false))
    {
        WriteStructString(oss, pPresentParameters->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "IsTemporaryMonoSupported(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetRestrictToOutput(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppRestrictToOutput, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutput_id" << *ppRestrictToOutput->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "SetBackgroundColor(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetBackgroundColor(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pColor, "    ", true))
    {
        WriteStructString(oss, pColor->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_SetRotation(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_MODE_ROTATION Rotation)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "SetRotation(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Rotation);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain1_GetRotation(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain1_id" << object_id << "->";
    oss << "GetRotation(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "IsWindowedStereoEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        uint64_t hWnd,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "CreateSwapChainForHwnd(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    oss << "    " << "" << hWnd;
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

    oss << "    " << "" << pRestrictToOutput;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGISwapChain1_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        format::HandleId pWindow,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "CreateSwapChainForCoreWindow(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    oss << "    " << "" << pWindow;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pRestrictToOutput;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGISwapChain1_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "GetSharedResourceAdapterLuid(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pLuid, "    ", true))
    {
        WriteStructString(oss, pLuid->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "RegisterStereoStatusWindow(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << WindowHandle;
    oss << ",\n";

    oss << "    " << "" << wMsg;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "RegisterStereoStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "UnregisterStereoStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "RegisterOcclusionStatusWindow(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << WindowHandle;
    oss << ",\n";

    oss << "    " << "" << wMsg;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "RegisterOcclusionStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "UnregisterOcclusionStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactory2_id" << object_id << "->";
    oss << "CreateSwapChainForComposition(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pRestrictToOutput;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGISwapChain1_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter2_GetDesc2(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter2_id" << object_id << "->";
    oss << "GetDesc2(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIOutput1_id" << object_id << "->";
    oss << "GetDisplayModeList1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(EnumFormat);
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumModes, "    ", false))
    {
        oss << "    " << "" << *pNumModes->GetPointer() << " /* address = " << pNumModes->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteArrayStructsString(oss, pDesc, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        format::HandleId pConcernedDevice)
{
    std::ostringstream oss;
    oss << "IDXGIOutput1_id" << object_id << "->";
    oss << "FindClosestMatchingMode1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pModeToMatch, "    ", false))
    {
        WriteStructString(oss, pModeToMatch->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestMatch, "    ", true))
    {
        WriteStructString(oss, pClosestMatch->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ",\n";

    oss << "    " << "" << pConcernedDevice;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDestination)
{
    std::ostringstream oss;
    oss << "IDXGIOutput1_id" << object_id << "->";
    oss << "GetDisplaySurfaceData1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDestination;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput1_DuplicateOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    std::ostringstream oss;
    oss << "IDXGIOutput1_id" << object_id << "->";
    oss << "DuplicateOutput(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutputDuplication, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutputDuplication_id" << *ppOutputDuplication->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_CreateDXGIFactory2(
        HRESULT returnValue,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory)
{
    std::ostringstream oss;
    oss << "CreateDXGIFactory2(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Flags;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFactory, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppFactory->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_DXGIGetDebugInterface1(
        HRESULT returnValue,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug)
{
    std::ostringstream oss;
    oss << "DXGIGetDebugInterface1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Flags;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDebug, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *pDebug->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice3_Trim(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "IDXGIDevice3_id" << object_id << "->";
    oss << "Trim(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetSourceSize(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Width,
        UINT Height)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "SetSourceSize(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Width;
    oss << ",\n";

    oss << "    " << "" << Height;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetSourceSize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "GetSourceSize(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pWidth, "    ", true))
    {
        oss << "    " << "&" << *pWidth->GetPointer() << " /* address = " << pWidth->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeight, "    ", true))
    {
        oss << "    " << "&" << *pHeight->GetPointer() << " /* address = " << pHeight->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MaxLatency)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "SetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << MaxLatency;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pMaxLatency)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "GetMaximumFrameLatency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMaxLatency, "    ", true))
    {
        oss << "    " << "&" << *pMaxLatency->GetPointer() << " /* address = " << pMaxLatency->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        format::HandleId object_id,
        uint64_t returnValue)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "GetFrameLatencyWaitableObject(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "SetMatrixTransform(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain2_id" << object_id << "->";
    oss << "GetMatrixTransform(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pMatrix, "    ", true))
    {
        WriteStructString(oss, pMatrix->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput2_SupportsOverlays(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIOutput2_id" << object_id << "->";
    oss << "SupportsOverlays(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory3_GetCreationFlags(
        format::HandleId object_id,
        UINT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIFactory3_id" << object_id << "->";
    oss << "GetCreationFlags(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "PresentBuffer(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << BufferToPresent;
    oss << ",\n";

    oss << "    " << "" << SyncInterval;
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "SetSourceRect(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "SetTargetRect(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Width,
        UINT Height)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "SetDestSize(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Width;
    oss << ",\n";

    oss << "    " << "" << Height;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "GetSourceRect(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRect, "    ", true))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "GetTargetRect(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRect, "    ", true))
    {
        WriteStructString(oss, pRect->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "GetDestSize(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pWidth, "    ", true))
    {
        oss << "    " << "&" << *pWidth->GetPointer() << " /* address = " << pWidth->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pHeight, "    ", true))
    {
        oss << "    " << "&" << *pHeight->GetPointer() << " /* address = " << pHeight->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "SetColorSpace(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(ColorSpace);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS returnValue)
{
    std::ostringstream oss;
    oss << "IDXGIDecodeSwapChain_id" << object_id << "->";
    oss << "GetColorSpace(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactoryMedia_id" << object_id << "->";
    oss << "CreateSwapChainForCompositionSurfaceHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    oss << "    " << "" << hSurface;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pRestrictToOutput;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGISwapChain1_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        uint64_t hSurface,
        StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
        format::HandleId pYuvDecodeBuffers,
        format::HandleId pRestrictToOutput,
        HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain)
{
    std::ostringstream oss;
    oss << "IDXGIFactoryMedia_id" << object_id << "->";
    oss << "CreateDecodeSwapChainForCompositionSurfaceHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    oss << "    " << "" << hSurface;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pYuvDecodeBuffers;
    oss << ",\n";

    oss << "    " << "" << pRestrictToOutput;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSwapChain, "    ", true))
    {
        oss << "    " << "&" << "IDXGIDecodeSwapChain_id" << *ppSwapChain->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    std::ostringstream oss;
    oss << "IDXGISwapChainMedia_id" << object_id << "->";
    oss << "GetFrameStatisticsMedia(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pStats, "    ", true))
    {
        WriteStructString(oss, pStats->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Duration)
{
    std::ostringstream oss;
    oss << "IDXGISwapChainMedia_id" << object_id << "->";
    oss << "SetPresentDuration(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Duration;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration)
{
    std::ostringstream oss;
    oss << "IDXGISwapChainMedia_id" << object_id << "->";
    oss << "CheckPresentDurationSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << DesiredPresentDuration;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestSmallerPresentDuration, "    ", true))
    {
        oss << "    " << "&" << *pClosestSmallerPresentDuration->GetPointer() << " /* address = " << pClosestSmallerPresentDuration->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pClosestLargerPresentDuration, "    ", true))
    {
        oss << "    " << "&" << *pClosestLargerPresentDuration->GetPointer() << " /* address = " << pClosestLargerPresentDuration->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    oss << "IDXGIOutput3_id" << object_id << "->";
    oss << "CheckOverlaySupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(EnumFormat);
    oss << ",\n";

    oss << "    " << "" << pConcernedDevice;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer() << " /* address = " << pFlags->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        format::HandleId object_id,
        UINT returnValue)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain3_id" << object_id << "->";
    oss << "GetCurrentBackBufferIndex(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain3_id" << object_id << "->";
    oss << "CheckColorSpaceSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(ColorSpace);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pColorSpaceSupport, "    ", true))
    {
        oss << "    " << "&" << *pColorSpaceSupport->GetPointer() << " /* address = " << pColorSpaceSupport->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_SetColorSpace1(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain3_id" << object_id << "->";
    oss << "SetColorSpace1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(ColorSpace);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        PointerDecoder<UINT>* pCreationNodeMask,
        HandlePointerDecoder<IUnknown*>* ppPresentQueue)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain3_id" << object_id << "->";
    oss << "ResizeBuffers1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << BufferCount;
    oss << ",\n";

    oss << "    " << "" << Width;
    oss << ",\n";

    oss << "    " << "" << Height;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << "" << SwapChainFlags;
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
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        format::HandleId pConcernedDevice,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    oss << "IDXGIOutput4_id" << object_id << "->";
    oss << "CheckOverlayColorSpaceSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(ColorSpace);
    oss << ",\n";

    oss << "    " << "" << pConcernedDevice;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer() << " /* address = " << pFlags->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory4_id" << object_id << "->";
    oss << "EnumAdapterByLuid(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &AdapterLuid, "    ", false, false);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory4_id" << object_id << "->";
    oss << "EnumWarpAdapter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "RegisterHardwareContentProtectionTeardownStatusEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "UnregisterHardwareContentProtectionTeardownStatus(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "QueryVideoMemoryInfo(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NodeIndex;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(MemorySegmentGroup);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pVideoMemoryInfo, "    ", true))
    {
        WriteStructString(oss, pVideoMemoryInfo->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "SetVideoMemoryReservation(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NodeIndex;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(MemorySegmentGroup);
    oss << ",\n";

    oss << "    " << "" << Reservation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "RegisterVideoMemoryBudgetChangeNotificationEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        format::HandleId object_id,
        DWORD dwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter3_id" << object_id << "->";
    oss << "UnregisterVideoMemoryBudgetChangeNotification(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IDXGIOutput5_DuplicateOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        PointerDecoder<DXGI_FORMAT>* pSupportedFormats,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    std::ostringstream oss;
    oss << "IDXGIOutput5_id" << object_id << "->";
    oss << "DuplicateOutput1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDevice;
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ",\n";

    oss << "    " << "" << SupportedFormatsCount;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSupportedFormats, "    ", false))
    {
        WriteArrayConvertsString(oss, pSupportedFormats, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppOutputDuplication, "    ", true))
    {
        oss << "    " << "&" << "IDXGIOutputDuplication_id" << *ppOutputDuplication->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData)
{
    std::ostringstream oss;
    oss << "IDXGISwapChain4_id" << object_id << "->";
    oss << "SetHDRMetaData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << "" << Size;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMetaData, "    ", false))
    {
        oss << "    " << "" << "pMetaData" << " /* value = " << static_cast<uint16_t>(*pMetaData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice4_OfferResources1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags)
{
    std::ostringstream oss;
    oss << "IDXGIDevice4_id" << object_id << "->";
    oss << "OfferResources1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumResources;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppResources, "    ", false))
    {
        WriteArrayClassesString(oss, ppResources, "IDXGIResource", "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Priority);
    oss << ",\n";

    oss << "    " << "" << Flags;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIDevice4_ReclaimResources1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    std::ostringstream oss;
    oss << "IDXGIDevice4_id" << object_id << "->";
    oss << "ReclaimResources1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumResources;
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
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "DXGIDeclareAdapterRemovalSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIAdapter4_GetDesc3(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIAdapter4_id" << object_id << "->";
    oss << "GetDesc3(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput6_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    std::ostringstream oss;
    oss << "IDXGIOutput6_id" << object_id << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", true))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pFlags)
{
    std::ostringstream oss;
    oss << "IDXGIOutput6_id" << object_id << "->";
    oss << "CheckHardwareCompositionSupport(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFlags, "    ", true))
    {
        oss << "    " << "&" << *pFlags->GetPointer() << " /* address = " << pFlags->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter)
{
    std::ostringstream oss;
    oss << "IDXGIFactory6_id" << object_id << "->";
    oss << "EnumAdapterByGpuPreference(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Adapter;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(GpuPreference);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvAdapter, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvAdapter->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hEvent,
        PointerDecoder<DWORD>* pdwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory7_id" << object_id << "->";
    oss << "RegisterAdaptersChangedEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hEvent;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pdwCookie, "    ", true))
    {
        oss << "    " << "&" << *pdwCookie->GetPointer() << " /* address = " << pdwCookie->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        DWORD dwCookie)
{
    std::ostringstream oss;
    oss << "IDXGIFactory7_id" << object_id << "->";
    oss << "UnregisterAdaptersChangedEvent(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << dwCookie;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_D3D12SerializeRootSignature(
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    std::ostringstream oss;
    oss << "D3D12SerializeRootSignature(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRootSignature, "    ", false))
    {
        WriteStructString(oss, pRootSignature->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Version);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        oss << "    " << "&" << "ID3D10Blob_id" << *ppBlob->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppErrorBlob, "    ", true))
    {
        oss << "    " << "&" << "ID3D10Blob_id" << *ppErrorBlob->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateRootSignatureDeserializer(
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    std::ostringstream oss;
    oss << "D3D12CreateRootSignatureDeserializer(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "" << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << SrcDataSizeInBytes;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*pRootSignatureDeserializerInterface.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppRootSignatureDeserializer, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppRootSignatureDeserializer->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12SerializeVersionedRootSignature(
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob)
{
    std::ostringstream oss;
    oss << "D3D12SerializeVersionedRootSignature(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pRootSignature, "    ", false))
    {
        WriteStructString(oss, pRootSignature->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        oss << "    " << "&" << "ID3D10Blob_id" << *ppBlob->GetPointer();
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppErrorBlob, "    ", true))
    {
        oss << "    " << "&" << "ID3D10Blob_id" << *ppErrorBlob->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer)
{
    std::ostringstream oss;
    oss << "D3D12CreateVersionedRootSignatureDeserializer(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "" << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << SrcDataSizeInBytes;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*pRootSignatureDeserializerInterface.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppRootSignatureDeserializer, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppRootSignatureDeserializer->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12CreateDevice(
        HRESULT returnValue,
        format::HandleId pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice)
{
    std::ostringstream oss;
    oss << "D3D12CreateDevice(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pAdapter;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(MinimumFeatureLevel);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDevice, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppDevice->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12GetDebugInterface(
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug)
{
    std::ostringstream oss;
    oss << "D3D12GetDebugInterface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvDebug, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvDebug->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_D3D12EnableExperimentalFeatures(
        HRESULT returnValue,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes)
{
    std::ostringstream oss;
    oss << "D3D12EnableExperimentalFeatures(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumFeatures;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pIIDs, "    ", false))
    {
        WriteArrayConvertsString(oss, pIIDs, "    ", false);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pConfigurationStructs, "    ", false))
    {
        oss << "    " << "" << "pConfigurationStructs" << " /* value = " << static_cast<uint16_t>(*pConfigurationStructs->GetPointer()) << " */";
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
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    oss << "ID3D12Object_id" << object_id << "->";
    oss << "GetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDataSize, "    ", false))
    {
        oss << "    " << "" << *pDataSize->GetPointer() << " /* address = " << pDataSize->GetPointer() << " */";
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
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData)
{
    std::ostringstream oss;
    oss << "ID3D12Object_id" << object_id << "->";
    oss << "SetPrivateData(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        format::HandleId pData)
{
    std::ostringstream oss;
    oss << "ID3D12Object_id" << object_id << "->";
    oss << "SetPrivateDataInterface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*guid.decoded_value);
    oss << ",\n";

    oss << "    " << "" << pData;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Object_SetName(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* Name)
{
    std::ostringstream oss;
    oss << "ID3D12Object_id" << object_id << "->";
    oss << "SetName(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceChild_GetDevice(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceChild_id" << object_id << "->";
    oss << "GetDevice(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvDevice, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvDevice->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12RootSignatureDeserializer_id" << object_id << "->";
    oss << "GetRootSignatureDesc(\n    /* ";

    oss << "return = " ;
    if (WriteCheckPointerDecoderNull(oss, returnValue, "                ", false))
    {
        WriteStructString(oss, returnValue->GetMetaStructPointer(), "                ", true, false);
    }
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC*>* ppDesc)
{
    std::ostringstream oss;
    oss << "ID3D12VersionedRootSignatureDeserializer_id" << object_id << "->";
    oss << "GetRootSignatureDescAtVersion(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(convertToVersion);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDesc, "    ", true))
    {
        WriteStructString(oss, *ppDesc->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12VersionedRootSignatureDeserializer_id" << object_id << "->";
    oss << "GetUnconvertedRootSignatureDesc(\n    /* ";

    oss << "return = " ;
    if (WriteCheckPointerDecoderNull(oss, returnValue, "                ", false))
    {
        WriteStructString(oss, returnValue->GetMetaStructPointer(), "                ", true, false);
    }
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Heap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Heap_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_Map(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "Map(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Subresource;
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
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "Unmap(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Subresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pWrittenRange, "    ", false))
    {
        WriteStructString(oss, pWrittenRange->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "GetGPUVirtualAddress(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_WriteToSubresource(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DstSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
        uint64_t pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "WriteToSubresource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << DstSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDstBox, "    ", false))
    {
        WriteStructString(oss, pDstBox->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pSrcData;
    oss << ",\n";

    oss << "    " << "" << SrcRowPitch;
    oss << ",\n";

    oss << "    " << "" << SrcDepthPitch;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_ReadFromSubresource(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "ReadFromSubresource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "&" << pDstData;
    oss << ",\n";

    oss << "    " << "" << DstRowPitch;
    oss << ",\n";

    oss << "    " << "" << DstDepthPitch;
    oss << ",\n";

    oss << "    " << "" << SrcSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcBox, "    ", false))
    {
        WriteStructString(oss, pSrcBox->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource_GetHeapProperties(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags)
{
    std::ostringstream oss;
    oss << "ID3D12Resource_id" << object_id << "->";
    oss << "GetHeapProperties(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", true))
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
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12CommandAllocator_id" << object_id << "->";
    oss << "Reset(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_GetCompletedValue(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Fence_id" << object_id << "->";
    oss << "GetCompletedValue(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_SetEventOnCompletion(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Value,
        uint64_t hEvent)
{
    std::ostringstream oss;
    oss << "ID3D12Fence_id" << object_id << "->";
    oss << "SetEventOnCompletion(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Value;
    oss << ",\n";

    oss << "    " << "" << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence_Signal(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Value)
{
    std::ostringstream oss;
    oss << "ID3D12Fence_id" << object_id << "->";
    oss << "Signal(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Fence1_GetCreationFlags(
        format::HandleId object_id,
        D3D12_FENCE_FLAGS returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Fence1_id" << object_id << "->";
    oss << "GetCreationFlags(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineState_GetCachedBlob(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineState_id" << object_id << "->";
    oss << "GetCachedBlob(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, ppBlob, "    ", true))
    {
        oss << "    " << "&" << "ID3D10Blob_id" << *ppBlob->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_DESCRIPTOR_HEAP_DESC returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12DescriptorHeap_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12DescriptorHeap_id" << object_id << "->";
    oss << "GetCPUDescriptorHandleForHeapStart(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12DescriptorHeap_id" << object_id << "->";
    oss << "GetGPUDescriptorHandleForHeapStart(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandList_GetType(
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12CommandList_id" << object_id << "->";
    oss << "GetType(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Close(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "Close(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Reset(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pAllocator,
        format::HandleId pInitialState)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "Reset(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pAllocator;
    oss << ",\n";

    oss << "    " << "" << pInitialState;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearState(
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ClearState(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pPipelineState;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "DrawInstanced(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << VertexCountPerInstance;
    oss << ",\n";

    oss << "    " << "" << InstanceCount;
    oss << ",\n";

    oss << "    " << "" << StartVertexLocation;
    oss << ",\n";

    oss << "    " << "" << StartInstanceLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "DrawIndexedInstanced(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << IndexCountPerInstance;
    oss << ",\n";

    oss << "    " << "" << InstanceCount;
    oss << ",\n";

    oss << "    " << "" << StartIndexLocation;
    oss << ",\n";

    oss << "    " << "" << BaseVertexLocation;
    oss << ",\n";

    oss << "    " << "" << StartInstanceLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "Dispatch(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ThreadGroupCountX;
    oss << ",\n";

    oss << "    " << "" << ThreadGroupCountY;
    oss << ",\n";

    oss << "    " << "" << ThreadGroupCountZ;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        format::HandleId object_id,
        format::HandleId pDstBuffer,
        UINT64 DstOffset,
        format::HandleId pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "CopyBufferRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstBuffer;
    oss << ",\n";

    oss << "    " << "" << DstOffset;
    oss << ",\n";

    oss << "    " << "" << pSrcBuffer;
    oss << ",\n";

    oss << "    " << "" << SrcOffset;
    oss << ",\n";

    oss << "    " << "" << NumBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "CopyTextureRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDst, "    ", false))
    {
        WriteStructString(oss, pDst->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << DstX;
    oss << ",\n";

    oss << "    " << "" << DstY;
    oss << ",\n";

    oss << "    " << "" << DstZ;
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
        format::HandleId object_id,
        format::HandleId pDstResource,
        format::HandleId pSrcResource)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "CopyResource(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstResource;
    oss << ",\n";

    oss << "    " << "" << pSrcResource;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
        format::HandleId object_id,
        format::HandleId pTiledResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
        format::HandleId pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "CopyTiles(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pTiledResource;
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

    oss << "    " << "" << pBuffer;
    oss << ",\n";

    oss << "    " << "" << BufferStartOffsetInBytes;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
        format::HandleId object_id,
        format::HandleId pDstResource,
        UINT DstSubresource,
        format::HandleId pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ResolveSubresource(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstResource;
    oss << ",\n";

    oss << "    " << "" << DstSubresource;
    oss << ",\n";

    oss << "    " << "" << pSrcResource;
    oss << ",\n";

    oss << "    " << "" << SrcSubresource;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Format);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "IASetPrimitiveTopology(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(PrimitiveTopology);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "RSSetViewports(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumViewports;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViewports, "    ", false))
    {
        WriteArrayStructsString(oss, pViewports, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "RSSetScissorRects(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4])
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
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
        format::HandleId object_id,
        UINT StencilRef)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "OMSetStencilRef(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << StencilRef;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
        format::HandleId object_id,
        format::HandleId pPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetPipelineState(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pPipelineState;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
        format::HandleId object_id,
        UINT NumBarriers,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ResourceBarrier(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumBarriers;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pBarriers, "    ", false))
    {
        WriteArrayStructsString(oss, pBarriers, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
        format::HandleId object_id,
        format::HandleId pCommandList)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ExecuteBundle(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pCommandList;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetDescriptorHeaps(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumDescriptorHeaps;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppDescriptorHeaps, "    ", false))
    {
        WriteArrayClassesString(oss, ppDescriptorHeaps, "ID3D12DescriptorHeap", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRootSignature(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pRootSignature;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        format::HandleId object_id,
        format::HandleId pRootSignature)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRootSignature(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pRootSignature;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRootDescriptorTable(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    WriteStructString(oss, &BaseDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRootDescriptorTable(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    WriteStructString(oss, &BaseDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRoot32BitConstant(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << SrcData;
    oss << ",\n";

    oss << "    " << "" << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRoot32BitConstant(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << SrcData;
    oss << ",\n";

    oss << "    " << "" << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRoot32BitConstants(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << Num32BitValuesToSet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "" << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRoot32BitConstants(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << Num32BitValuesToSet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcData, "    ", false))
    {
        oss << "    " << "" << "pSrcData" << " /* value = " << static_cast<uint16_t>(*pSrcData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DestOffsetIn32BitValues;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRootConstantBufferView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRootConstantBufferView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRootShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRootShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetComputeRootUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetGraphicsRootUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << RootParameterIndex;
    oss << ",\n";

    oss << "    " << "" << BufferLocation;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
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
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "IASetVertexBuffers(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << StartSlot;
    oss << ",\n";

    oss << "    " << "" << NumViews;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViews, "    ", false))
    {
        WriteArrayStructsString(oss, pViews, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SOSetTargets(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << StartSlot;
    oss << ",\n";

    oss << "    " << "" << NumViews;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pViews, "    ", false))
    {
        WriteArrayStructsString(oss, pViews, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "OMSetRenderTargets(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumRenderTargetDescriptors;
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
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ClearDepthStencilView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &DepthStencilView, "    ", false, false);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(ClearFlags);
    oss << ",\n";

    oss << "    " << "" << Depth;
    oss << ",\n";

    oss << "    " << "" << static_cast<uint16_t>(Stencil);
    oss << ",\n";

    oss << "    " << "" << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ClearRenderTargetView(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &RenderTargetView, "    ", false, false);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ColorRGBA, "    ", false))
    {
        WriteArrayValuesString(oss, ColorRGBA, "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<UINT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ClearUnorderedAccessViewUint(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &ViewGPUHandleInCurrentHeap, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &ViewCPUHandle, "    ", false, false);
    oss << ",\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Values, "    ", false))
    {
        WriteArrayValuesString(oss, Values, "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        format::HandleId pResource,
        PointerDecoder<FLOAT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ClearUnorderedAccessViewFloat(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteStructString(oss, &ViewGPUHandleInCurrentHeap, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &ViewCPUHandle, "    ", false, false);
    oss << ",\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Values, "    ", false))
    {
        WriteArrayValuesString(oss, Values, "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << NumRects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRects, "    ", false))
    {
        WriteArrayStructsString(oss, pRects, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "DiscardResource(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pRegion, "    ", false))
    {
        WriteStructString(oss, pRegion->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "BeginQuery(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pQueryHeap;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << "" << Index;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "EndQuery(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pQueryHeap;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << "" << Index;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
        format::HandleId object_id,
        format::HandleId pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        format::HandleId pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ResolveQueryData(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pQueryHeap;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    oss << "    " << "" << StartIndex;
    oss << ",\n";

    oss << "    " << "" << NumQueries;
    oss << ",\n";

    oss << "    " << "" << pDestinationBuffer;
    oss << ",\n";

    oss << "    " << "" << AlignedDestinationBufferOffset;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
        format::HandleId object_id,
        format::HandleId pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetPredication(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pBuffer;
    oss << ",\n";

    oss << "    " << "" << AlignedBufferOffset;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Operation);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "SetMarker(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "BeginEvent(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "EndEvent(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
        format::HandleId object_id,
        format::HandleId pCommandSignature,
        UINT MaxCommandCount,
        format::HandleId pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        format::HandleId pCountBuffer,
        UINT64 CountBufferOffset)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList_id" << object_id << "->";
    oss << "ExecuteIndirect(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pCommandSignature;
    oss << ",\n";

    oss << "    " << "" << MaxCommandCount;
    oss << ",\n";

    oss << "    " << "" << pArgumentBuffer;
    oss << ",\n";

    oss << "    " << "" << ArgumentBufferOffset;
    oss << ",\n";

    oss << "    " << "" << pCountBuffer;
    oss << ",\n";

    oss << "    " << "" << CountBufferOffset;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
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
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "AtomicCopyBufferUINT(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstBuffer;
    oss << ",\n";

    oss << "    " << "" << DstOffset;
    oss << ",\n";

    oss << "    " << "" << pSrcBuffer;
    oss << ",\n";

    oss << "    " << "" << SrcOffset;
    oss << ",\n";

    oss << "    " << "" << Dependencies;
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
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "AtomicCopyBufferUINT64(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstBuffer;
    oss << ",\n";

    oss << "    " << "" << DstOffset;
    oss << ",\n";

    oss << "    " << "" << pSrcBuffer;
    oss << ",\n";

    oss << "    " << "" << SrcOffset;
    oss << ",\n";

    oss << "    " << "" << Dependencies;
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
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "OMSetDepthBounds(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Min;
    oss << ",\n";

    oss << "    " << "" << Max;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "SetSamplePositions(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumSamplesPerPixel;
    oss << ",\n";

    oss << "    " << "" << NumPixels;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSamplePositions, "    ", false))
    {
        WriteArrayStructsString(oss, pSamplePositions, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
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
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "ResolveSubresourceRegion(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstResource;
    oss << ",\n";

    oss << "    " << "" << DstSubresource;
    oss << ",\n";

    oss << "    " << "" << DstX;
    oss << ",\n";

    oss << "    " << "" << DstY;
    oss << ",\n";

    oss << "    " << "" << pSrcResource;
    oss << ",\n";

    oss << "    " << "" << SrcSubresource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSrcRect, "    ", false))
    {
        WriteStructString(oss, pSrcRect->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Format);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(ResolveMode);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        format::HandleId object_id,
        UINT Mask)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList1_id" << object_id << "->";
    oss << "SetViewInstanceMask(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Mask;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList2_id" << object_id << "->";
    oss << "WriteBufferImmediate(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Count;
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
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "UpdateTileMappings(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << NumResourceRegions;
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

    oss << "    " << "" << pHeap;
    oss << ",\n";

    oss << "    " << "" << NumRanges;
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

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
        format::HandleId object_id,
        format::HandleId pDstResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
        format::HandleId pSrcResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "CopyTileMappings(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pDstResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDstRegionStartCoordinate, "    ", false))
    {
        WriteStructString(oss, pDstRegionStartCoordinate->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pSrcResource;
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

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "ExecuteCommandLists(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumCommandLists;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandLists, "    ", false))
    {
        WriteArrayClassesString(oss, ppCommandLists, "ID3D12CommandList", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "SetMarker(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "BeginEvent(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << Metadata;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << Size;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_EndEvent(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "EndEvent(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Signal(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pFence,
        UINT64 Value)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "Signal(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pFence;
    oss << ",\n";

    oss << "    " << "" << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_Wait(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pFence,
        UINT64 Value)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "Wait(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pFence;
    oss << ",\n";

    oss << "    " << "" << Value;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT64>* pFrequency)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "GetTimestampFrequency(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFrequency, "    ", true))
    {
        oss << "    " << "&" << *pFrequency->GetPointer() << " /* address = " << pFrequency->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "GetClockCalibration(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pGpuTimestamp, "    ", true))
    {
        oss << "    " << "&" << *pGpuTimestamp->GetPointer() << " /* address = " << pGpuTimestamp->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCpuTimestamp, "    ", true))
    {
        oss << "    " << "&" << *pCpuTimestamp->GetPointer() << " /* address = " << pCpuTimestamp->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12CommandQueue_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_COMMAND_QUEUE_DESC returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12CommandQueue_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetNodeCount(
        format::HandleId object_id,
        UINT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetNodeCount(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandQueue(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateCommandQueue(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandQueue, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppCommandQueue->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandAllocator(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateCommandAllocator(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(type);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandAllocator, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppCommandAllocator->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateGraphicsPipelineState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateComputePipelineState(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateComputePipelineState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandList(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        format::HandleId pCommandAllocator,
        format::HandleId pInitialState,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateCommandList(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << nodeMask;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(type);
    oss << ",\n";

    oss << "    " << "" << pCommandAllocator;
    oss << ",\n";

    oss << "    " << "" << pInitialState;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandList, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppCommandList->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateDescriptorHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateDescriptorHeap(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDescriptorHeapDesc, "    ", false))
    {
        WriteStructString(oss, pDescriptorHeapDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        format::HandleId object_id,
        UINT returnValue,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetDescriptorHandleIncrementSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(DescriptorHeapType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateRootSignature(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateRootSignature(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << nodeMask;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pBlobWithRootSignature, "    ", false))
    {
        oss << "    " << "" << "pBlobWithRootSignature" << " /* value = " << static_cast<uint16_t>(*pBlobWithRootSignature->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << blobLengthInBytes;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvRootSignature, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvRootSignature->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateConstantBufferView(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
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
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateShaderResourceView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
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
        format::HandleId object_id,
        format::HandleId pResource,
        format::HandleId pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << pCounterResource;
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
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateRenderTargetView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
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
        format::HandleId object_id,
        format::HandleId pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateDepthStencilView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
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
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
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
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CopyDescriptors(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumDestDescriptorRanges;
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

    oss << "    " << "" << NumSrcDescriptorRanges;
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

    oss << "    " << "" << ConverttoText(DescriptorHeapsType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CopyDescriptorsSimple(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumDescriptors;
    oss << ",\n";

    WriteStructString(oss, &DestDescriptorRangeStart, "    ", false, false);
    oss << ",\n";

    WriteStructString(oss, &SrcDescriptorRangeStart, "    ", false, false);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(DescriptorHeapsType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetResourceAllocationInfo(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << visibleMask;
    oss << ",\n";

    oss << "    " << "" << numResourceDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pResourceDescs, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetCustomHeapProperties(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_PROPERTIES returnValue,
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetCustomHeapProperties(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << nodeMask;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(heapType);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommittedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateCommittedResource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateHeap(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreatePlacedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreatePlacedResource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pHeap;
    oss << ",\n";

    oss << "    " << "" << HeapOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateReservedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateReservedResource(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pObject,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD Access,
        WStringDecoder* Name,
        PointerDecoder<uint64_t, void*>* pHandle)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pObject;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pAttributes, "    ", false))
    {
        WriteStructString(oss, pAttributes->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << Access;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
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
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "OpenSharedHandle(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NTHandle;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvObj, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvObj->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_OpenSharedHandleByName(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* Name,
        DWORD Access,
        PointerDecoder<uint64_t, void*>* pNTHandle)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "OpenSharedHandleByName(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, Name, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(Name->GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << "    " << "" << Access;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNTHandle, "    ", true))
    {
        oss << "    " << "&" << "pNTHandle" << " /* address = " << *pNTHandle->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_MakeResident(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "MakeResident(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_Evict(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "Evict(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateFence(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateFence(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << InitialValue;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFence, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppFence->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetDeviceRemovedReason(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetCopyableFootprints(
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
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetCopyableFootprints(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDesc, "    ", false))
    {
        WriteStructString(oss, pResourceDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << FirstSubresource;
    oss << ",\n";

    oss << "    " << "" << NumSubresources;
    oss << ",\n";

    oss << "    " << "" << BaseOffset;
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
        oss << "    " << "&" << *pTotalBytes->GetPointer() << " /* address = " << pTotalBytes->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateQueryHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateQueryHeap(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_SetStablePowerState(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Enable)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "SetStablePowerState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_CreateCommandSignature(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        format::HandleId pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "CreateCommandSignature(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pRootSignature;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvCommandSignature, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvCommandSignature->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetResourceTiling(
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
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetResourceTiling(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pTiledResource;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pNumTilesForEntireResource, "    ", true))
    {
        oss << "    " << "&" << *pNumTilesForEntireResource->GetPointer() << " /* address = " << pNumTilesForEntireResource->GetPointer() << " */";
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
        oss << "    " << "" << *pNumSubresourceTilings->GetPointer() << " /* address = " << pNumSubresourceTilings->GetPointer() << " */";
    }
    oss << ",\n";

    oss << "    " << "" << FirstSubresourceTilingToGet;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSubresourceTilingsForNonPackedMips, "    ", true))
    {
        WriteArrayStructsString(oss, pSubresourceTilingsForNonPackedMips, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device_GetAdapterLuid(
        format::HandleId object_id,
        Decoded_LUID returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Device_id" << object_id << "->";
    oss << "GetAdapterLuid(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        format::HandleId pPipeline)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary_id" << object_id << "->";
    oss << "StorePipeline(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    oss << "    " << "" << pPipeline;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary_id" << object_id << "->";
    oss << "LoadGraphicsPipeline(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary_id" << object_id << "->";
    oss << "LoadComputePipeline(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
        format::HandleId object_id,
        SIZE_T returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary_id" << object_id << "->";
    oss << "GetSerializedSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary_Serialize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary_id" << object_id << "->";
    oss << "Serialize(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12PipelineLibrary1_id" << object_id << "->";
    oss << "LoadPipeline(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pName->GetPointer()) << "\"";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T BlobLength,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineLibrary)
{
    std::ostringstream oss;
    oss << "ID3D12Device1_id" << object_id << "->";
    oss << "CreatePipelineLibrary(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pLibraryBlob, "    ", false))
    {
        oss << "    " << "" << "pLibraryBlob" << " /* value = " << static_cast<uint16_t>(*pLibraryBlob->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << BlobLength;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineLibrary, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineLibrary->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Fence*>* ppFences,
        PointerDecoder<UINT64>* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        uint64_t hEvent)
{
    std::ostringstream oss;
    oss << "ID3D12Device1_id" << object_id << "->";
    oss << "SetEventOnMultipleFenceCompletion(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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

    oss << "    " << "" << NumFences;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << "" << hEvent;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device1_SetResidencyPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities)
{
    std::ostringstream oss;
    oss << "ID3D12Device1_id" << object_id << "->";
    oss << "SetResidencyPriority(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumObjects;
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState)
{
    std::ostringstream oss;
    oss << "ID3D12Device2_id" << object_id << "->";
    oss << "CreatePipelineState(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppPipelineState, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppPipelineState->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device3_id" << object_id << "->";
    oss << "OpenExistingHeapFromAddress(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pAddress;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device3_id" << object_id << "->";
    oss << "OpenExistingHeapFromFileMapping(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << hFileMapping;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device3_EnqueueMakeResident(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        format::HandleId pFenceToSignal,
        UINT64 FenceValueToSignal)
{
    std::ostringstream oss;
    oss << "ID3D12Device3_id" << object_id << "->";
    oss << "EnqueueMakeResident(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ",\n";

    oss << "    " << "" << NumObjects;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppObjects, "    ", false))
    {
        WriteArrayClassesString(oss, ppObjects, "ID3D12Pageable", "    ", false);
    }
    oss << ",\n";

    oss << "    " << "" << pFenceToSignal;
    oss << ",\n";

    oss << "    " << "" << FenceValueToSignal;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence)
{
    std::ostringstream oss;
    oss << "ID3D12ProtectedSession_id" << object_id << "->";
    oss << "GetStatusFence(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppFence, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppFence->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12ProtectedSession_id" << object_id << "->";
    oss << "GetSessionStatus(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12ProtectedResourceSession_id" << object_id << "->";
    oss << "GetDesc(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommandList1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList)
{
    std::ostringstream oss;
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "CreateCommandList1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << nodeMask;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(type);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(flags);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppCommandList, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppCommandList->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    std::ostringstream oss;
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "CreateProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSession, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppSession->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateCommittedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
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
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "CreateCommittedResource1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pProtectedSession;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateHeap1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap)
{
    std::ostringstream oss;
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "CreateHeap1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pProtectedSession;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvHeap, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvHeap->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_CreateReservedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        format::HandleId pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "CreateReservedResource1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pProtectedSession;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    std::ostringstream oss;
    oss << "ID3D12Device4_id" << object_id << "->";
    oss << "GetResourceAllocationInfo1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << visibleMask;
    oss << ",\n";

    oss << "    " << "" << numResourceDescs;
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
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState)
{
    std::ostringstream oss;
    oss << "ID3D12LifetimeOwner_id" << object_id << "->";
    oss << "LifetimeStateUpdated(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(NewState);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
        format::HandleId object_id,
        Decoded_LUID returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12SwapChainAssistant_id" << object_id << "->";
    oss << "GetLUID(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv)
{
    std::ostringstream oss;
    oss << "ID3D12SwapChainAssistant_id" << object_id << "->";
    oss << "GetSwapChainObject(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppv, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppv->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue)
{
    std::ostringstream oss;
    oss << "ID3D12SwapChainAssistant_id" << object_id << "->";
    oss << "GetCurrentResourceAndCommandQueue(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riidQueue.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvQueue, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvQueue->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12SwapChainAssistant_id" << object_id << "->";
    oss << "InsertImplicitSync(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pObject)
{
    std::ostringstream oss;
    oss << "ID3D12LifetimeTracker_id" << object_id << "->";
    oss << "DestroyOwnedObject(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pObject;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        format::HandleId object_id,
        uint64_t returnValue,
        WStringDecoder* pExportName)
{
    std::ostringstream oss;
    oss << "ID3D12StateObjectProperties_id" << object_id << "->";
    oss << "GetShaderIdentifier(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pExportName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pExportName->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
        format::HandleId object_id,
        UINT64 returnValue,
        WStringDecoder* pExportName)
{
    std::ostringstream oss;
    oss << "ID3D12StateObjectProperties_id" << object_id << "->";
    oss << "GetShaderStackSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pExportName, "    ", false))
    {
        oss << "    " << "" << "\"" << util::interception::WideStringToString(pExportName->GetPointer()) << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12StateObjectProperties_id" << object_id << "->";
    oss << "GetPipelineStackSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes)
{
    std::ostringstream oss;
    oss << "ID3D12StateObjectProperties_id" << object_id << "->";
    oss << "SetPipelineStackSize(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << PipelineStackSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "CreateLifetimeTracker(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pOwner;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvTracker, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvTracker->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_RemoveDevice(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "RemoveDevice(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "EnumerateMetaCommands(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pNumMetaCommands, "    ", false))
    {
        oss << "    " << "" << *pNumMetaCommands->GetPointer() << " /* address = " << pNumMetaCommands->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDescs, "    ", true))
    {
        WriteArrayStructsString(oss, pDescs, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        PointerDecoder<UINT>* pTotalStructureSizeInBytes,
        PointerDecoder<UINT>* pParameterCount,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "EnumerateMetaCommandParameters(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*CommandId.decoded_value);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Stage);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pTotalStructureSizeInBytes, "    ", true))
    {
        oss << "    " << "&" << *pTotalStructureSizeInBytes->GetPointer() << " /* address = " << pTotalStructureSizeInBytes->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pParameterCount, "    ", false))
    {
        oss << "    " << "" << *pParameterCount->GetPointer() << " /* address = " << pParameterCount->GetPointer() << " */";
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pParameterDescs, "    ", true))
    {
        WriteArrayStructsString(oss, pParameterDescs, "    ", true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateMetaCommand(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID CommandId,
        UINT NodeMask,
        PointerDecoder<uint8_t>* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppMetaCommand)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "CreateMetaCommand(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*CommandId.decoded_value);
    oss << ",\n";

    oss << "    " << "" << NodeMask;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCreationParametersData, "    ", false))
    {
        oss << "    " << "" << "pCreationParametersData" << " /* value = " << static_cast<uint16_t>(*pCreationParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << CreationParametersDataSizeInBytes;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppMetaCommand, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppMetaCommand->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_CreateStateObject(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "CreateStateObject(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppStateObject, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppStateObject->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
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
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS returnValue,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    std::ostringstream oss;
    oss << "ID3D12Device5_id" << object_id << "->";
    oss << "CheckDriverMatchingIdentifier(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(SerializedDataType);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pIdentifierToCheck, "    ", false))
    {
        WriteStructString(oss, pIdentifierToCheck->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedDataSettings_id" << object_id << "->";
    oss << "SetAutoBreadcrumbsEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedDataSettings_id" << object_id << "->";
    oss << "SetPageFaultEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedDataSettings_id" << object_id << "->";
    oss << "SetWatsonDumpEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedDataSettings1_id" << object_id << "->";
    oss << "SetBreadcrumbContextEnablement(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Enablement);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedData_id" << object_id << "->";
    oss << "GetAutoBreadcrumbsOutput(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedData_id" << object_id << "->";
    oss << "GetPageFaultAllocationOutput(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedData1_id" << object_id << "->";
    oss << "GetAutoBreadcrumbsOutput1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    std::ostringstream oss;
    oss << "ID3D12DeviceRemovedExtendedData1_id" << object_id << "->";
    oss << "GetPageFaultAllocationOutput1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pOutput, "    ", true))
    {
        WriteStructString(oss, pOutput->GetMetaStructPointer(), "    ", false, true);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        uint64_t hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired)
{
    std::ostringstream oss;
    oss << "ID3D12Device6_id" << object_id << "->";
    oss << "SetBackgroundProcessingMode(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Mode);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(MeasurementsAction);
    oss << ",\n";

    oss << "    " << "" << hEventToSignalUponCompletion;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pbFurtherMeasurementsDesired, "    ", true))
    {
        oss << "    " << "&" << *pbFurtherMeasurementsDesired->GetPointer() << " /* address = " << pbFurtherMeasurementsDesired->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12ProtectedResourceSession1_id" << object_id << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device7_AddToStateObject(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        format::HandleId pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject)
{
    std::ostringstream oss;
    oss << "ID3D12Device7_id" << object_id << "->";
    oss << "AddToStateObject(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pAddition, "    ", false))
    {
        WriteStructString(oss, pAddition->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pStateObjectToGrowFrom;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppNewStateObject, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppNewStateObject->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession)
{
    std::ostringstream oss;
    oss << "ID3D12Device7_id" << object_id << "->";
    oss << "CreateProtectedResourceSession1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppSession, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppSession->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    std::ostringstream oss;
    oss << "ID3D12Device8_id" << object_id << "->";
    oss << "GetResourceAllocationInfo2(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << visibleMask;
    oss << ",\n";

    oss << "    " << "" << numResourceDescs;
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
        format::HandleId object_id,
        HRESULT returnValue,
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
    oss << "ID3D12Device8_id" << object_id << "->";
    oss << "CreateCommittedResource2(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pHeapProperties, "    ", false))
    {
        WriteStructString(oss, pHeapProperties->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(HeapFlags);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialResourceState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << pProtectedSession;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riidResource.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_CreatePlacedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource)
{
    std::ostringstream oss;
    oss << "ID3D12Device8_id" << object_id << "->";
    oss << "CreatePlacedResource1(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pHeap;
    oss << ",\n";

    oss << "    " << "" << HeapOffset;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(InitialState);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pOptimizedClearValue, "    ", false))
    {
        WriteStructString(oss, pOptimizedClearValue->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvResource, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvResource->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        format::HandleId object_id,
        format::HandleId pTargetedResource,
        format::HandleId pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    std::ostringstream oss;
    oss << "ID3D12Device8_id" << object_id << "->";
    oss << "CreateSamplerFeedbackUnorderedAccessView(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pTargetedResource;
    oss << ",\n";

    oss << "    " << "" << pFeedbackResource;
    oss << ",\n";

    WriteStructString(oss, &DestDescriptor, "    ", false, false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
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
    oss << "ID3D12Device8_id" << object_id << "->";
    oss << "GetCopyableFootprints1(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pResourceDesc, "    ", false))
    {
        WriteStructString(oss, pResourceDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << FirstSubresource;
    oss << ",\n";

    oss << "    " << "" << NumSubresources;
    oss << ",\n";

    oss << "    " << "" << BaseOffset;
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
        oss << "    " << "&" << *pTotalBytes->GetPointer() << " /* address = " << pTotalBytes->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    std::ostringstream oss;
    oss << "ID3D12Resource1_id" << object_id << "->";
    oss << "GetProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppProtectedSession, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppProtectedSession->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Resource2_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Resource2_id" << object_id << "->";
    oss << "GetDesc1(\n    /* ";

    oss << "return = " ;
    WriteStructString(oss, &returnValue, "                ", true, false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession)
{
    std::ostringstream oss;
    oss << "ID3D12Heap1_id" << object_id << "->";
    oss << "GetProtectedResourceSession(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppProtectedSession, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppProtectedSession->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        format::HandleId object_id,
        format::HandleId pProtectedResourceSession)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList3_id" << object_id << "->";
    oss << "SetProtectedResourceSession(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pProtectedResourceSession;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        format::HandleId object_id,
        UINT64 returnValue,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex)
{
    std::ostringstream oss;
    oss << "ID3D12MetaCommand_id" << object_id << "->";
    oss << "GetRequiredParameterResourceSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Stage);
    oss << ",\n";

    oss << "    " << "" << ParameterIndex;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "BeginRenderPass(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << NumRenderTargets;
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

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "EndRenderPass(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "InitializeMetaCommand(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pMetaCommand;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pInitializationParametersData, "    ", false))
    {
        oss << "    " << "" << "pInitializationParametersData" << " /* value = " << static_cast<uint16_t>(*pInitializationParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << InitializationParametersDataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        format::HandleId object_id,
        format::HandleId pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "ExecuteMetaCommand(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pMetaCommand;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pExecutionParametersData, "    ", false))
    {
        oss << "    " << "" << "pExecutionParametersData" << " /* value = " << static_cast<uint16_t>(*pExecutionParametersData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << ExecutionParametersDataSizeInBytes;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "BuildRaytracingAccelerationStructure(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << NumPostbuildInfoDescs;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pPostbuildInfoDescs, "    ", false))
    {
        WriteArrayStructsString(oss, pPostbuildInfoDescs, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "EmitRaytracingAccelerationStructurePostbuildInfo(\n    /* ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pDesc, "    ", false))
    {
        WriteStructString(oss, pDesc->GetMetaStructPointer(), "    ", false, false);
    }
    oss << ",\n";

    oss << "    " << "" << NumSourceAccelerationStructures;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pSourceAccelerationStructureData, "    ", false))
    {
        WriteArrayValuesString(oss, pSourceAccelerationStructureData, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "CopyRaytracingAccelerationStructure(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << DestAccelerationStructureData;
    oss << ",\n";

    oss << "    " << "" << SourceAccelerationStructureData;
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Mode);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        format::HandleId object_id,
        format::HandleId pStateObject)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
    oss << "SetPipelineState1(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pStateObject;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList4_id" << object_id << "->";
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
        format::HandleId object_id,
        BOOL bEnable)
{
    std::ostringstream oss;
    oss << "ID3D12Tools_id" << object_id << "->";
    oss << "EnableShaderInstrumentation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12Tools_id" << object_id << "->";
    oss << "ShaderInstrumentationEnabled(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList5_id" << object_id << "->";
    oss << "RSSetShadingRate(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(baseShadingRate);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, combiners, "    ", false))
    {
        WriteArrayConvertsString(oss, combiners, "    ", false);
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        format::HandleId object_id,
        format::HandleId shadingRateImage)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList5_id" << object_id << "->";
    oss << "RSSetShadingRateImage(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << shadingRateImage;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ)
{
    std::ostringstream oss;
    oss << "ID3D12GraphicsCommandList6_id" << object_id << "->";
    oss << "DispatchMesh(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ThreadGroupCountX;
    oss << ",\n";

    oss << "    " << "" << ThreadGroupCountY;
    oss << ",\n";

    oss << "    " << "" << ThreadGroupCountZ;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferPointer(
        format::HandleId object_id,
        uint64_t returnValue)
{
    std::ostringstream oss;
    oss << "ID3D10Blob_id" << object_id << "->";
    oss << "GetBufferPointer(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D10Blob_GetBufferSize(
        format::HandleId object_id,
        SIZE_T returnValue)
{
    std::ostringstream oss;
    oss << "ID3D10Blob_id" << object_id << "->";
    oss << "GetBufferSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID)
{
    std::ostringstream oss;
    oss << "ID3DDestructionNotifier_id" << object_id << "->";
    oss << "RegisterDestructionCallback(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << "callbackFn /* address = " << callbackFn << " */";
    oss << ",\n";

    oss << "    " << "" << pData;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pCallbackID, "    ", true))
    {
        oss << "    " << "&" << *pCallbackID->GetPointer() << " /* address = " << pCallbackID->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT callbackID)
{
    std::ostringstream oss;
    oss << "ID3DDestructionNotifier_id" << object_id << "->";
    oss << "UnregisterDestructionCallback(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << callbackID;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_ID3D12Debug_EnableDebugLayer(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12Debug_id" << object_id << "->";
    oss << "EnableDebugLayer(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_EnableDebugLayer(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12Debug1_id" << object_id << "->";
    oss << "EnableDebugLayer(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    oss << "ID3D12Debug1_id" << object_id << "->";
    oss << "SetEnableGPUBasedValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    oss << "ID3D12Debug1_id" << object_id << "->";
    oss << "SetEnableSynchronizedCommandQueueValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12Debug2_id" << object_id << "->";
    oss << "SetGPUBasedValidationFlags(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    oss << "ID3D12Debug3_id" << object_id << "->";
    oss << "SetEnableGPUBasedValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
        format::HandleId object_id,
        BOOL Enable)
{
    std::ostringstream oss;
    oss << "ID3D12Debug3_id" << object_id << "->";
    oss << "SetEnableSynchronizedCommandQueueValidation(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, Enable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
        format::HandleId object_id,
        D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12Debug3_id" << object_id << "->";
    oss << "SetGPUBasedValidationFlags(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice1_id" << object_id << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice1_id" << object_id << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_RLDO_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice1_id" << object_id << "->";
    oss << "ReportLiveDeviceObjects(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_FEATURE Mask)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice_id" << object_id << "->";
    oss << "SetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Mask);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice_id" << object_id << "->";
    oss << "GetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_RLDO_FLAGS Flags)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice_id" << object_id << "->";
    oss << "ReportLiveDeviceObjects(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Flags);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice2_id" << object_id << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugDevice2_id" << object_id << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
        format::HandleId object_id,
        BOOL returnValue,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandQueue_id" << object_id << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << Subresource;
    oss << ",\n";

    oss << "    " << "" << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
        format::HandleId object_id,
        BOOL returnValue,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList1_id" << object_id << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << Subresource;
    oss << ",\n";

    oss << "    " << "" << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList1_id" << object_id << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList1_id" << object_id << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
        format::HandleId object_id,
        BOOL returnValue,
        format::HandleId pResource,
        UINT Subresource,
        UINT State)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList_id" << object_id << "->";
    oss << "AssertResourceState(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << Subresource;
    oss << ",\n";

    oss << "    " << "" << State;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_FEATURE Mask)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList_id" << object_id << "->";
    oss << "SetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Mask);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
        format::HandleId object_id,
        D3D12_DEBUG_FEATURE returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList_id" << object_id << "->";
    oss << "GetFeatureMask(\n    /* ";

    oss << "return = " ;
    oss << "" << ConverttoText(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList2_id" << object_id << "->";
    oss << "SetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", false))
    {
        oss << "    " << "" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
        PointerDecoder<uint8_t>* pData,
        UINT DataSize)
{
    std::ostringstream oss;
    oss << "ID3D12DebugCommandList2_id" << object_id << "->";
    oss << "GetDebugParameter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Type);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pData, "    ", true))
    {
        oss << "    " << "&" << "pData" << " /* value = " << static_cast<uint16_t>(*pData->GetPointer()) << " */";
    }
    oss << ",\n";

    oss << "    " << "" << DataSize;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_Present(
        format::HandleId object_id,
        format::HandleId pResource,
        UINT Subresource,
        uint64_t window)
{
    std::ostringstream oss;
    oss << "ID3D12SharingContract_id" << object_id << "->";
    oss << "Present(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pResource;
    oss << ",\n";

    oss << "    " << "" << Subresource;
    oss << ",\n";

    oss << "    " << "" << window;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
        format::HandleId object_id,
        format::HandleId pFence,
        UINT64 FenceValue)
{
    std::ostringstream oss;
    oss << "ID3D12SharingContract_id" << object_id << "->";
    oss << "SharedFenceSignal(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << pFence;
    oss << ",\n";

    oss << "    " << "" << FenceValue;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
        format::HandleId object_id,
        Decoded_GUID guid)
{
    std::ostringstream oss;
    oss << "ID3D12SharingContract_id" << object_id << "->";
    oss << "BeginCapturableWork(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*guid.decoded_value);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12SharingContract_EndCapturableWork(
        format::HandleId object_id,
        Decoded_GUID guid)
{
    std::ostringstream oss;
    oss << "ID3D12SharingContract_id" << object_id << "->";
    oss << "EndCapturableWork(\n    /* ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*guid.decoded_value);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 MessageCountLimit)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "SetMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << MessageCountLimit;
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "ClearStoredMessages(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessage(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 MessageIndex,
        StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
        PointerDecoder<SIZE_T>* pMessageByteLength)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetMessage(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << MessageIndex;
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMessage, "    ", true))
    {
        WriteArrayStructsString(oss, pMessage, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pMessageByteLength, "    ", false))
    {
        oss << "    " << "" << *pMessageByteLength->GetPointer() << " /* address = " << pMessageByteLength->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetNumMessagesAllowedByStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetNumMessagesDeniedByStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetNumStoredMessages(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetNumStoredMessagesAllowedByRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetNumMessagesDiscardedByMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
        format::HandleId object_id,
        UINT64 returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetMessageCountLimit(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "AddStorageFilterEntries(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", true))
    {
        WriteArrayStructsString(oss, pFilter, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFilterByteLength, "    ", false))
    {
        oss << "    " << "" << *pFilterByteLength->GetPointer() << " /* address = " << pFilterByteLength->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "ClearStorageFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushEmptyStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushCopyOfStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushStorageFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PopStorageFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
        format::HandleId object_id,
        UINT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetStorageFilterStackSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "AddRetrievalFilterEntries(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
        PointerDecoder<SIZE_T>* pFilterByteLength)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    if (WriteCheckPointerDecoderNull(oss, pFilter, "    ", true))
    {
        WriteArrayStructsString(oss, pFilter, "    ", true);
    }
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pFilterByteLength, "    ", false))
    {
        oss << "    " << "" << *pFilterByteLength->GetPointer() << " /* address = " << pFilterByteLength->GetPointer() << " */";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "ClearRetrievalFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushEmptyRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
        format::HandleId object_id,
        HRESULT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushCopyOfRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PushRetrievalFilter(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
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
        format::HandleId object_id)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "PopRetrievalFilter(\n    /* ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
        format::HandleId object_id,
        UINT returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetRetrievalFilterStackSize(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddMessage(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_MESSAGE_CATEGORY Category,
        D3D12_MESSAGE_SEVERITY Severity,
        D3D12_MESSAGE_ID ID,
        StringDecoder* pDescription)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "AddMessage(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Category);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(Severity);
    oss << ",\n";

    oss << "    " << "" << ConverttoText(ID);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDescription, "    ", false))
    {
        oss << "    " << "" << "\"" << pDescription->GetPointer() << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_MESSAGE_SEVERITY Severity,
        StringDecoder* pDescription)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "AddApplicationMessage(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Severity);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, pDescription, "    ", false))
    {
        oss << "    " << "" << "\"" << pDescription->GetPointer() << "\"";
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_MESSAGE_CATEGORY Category,
        BOOL bEnable)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "SetBreakOnCategory(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Category);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_MESSAGE_SEVERITY Severity,
        BOOL bEnable)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "SetBreakOnSeverity(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Severity);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_MESSAGE_ID ID,
        BOOL bEnable)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "SetBreakOnID(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(ID);
    oss << ",\n";

    WriteBOOLString(oss, bEnable, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
        format::HandleId object_id,
        BOOL returnValue,
        D3D12_MESSAGE_CATEGORY Category)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetBreakOnCategory(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Category);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
        format::HandleId object_id,
        BOOL returnValue,
        D3D12_MESSAGE_SEVERITY Severity)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetBreakOnSeverity(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(Severity);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
        format::HandleId object_id,
        BOOL returnValue,
        D3D12_MESSAGE_ID ID)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetBreakOnID(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(ID);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
        format::HandleId object_id,
        BOOL bMute)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "SetMuteDebugOutput(\n    /* ";

    oss << "thread_id = WIP */\n";

    WriteBOOLString(oss, bMute, "    ", false);
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
        format::HandleId object_id,
        BOOL returnValue)
{
    std::ostringstream oss;
    oss << "ID3D12InfoQueue_id" << object_id << "->";
    oss << "GetMuteDebugOutput(\n    /* ";

    oss << "return = " ;
    WriteBOOLString(oss, returnValue, "                ", false);
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/
void Dx12AsciiConsumer::Process_IUnknown_QueryInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject)
{
    std::ostringstream oss;
    oss << "IUnknown_id" << object_id << "->";
    oss << "QueryInterface(\n    /* ";

    oss << "return = " ;
    oss << "" << enumutil::GetResultValueString(returnValue);
    oss << ",\n       ";

    oss << "thread_id = WIP */\n";

    oss << "    " << "" << ConverttoText(*riid.decoded_value);
    oss << ",\n";

    if (WriteCheckPointerDecoderNull(oss, ppvObject, "    ", true))
    {
        oss << "    " << "&" << "void_id" << *ppvObject->GetPointer();
    }
    oss << ");\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IUnknown_AddRef(
        format::HandleId object_id,
        ULONG returnValue)
{
    std::ostringstream oss;
    oss << "IUnknown_id" << object_id << "->";
    oss << "AddRef(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}


void Dx12AsciiConsumer::Process_IUnknown_Release(
        format::HandleId object_id,
        ULONG returnValue)
{
    std::ostringstream oss;
    oss << "IUnknown_id" << object_id << "->";
    oss << "Release(\n    /* ";

    oss << "return = " ;
    oss << "" << returnValue;
    oss << ",\n       ";

    oss << "thread_id = WIP */);\n\n";

    fprintf(GetFile(), "%s\n", oss.str().c_str());
}




GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
