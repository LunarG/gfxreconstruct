//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author Esen Yilmaz
/// \file   asic_info_amdext_loader.h
//=============================================================================

#ifndef ASIC_INFO_AMDEXT_LOADER_H_
#define ASIC_INFO_AMDEXT_LOADER_H_

#ifdef _WIN32
#include <d3d11.h>
#include "AmdDxExtASICInfoApi.h"
#else
typedef void AmdDxASICInfo;
#endif

class AsicInfoAmdExtLoader
{
  public:
    static bool GetAsicInfo(AmdDxASICInfo* pAsicInfo);
};

#endif // ASIC_INFO_EXTENSION_H_