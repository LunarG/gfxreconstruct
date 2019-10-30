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
* @file  amddxextiface.h
* @brief
*    AMD D3D Exension API include file. This is a helper include file for extensions. It 
*    provides a common base class for all extension interfaces
***************************************************************************************************
*/
#ifndef _AMDDXEXTIFACE_H_
#define _AMDDXEXTIFACE_H_

#include "AmdDxExt.h"

/**
***************************************************************************************************
* @brief Abstract extension interface class
*
* Each extension interface (e.g. tessellation) will derive from this class
***************************************************************************************************
*/
class IAmdDxExtInterface
{
public:
    virtual unsigned int AddRef(void) = 0;
    virtual unsigned int Release(void) = 0;

protected:
    // Basic constructor
    IAmdDxExtInterface() {};
    virtual ~IAmdDxExtInterface() = 0 {};
};

#endif // _AMDDXEXTIFACE_H_