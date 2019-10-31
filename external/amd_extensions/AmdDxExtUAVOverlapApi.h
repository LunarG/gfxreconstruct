/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2014 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextsurfsyncapi.h
* @brief
*    AMD D3D UAV Overlap Extension API include file.
*    This is the main include file for apps using the UAV Overlap extension.
***************************************************************************************************
*/


#ifndef _AMDDXEXTUAVOVERLAPAPI_H_
#define _AMDDXEXTUAVOVERLAPAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"

const unsigned int AmdDxUavOverlapMajorVersion = 1;
const unsigned int AmdDxUavOverlapMinorVersion = 4;
// UAV Overlap extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtUAVOverlapID = 15;

/**
***************************************************************************************************
* @brief Abstract UAV Overlap extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtUAVOverlap : public IAmdDxExtInterface
{
public:
    virtual HRESULT BeginUAVOverlap() = 0;
    virtual HRESULT EndUAVOverlap() = 0;

    virtual HRESULT GetExtensionVersion(AmdDxExtVersion* pExtVer) = 0;

    virtual HRESULT BeginUAVOverlapCtx(ID3D11DeviceContext* pCtx) = 0;
    virtual HRESULT EndUAVOverlapCtx(ID3D11DeviceContext* pCtx) = 0;
};

#endif //_AMDDXEXTUAVOVERLAPAPI_H_
