//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   tcp_client.cpp
/// \brief  Implementation of TcpClient class,
///         which is used to send messages over TCP
//=============================================================================

#include "tcp_client.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <WinSock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <io.h>

using namespace std;

namespace
{
static constexpr uint32_t kStrLen     = 4096;
static constexpr uint32_t kPortStrLen = 128;
static constexpr char*    kDriverName = "amdvlk64.dll";

void InitSocket()
{
    WSADATA wsa_data;
    int     result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (result != 0)
    {
        GFXRECON_LOG_ERROR("WSAStartup failed\n");
        return;
    }
}
} // namespace

std::unique_ptr<TcpClient>
TcpClient::Create(char* addr, uint32_t port, addrinfo* addr_info, char* file_name, bool data_send)
{
    std::unique_ptr<TcpClient> instance =
        std::unique_ptr<TcpClient>(new TcpClient(port, addr_info, file_name, data_send));
    strcpy(instance->ip_str_, addr);
    return instance;
}

TcpClient::TcpClient(uint32_t port, addrinfo* addr_info, char* file_name, bool data_send) :
    port_(port), address_info_(addr_info), file_name_(file_name), data_sent_(data_send)
{
    socket_    = NULL;
    tcp_valid_ = false;
    memset(ip_str_, 0, sizeof(ip_str_));
}

void TcpClient::GetAddressInfo()
{
    addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    char port_str[kPortStrLen];
    memset(port_str, 0, kPortStrLen);
    _itoa_s(port_, port_str, kPortStrLen, 10);

    int result = getaddrinfo(ip_str_, port_str, &hints, &address_info_);
    if (result != 0)
    {
        GFXRECON_LOG_ERROR("Failed to call getaddrinfo function");
        WSACleanup();
        return;
    }
}

void TcpClient::CreateSocket()
{
    socket_ = socket(address_info_->ai_family, address_info_->ai_socktype, address_info_->ai_protocol);

    if (socket_ == INVALID_SOCKET)
    {
        GFXRECON_LOG_ERROR("Error at creating socket\n");
        freeaddrinfo(address_info_);
        WSACleanup();
        return;
    }
}

void TcpClient::ConnectSocket()
{
    int result = connect(socket_, address_info_->ai_addr, (int)address_info_->ai_addrlen);

    if (result == SOCKET_ERROR)
    {
        closesocket(socket_);
        socket_ = INVALID_SOCKET;
        return;
    }
}

uint64_t GetFileLength(FILE* fp)
{
    uint64_t byte_length = 0;

    // Get file length
    int64_t length = 0;
    if (_fseeki64(fp, 0, SEEK_END) != 0)
    {
        GFXRECON_LOG_ERROR("Failed to fseek to the end of tracefile for replaying\n");
        return 0;
    }
    else
    {
        length = _ftelli64(fp);
        if (length == -1L)
        {
            GFXRECON_LOG_ERROR("Failed to get the length of tracefile for replaying.");
            length = 0;
        }
    }

    // WARNING: Reset file position to the beginning of the file
    // Because this function is only called from vktrace_FileLike_create_file,
    // the file position should always be the beginning of the file before getting file length.
    rewind(fp);

    byte_length = length;
    return byte_length;
}

// Send current file position info to GPS Shim UI and get next packet
void TcpClient::TcpSendFilePos(FILE* file_pointer, char* file_name)
{
    static INT64 last_position_sent = 0;

    if (NULL != file_name)
    {
        HANDLE file_handle = reinterpret_cast<HANDLE>(_get_osfhandle(_fileno(file_pointer)));
        INT64  file_len    = GetFileLength(file_pointer);
        LONG   file_pos_hi = 0;
        DWORD  file_pos_lo = SetFilePointer(file_handle, 0, &file_pos_hi, FILE_CURRENT);
        if (INVALID_SET_FILE_POINTER != file_pos_lo)
        {
            INT64  file_pos   = reinterpret_cast<INT64&>(file_pos_lo) | ((reinterpret_cast<INT64&>(file_pos_hi)) << 32);
            double file_len_f = reinterpret_cast<double&>(file_len);
            double position_cur                 = reinterpret_cast<double&>(file_pos);
            double position_last_sent           = reinterpret_cast<double&>(last_position_sent);
            double diff_from_last_position_sent = (position_cur - position_last_sent);
            double diff_min                     = (file_len_f * 0.001f);

            if (diff_from_last_position_sent >= diff_min)
            {
                std::stringstream str_stream;
                std::string       file_str;

                str_stream << file_name << ',' << file_pos << ',' << file_len;
                file_str = str_stream.str();

                TransmitData("GFXRECFILE:%s", file_str);
                last_position_sent = file_pos;
            }
        }
    }
}

// Send driver load info to GPS Shim UI
void TcpClient::TcpSendDriverLoadInfo()
{
    bool sent_driver_info = false;
    if (false == sent_driver_info)
    {
        sent_driver_info = true;

        HMODULE driver_handle = GetModuleHandleA(kDriverName);
        if (NULL == driver_handle)
        {
            TransmitData("[DRIVER_INFO]:UNKNOWN");
        }
        else
        {
            char driver_path[MAX_PATH];
            memset(driver_path, 0, MAX_PATH);
            DWORD res = GetModuleFileNameA(driver_handle, driver_path, MAX_PATH);
            if (0 == res)
            {
                TransmitData("[DRIVER_INFO]:NOT_FOUND");
            }
            else
            {
                TransmitData("[DRIVER_INFO]:FOUND_PATH,%s", driver_path);
            }
        }
    }
}

uint32_t TcpClient::GetPortNum()
{
    return port_;
}

char* TcpClient::GetFileName()
{
    return file_name_;
}

char* TcpClient::GetIPAddress()
{
    return ip_str_;
}
