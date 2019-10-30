/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2011 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxexthiz.h
* @brief AMD D3D Hi Z Extension API include file.
***************************************************************************************************
*/

#ifndef _AMDDXEXTHIZ_H_
#define _AMDDXEXTHIZ_H_

struct ID3D11Resource;

// This include file contains all the Hi Z extension definitions
// (structures, enums, constants) shared between the driver and the application

/**
***************************************************************************************************
* @brief
*    AmdDxHiZMode enumeration - Used for controlling the data that will be returned by Hi z
*
***************************************************************************************************
*/
enum AmdDxHiZMode
{
    AmdDxHiZMode_Min       = 0,         // DXGI_FORMAT_R16_UNORM
    AmdDxHiZMode_Max       = 1,         // DXGI_FORMAT_R16_UNORM
    AmdDxHiZMode_MaxMin    = 2,         // DXGI_FORMAT_R16G16_UNORM
    AmdDxHiZMode_ModeCount = 3
};

/**
***************************************************************************************************
* @brief
*    AmdDxHiZInfo struct - HiZ input struct. Contains the information needed to construct
*    a HiZ texture and return it to the app.
*
***************************************************************************************************
*/
struct AmdDxHiZInfo
{
    AmdDxHiZMode mode;
    ID3D11Resource* pDst;
    ID3D11Resource* pSrcDb;
};


#endif //_AMDDXEXTHIZ_H_
