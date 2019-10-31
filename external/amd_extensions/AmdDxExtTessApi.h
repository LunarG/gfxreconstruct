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
* @file  amddxexttessapi.h
* @brief
*    AMD D3D Tessellation Exension API include file.
*    This is the main include file for apps using tessellation extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTTESSAPI_H_
#define _AMDDXEXTTESSAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtTess.h"

// Tessellation extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtTessID = 1;

// forward declaration
struct AmdDxTessInfo;

/**
***************************************************************************************************
* @brief Abstract tessellation extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtTess : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetInfo(AmdDxTessInfo* pTessInfo) = 0;
    virtual HRESULT SetMode(AmdDxTessMode mode) = 0;
    virtual HRESULT SetMinLevel(FLOAT minLevel) = 0;
    virtual HRESULT SetMaxLevel(FLOAT maxLevel) = 0;
    virtual HRESULT SetInputSlots(const AmdDxTessInputSlot tessSlots[AmdDxTessMaxInputSlots]) = 0;
    virtual HRESULT SetPatchType(AmdDxTessPatchType patchType) = 0;

};

#endif // _AMDDXEXTTESSAPI_H_