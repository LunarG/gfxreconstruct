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
* @file  AmdDxExtTess.h
* @brief AMD D3D Tessellation Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTTESS_H_
#define _AMDDXEXTTESS_H_

/// @todo Need to handle packing to guarantee correct layouts

// This include file contains all the tessellation extension definitions
// (structures, enums, constants) shared between the driver and the application

// The number of supported tessellation modes is given by AmdDxTessMode_MaxModes below

/**
***************************************************************************************************
* @brief
*    AmdDxTessMode enumeration - Used for setting tessellation mode
*
***************************************************************************************************
*/
enum AmdDxTessMode
{
    AmdDxTessMode_Disabled     = 0,
    AmdDxTessMode_Continuous   = 1,
    AmdDxTessMode_Adaptive     = 2,
    AmdDxTessMode_Discrete     = 3,
    AmdDxTessMode_MaxModes     = 4
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessPatchType enumeration - Used for setting patch type for tessellation purposes
*    This only applies to the extended primitive topology ExtPatch.
*
***************************************************************************************************
*/
enum AmdDxTessPatchType
{
    AmdDxTessPatchType_Line     = 0,
    AmdDxTessPatchType_Tri      = 1,
    AmdDxTessPatchType_Quad     = 2
};



/**
***************************************************************************************************
* @brief
*    AmdDxTessModes structure - substructure of AmdDxTessInfo for reporting mode support
*
***************************************************************************************************
*/
struct AmdDxTessModes
{
    unsigned int disabled   :  1;
    unsigned int continuous :  1;
    unsigned int adaptive   :  1;
    unsigned int discrete   :  1;
    unsigned int unused     : 28;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessPrimSupport structure - substructure of AmdDxTessModeDetails for reporting
*    primitive support for tessellation purposes
*
***************************************************************************************************
*/
struct AmdDxTessPrimSupport
{
    unsigned int reserved0  :  2; // matches D3D10 primitive topology enums
    unsigned int lineList   :  1;
    unsigned int lineStrip  :  1;
    unsigned int triList    :  1;
    unsigned int triStrip   :  1;
    unsigned int reserved1  :  4; // gaps in D3D10 primitive topology enums
    unsigned int reserved2  :  8; // gap for adjacency prims
    unsigned int unused     : 12;
    // Note the extended primtypes are at other end
    unsigned int quadList   :  1;
    unsigned int patch      :  1;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessModeDetailFlags structure - substructure of AmdDxTessModeDetails for reporting
*    various settings for support on a per-mode basis
*
***************************************************************************************************
*/
struct AmdDxTessModeDetailFlags
{
    unsigned int gs             :  1;  // geometry shader support with tessellation
    unsigned int instancing     :  1;  // instancing support with tessellation
    unsigned int unused         : 30;
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessModeDetails structure - substructure of AmdDxTessInfo for reporting
*    complete per-mode tessellation support
*
***************************************************************************************************
*/
struct AmdDxTessModeDetails
{
    AmdDxTessPrimSupport     indexedPrims;
    AmdDxTessPrimSupport     nonindexedPrims;
    AmdDxTessPrimSupport     indexedInstancedPrims;
    AmdDxTessPrimSupport     nonindexedInstancedPrims;
    AmdDxTessModeDetailFlags flags;
    float                    maxTessLevel;
    unsigned int             reserved[2]; // just in case
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessInfo structure - main tessellation info structure returned
*    by AmdDxExtTess::GetInfo()
*
***************************************************************************************************
*/
struct AmdDxTessInfo
{
    AmdDxTessModes        modes;
    AmdDxTessModeDetails  modeDetails[AmdDxTessMode_MaxModes];
    unsigned int          reserved[7]; // just in case
};

/**
***************************************************************************************************
* @brief
*    AmdDxTessInputSlot enumeration - Specifies the input slot usage for tessellation
*    purposes and is used in AmdDxExtTess::SetInputSlots().
*
***************************************************************************************************
*/
enum AmdDxTessInputSlot
{
    AmdDxTessSlot_SuperPrimVtx0     = 0,
    AmdDxTessSlot_SuperPrimVtx1     = 1,
    AmdDxTessSlot_SuperPrimVtx2     = 2,
    AmdDxTessSlot_SuperPrimVtx3     = 3,
    AmdDxTessSlot_SysGenValues      = 4,
    AmdDxTessSlot_MaxSlotSpecifiers = 5
};

// D3D10.1 has max of 32 input slots so we'll use this as max
// Note that D3D10.0 has max of 16 input slots
const unsigned int AmdDxTessMaxInputSlots = 32;

// The tessellation system generated values in the input layout are recognized as follows:
// Triangles and lines
//    barycentric coordinates use any of the following formats
//        DXGI_FORMAT_R32G32B32A32_FLOAT
//        DXGI_FORMAT_R32G32B32_FLOAT
//    super primitive indices use any of the following formats
//        DXGI_FORMAT_R32G32B32A32_UINT
//        DXGI_FORMAT_R32G32B32_UINT
// Extended quad list primitive topologies
//    barycentric coordinates use the following format
//        DXGI_FORMAT_R32G32B32A32_FLOAT
//    super primitive indices use the following format
//        DXGI_FORMAT_R32G32B32A32_UINT
// Extended patch primitive topologies
//    barycentric coordinates use any of the following formats
//        DXGI_FORMAT_R32G32B32A32_FLOAT
//        DXGI_FORMAT_R32G32B32_FLOAT
//    Patch index and QuadId
//        DXGI_FORMAT_R32G32_UINT


#endif // _AMDDXEXTTESS_H_
