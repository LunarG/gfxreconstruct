/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2012 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextflglapi.h
* @brief
*    AMD D3D Framelock/Genlock API include file.
*    This is the main include file for applications using the FL/GL extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTFLGLAPI_H_
#define _AMDDXEXTFLGLAPI_H_

#include "AmdDxExtApi.h"
#include "AmdDxExtIface.h"
#include "AmdDxExtFLGL.h"
#include <DXGI.h>

// Extension ID passed to IAmdDxExt::GetExtInterface()
const unsigned int AmdDxExtFlglID = 13;

/**
***************************************************************************************************
* @brief Abstract FL/GL extension interface class
*
***************************************************************************************************
*/
class IAmdDxExtFlgl : public IAmdDxExtInterface
{
public:

    /**
    * SetFrameLock - Enable or disable Framelock
    *
    * This method can be used to enable or disable the framelock.
    *
    * The following error codes are defined:
    * E_FAIL   FL/GL HW is not supported, or no GLSync HW available
    *
    * \return HRESULT S_OK on success, error code on error.
    * \param  UINT enabled Zero to disable FL, nonzero to enable.
    */
    virtual HRESULT SetFrameLock(UINT enabled) = 0;

    /**
    * GetFrameCounter - Retrieve the current value for the frame counter
    *
    * The following error codes are defined:
    * E_FAIL   FL/GL HW is not supported, or no GLSync HW available
    *
    * \return HRESULT S_OK on success, error code on error
    * \param  UINT64 & pFrameCounter Pointer to writable UINT64 location to receive the current frame counter value
    */
    virtual HRESULT GetFrameCounter(UINT64* pFrameCounter) = 0;

    /**
    * ResetFrameCounter - Reset the frame counter
    *
    * This method can be used to reset the frame counter on the timing master
    *
    * The following error codes are defined:
    * E_FAIL   FL/GL HW is not supported, or no GLSync HW available
    * E_ACCESS The current adapter is not configured as the timing master
    *
    * \return HRESULT S_OK on success, error code on error
    */
    virtual HRESULT ResetFrameCounter() = 0;

    /**
    * GetState - Retrieve the current FL/GL state
    *
    * \return HRESULT S_OK on success, error code on error. Currently no error conditions are defined
    * \param  AmdDxFLGLState & pState Pointer to AmdDxFLGLState structure to receive the current state information.
    */
    virtual HRESULT GetState(AmdDxFlglState* pState) = 0;

    /**
    * FrameLockedPresent - perform framelocked Present call
    *
    * This method can be used to prevent deadlocks when using multiple threads within process
    *
    * The following error codes are defined:
    *
    * \return HRESULT S_OK on success, error code on error
    * \param  IDXGISwapChain & pSwapChain The DXGI swap chain normally used for presenting
    * \param  UINT syncInterval IDXGISwapChain::Present syncInterval attribute
    * \param  UINT flags IDXGISwapChain::Present flags attribute
    */
    virtual HRESULT FrameLockedPresent(IDXGISwapChain* pSwapChain,
                                       UINT syncInterval,
                                       UINT flags) = 0;
};

#endif // _AMDDXEXTFLGLAPI_H_