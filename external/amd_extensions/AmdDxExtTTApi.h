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
* @file  amddxextttapi.h
* @brief
*    AMD D3D Thread Trace Exension API include file.
*    This is the main include file for apps using thread trace extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTTTAPI_H_
#define _AMDDXEXTTTAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtTT.h"

// Thread Trace extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtTTID = 3;

/**
***************************************************************************************************
* @brief Abstract thread trace extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtTT : public IAmdDxExtInterface
{
public:
    virtual HRESULT GetInfo(AmdDxTTInfo* pTTInfo) = 0;
    virtual VOID Init() = 0;
    virtual VOID Close() = 0;
    virtual HRESULT GetConfig(AmdDxTTConfig* pTTConfig) = 0;
    virtual HRESULT SetConfig(AmdDxTTConfig* pTTConfig) = 0;
    virtual HRESULT AllocThreadTraceBuffer(AmdDxTTBufDesc* pBufDesc) = 0;
    virtual HRESULT FreeThreadTraceBuffer(UINT shaderEngineId) = 0;
    virtual HRESULT BeginTrace(AmdDxTTTraceIndex* pTraceIndex) = 0;
    virtual HRESULT EndTrace() = 0;
    virtual VOID InsertData(UINT32 data) = 0;
    virtual HRESULT GetTraceStatus(AmdDxTTStatus* pStatusInfo) = 0;
    virtual HRESULT LockBuffer(AmdDxTTData* pTTData) = 0;
    virtual VOID UnlockBuffer() = 0;
};

#endif // _AMDDXEXTTTAPI_H_