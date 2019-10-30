/*
***************************************************************************************************
*
*  Trade secret of Advanced Micro Devices, Inc.
*  Copyright (c) 2017 Advanced Micro Devices, Inc. (unpublished)
*
*  All rights reserved.  This notice is intended as a precaution against inadvertent publication and
*  does not imply publication or any waiver of confidentiality.  The year included in the foregoing
*  notice is the year of creation of the work.
*
***************************************************************************************************
*/

/**
***************************************************************************************************
* @file  amddxextgpumarker.h
* @brief
*   enums / structs for AMD GPU marker extension
***************************************************************************************************
*/

#ifndef _AMDDXEXTGPUMARKER_H_
#define _AMDDXEXTGPUMARKER_H_

/**
***************************************************************************************************
* @brief
*    AmdDxExtWriteMarkerFlag enumeration
***************************************************************************************************
*/
enum AmdDxExtWriteMarkerFlag
{
    AmdDxExtWriteMarkerFlag_TopOfPipe    = 0x01,
    AmdDxExtWriteMarkerFlag_BottomOfPipe = 0x02,
};

struct AmdDxExtMarkerBufferHandle
{
    void* pGpuVidMem; ///< The pointer to existing system memory object
};

struct AmdDxExtMarkerBufferCreateInfo
{
    void*                        pMarkerBuffer;      ///< Marker Data buffer (CPU pointer)
    SIZE_T                       markerBufferSize;   ///< Marker Data buffer size
    AmdDxExtMarkerBufferHandle   markerBufferHandle; ///< The handle returned to app for
                                                     ///  inserting marker data
};

struct AmdDxExtGpuMarkerWriteInfo
{
    UINT64                      markerData;         ///< The marker data that is writen to
                                                    ///  markerBufferGpuAddress
    SIZE_T                      offset;             ///< Marker data offset
    AmdDxExtWriteMarkerFlag     flags;              ///< Marker flags
    AmdDxExtMarkerBufferHandle  markerBufferHandle; ///< The handle to insert the marker data
};
#endif