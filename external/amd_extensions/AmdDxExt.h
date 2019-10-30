/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2008 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/
/**
***************************************************************************************************
* @file  amddxext.h
* @brief AMD D3D Exension API include file.
***************************************************************************************************
*/
#ifndef _AMDDXEXT_H_
#define _AMDDXEXT_H_


/// Extended Primitive Topology enumeration
enum AmdDxExtPrimitiveTopology
{
                                                       // D3D10_DDI_PRIMITIVE_TOPOLOGY_* values
    AmdDxExtPrimitiveTopology_Undefined          = 0,  // D3D10 UNDEFINED
    AmdDxExtPrimitiveTopology_PointList          = 1,  // D3D10 POINTLIST
    AmdDxExtPrimitiveTopology_LineList           = 2,  // D3D10 LINELIST
    AmdDxExtPrimitiveTopology_LineStrip          = 3,  // D3D10 LINESTRIP
    AmdDxExtPrimitiveTopology_TriangleList       = 4,  // D3D10 TRIANGLELIST
    AmdDxExtPrimitiveTopology_TriangleStrip      = 5,  // D3D10 TRIANGLESTRIP
                                                       // 6 is reserved for legacy triangle fans
    AmdDxExtPrimitiveTopology_ExtQuadList        = 7,  // No D3D10 equivalent
    AmdDxExtPrimitiveTopology_ExtPatch           = 8,  // No D3D10 equivalent
    AmdDxExtPrimitiveTopology_ExtScreenRectList  = 9,  // No D3D10 equivalent
    AmdDxExtPrimitiveTopology_LineListAdj        = 10, // D3D10 LINELIST_ADJ
    AmdDxExtPrimitiveTopology_LineStripAdj       = 11, // D3D10 LINESTRIP_ADJ
    AmdDxExtPrimitiveTopology_TriangleListAdj    = 12, // D3D10 TRIANGLELIST_ADJ
    AmdDxExtPrimitiveTopology_TriangleStripAdj   = 13, // D3D10 TRIANGLESTRIP_ADJ
    AmdDxExtPrimitiveTopology_Max                = 14
};


enum AmdDxExtFeatureToken
{
    AmdDxExtFeature_ScreenRectSupport           = 1, // Screen Rect supported - data is BOOL
    AmdDxExtFeature_DeviceHp3d                  = 2, // HP3D support
    AmdDxExtFeature_DeviceCtxSupport            = 3, // Device Ctx Support
};

#endif // _AMDDXEXT_H_