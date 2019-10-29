//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   tcp_client.cpp
/// \brief  Implementation of TcpClient class,
///         which is used to send messages over TCP
//=============================================================================

#include "tcp_client.h"

#include <stdio.h>

using namespace std;

std::unique_ptr<TcpClient>
TcpClient::Create(char* addr, uint32_t port, addrinfo* addr_info, char* file_name, bool data_send)
{
    std::unique_ptr<TcpClient> instance =
        std::unique_ptr<TcpClient>(new TcpClient(port, addr_info, file_name, data_send));
    strcpy(instance->ip_str_, addr);
    return instance;
}

TcpClient::TcpClient(uint32_t port, addrinfo* addr_info, char* file_name, bool data_send) :
    port_(port), address_info_(addr_info), file_name_(file_name), data_sent_(data_send), file_position(0)
{
    socket_    = NULL;
    tcp_valid_ = false;
    memset(ip_str_, 0, sizeof(ip_str_));
}

bool TcpClient::GetAddressInfo()
{
#ifdef _WIN32
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
        GFXRECON_LOG_ERROR("Failed to call getaddrinfo function.\n");
        WSACleanup();
        return false;
    }
#else
    GFXRECON_LOG_ERROR("TcpClient GetAddressInfo() is supported in Windows only.\n");
    return false;
#endif
}

bool TcpClient::InitSocket()
{
#ifdef _WIN32
    WSADATA wsa_data;
    int     result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (result != 0)
    {
        GFXRECON_LOG_ERROR("WSAStartup failed\n");
        return false;
    }
#else
    GFXRECON_LOG_ERROR("TcpClient InitSocket() is supported in Windows only.\n");
    return false;
#endif
}

bool TcpClient::CreateSocket()
{
#ifdef _WIN32
    socket_ = socket(address_info_->ai_family, address_info_->ai_socktype, address_info_->ai_protocol);

    if (socket_ == INVALID_SOCKET)
    {
        GFXRECON_LOG_ERROR("Error at creating socket\n");
        freeaddrinfo(address_info_);
        WSACleanup();
        return false;
    }
#else
    GFXRECON_LOG_ERROR("TcpClient CreateSocket() is supported in Windows only.\n");
    return false;
#endif
}

bool TcpClient::ConnectSocket()
{
#ifdef _WIN32
    int result = connect(socket_, address_info_->ai_addr, (int)address_info_->ai_addrlen);

    if (result == SOCKET_ERROR)
    {
        closesocket(socket_);
        socket_ = INVALID_SOCKET;
        return false;
    }
#else
    GFXRECON_LOG_ERROR("TcpClient ConnectSocket() is supported in Windows only.\n");
    return false;
#endif
}

std::ifstream::pos_type TcpClient::GetFileSize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

// Send current file position info to GPS Shim UI and get next packet
void TcpClient::TcpSendFilePos(double file_len, double bytes_sent, char* file_name)
{
#ifdef _WIN32
    static int64_t last_position_sent = file_position;
    file_position += bytes_sent;
    if (NULL != file_name)
    {
        int64_t file_length = file_len;
        if (file_length > 0)
        {
            double file_len_f                   = file_length;
            double position_cur                 = file_position;
            double position_last_sent           = last_position_sent;
            double diff_from_last_position_sent = (position_cur - position_last_sent);
            double diff_min                     = (file_len_f * 0.001f);

            if (diff_from_last_position_sent >= diff_min)
            {
                std::stringstream str_stream;
                std::string       file_str;

                str_stream << file_name << ',' << file_position << ',' << file_len;
                file_str = str_stream.str();

                TransmitData("GFXRECFILE:%s", file_str);
                last_position_sent = file_position;
            }
        }
    }
#else
    GFXRECON_LOG_ERROR("TcpClient TcpSendFilePos() is supported in Windows only.\n");
    return;
#endif
}

// Send driver load info to GPS Shim UI
void TcpClient::TcpSendDriverLoadInfo()
{
#ifdef _WIN32
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
#else
    GFXRECON_LOG_ERROR("TcpClient TcpSendDriverLoadInfo() is supported in Windows only.\n");
    return;
#endif
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
