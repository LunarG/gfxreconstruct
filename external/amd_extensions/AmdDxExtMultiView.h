/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2016 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextmultiview.h
* @brief
*    AMD MultiView Exension API include file.
*    This is the main include file for apps using the MultiView extension.
***************************************************************************************************
*/

#ifndef _AMDDXEXTMULTIVIEW_H_
#define _AMDDXEXTMULTIVIEW_H_

#include <d3d11.h>

struct AmdDxClipRect
{
    BOOL       exclude; // include/exclude rect region
    D3D11_RECT rect;
};

#endif //_AMDDXEXTMULTIVIEW_H_
