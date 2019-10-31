/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2010 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxexthizapi.h
* @brief
*    AMD D3D Hi Z Exension API include file.
*    This is the main include file for apps using Hi Z extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTHIZAPI_H_
#define _AMDDXEXTHIZAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtHiZ.h"

// Hi Z extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtHiZID = 4;

/**
***************************************************************************************************
* @brief Abstract Hi Z extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtHiZ : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetHiZTileData(AmdDxHiZInfo* pHiZInfo) = 0;
    virtual BOOL HasHiZTileData(ID3D11Resource* pDbRes) = 0;
};

#endif //_AMDDXEXTHIZAPI_H_
