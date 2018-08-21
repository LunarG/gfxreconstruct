/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef BRIMSTONE_PLATFORM_TYPES_H
#define BRIMSTONE_PLATFORM_TYPES_H

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else  // WIN32
// Define a version of the WIN32 SECURITY_ATTRIBUTES struct that
// is suitable for decoding on non-WIN32 platforms.
typedef uint32_t DWORD;
typedef int32_t  BOOL;
typedef void*    LPVOID;
typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef WORD     SECURITY_DESCRIPTOR_CONTROL;

struct SID_IDENTIFIER_AUTHORITY
{
    BYTE Value[6];
};

struct SID
{
    BYTE                     Revision;
    BYTE                     SubAuthorityCount;
    SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
    DWORD                    SubAuthority[1];
};

struct ACL
{
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
};

typedef void* PSID;
typedef ACL*  PACL;

struct SECURITY_DESCRIPTOR
{
    BYTE                        Revision;
    BYTE                        Sbz1;
    SECURITY_DESCRIPTOR_CONTROL Control;
    PSID                        Owner;
    PSID                        Group;
    PACL                        Sacl;
    PACL                        Dacl;
};

struct SECURITY_ATTRIBUTES
{
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
};
#endif // WIN32

#endif // BRIMSTONE_PLATFORM_TYPES_H
