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
#ifndef _AMDDXEXTSSG_H_
#define _AMDDXEXTSSG_H_

/**
***************************************************************************************************
* @file  AmdDxExtSSG.h
* @brief AMD SSG Extension include file
***************************************************************************************************
*/

struct AmdDxSsgVersion
{
    UINT    extVersionMajor;    ///< EXT interface major version
    UINT    extVersionMinor;    ///< EXT interface minor version
    UINT    ssgLibBuild;        ///< SSG library build number
};

typedef VOID*   AmdDxSsgFileHandle;
typedef VOID*   AmdDxSsgEventHandle;

enum AmdDxSsgFileAccess
{
    AmdDxSsgFile_Read           = 1,
    AmdDxSsgFile_Write          = 2,
    AmdDxSsgFile_ReadWrite      = 3,
};

struct AmdDxSsgFileInfo
{
    UINT64      fileSize;       ///< size in bytes of the file
    UINT        blockSize;      ///< size in bytes of file block
};

struct AmdDxSsgRegionDesc
{
    UINT64      fileOffset;     ///< start offset in bytes in the file
    UINT64      bufferOffset;   ///< start offset in bytes in the D3D buffer
    UINT64      regionSize;     ///< region size in bytes
};

#endif // _AMDDXEXTSSG_H_

