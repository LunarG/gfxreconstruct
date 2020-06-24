//=============================================================================
/// Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file   tcp_client.h
/// \brief  Header file of TcpClient class,
///         which is used to send messages over TCP
//=============================================================================

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#ifdef _WIN32
#include <WinSock2.h>
#include <WS2tcpip.h>
#endif

#include "util/logging.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <mutex>

#ifndef _WIN32
// TODO(xooi@amd.com) replace these with platform agnostic wrappers
typedef void addrinfo;
typedef int  SOCKET;
#endif

using namespace std;

namespace
{
static constexpr uint32_t kStrLen              = 4096;
static constexpr uint32_t kPortStrLen          = 128;
static const char*        kDriverName          = "amdvlk64.dll";
static constexpr uint32_t kIpAddressStringSize = 32;
} // namespace

// Used for sending messages over TCP
// (currently only implemented for Windows)
class TcpClient
{
    TcpClient(const TcpClient&) = delete;
    TcpClient& operator=(const TcpClient&) = delete;

  public:
    // Factory method: creates and returns TcpClient.
    // Must be called prior to sending data
    // in order to set target IP and port.
    // May return null on failure.
    static std::unique_ptr<TcpClient>
    Create(char* addr, uint32_t port, addrinfo* addr_info, char* file_name, bool data_send);

    // Send data over socket
    template <typename... Args>
    bool SendDataOverSocket(const char* data, Args... args)
    {
#ifdef _WIN32
        char  str[kStrLen];
        char* va_str = str;
        int   result = 0;

        result = snprintf(va_str, kStrLen, data, args...);
        if (result < 0)
        {
            GFXRECON_LOG_WARNING("No data\n");
        }

        int send_result = send(socket_, str, (int)strlen(str), 0);

        if (send_result == SOCKET_ERROR)
        {
            GFXRECON_LOG_ERROR("Send data failed\n");
            closesocket(socket_);
            WSACleanup();
            return false;
        }

        return true;
#else
        GFXRECON_LOG_ERROR("TcpClient SendDataOverSocket only supported in Windows.\n");
        return false;
#endif
    }

    // Create and connect to the socket
    // Formats the provided data and
    // sends it to the provided address over TCP
    template <typename... Args>
    void TransmitData(const char* fmt, Args... args)
    {
#ifdef _WIN32
        std::lock_guard<std::mutex> lock(mutex_);

        if (InitSocket() == false)
        {
            GFXRECON_LOG_ERROR("Init WinSock DLL process failed.\n");
            return;
        }

        socket_ = socket(AF_INET, SOCK_STREAM, 0);

        if (GetAddressInfo() == false)
        {
            GFXRECON_LOG_WARNING("Get address information failed.\n");
            return;
        }

        if (CreateSocket() == false)
        {
            GFXRECON_LOG_ERROR("Create socket failed.\n");
            return;
        }

        if (ConnectSocket() == false)
        {
            GFXRECON_LOG_ERROR("Connect to socket failed.\n");
            return;
        }

        freeaddrinfo(address_info_);

        if (socket_ == INVALID_SOCKET)
        {
            GFXRECON_LOG_ERROR("Unable to connect to server\n");
            WSACleanup();
            return;
        }

        data_sent_ = SendDataOverSocket(fmt, args...);
#else
        GFXRECON_LOG_ERROR("TcpClient TransmitData only supported in Windows.\n");
        return;
#endif
    }

    // Send the trace file pointer position over TCP
    void TcpSendFilePos(int64_t file_len, int64_t bytes_sent, char* file_name);

    // Send loaded driver info over TCP
    void TcpSendDriverLoadInfo();

    // Get File Size that sent over TCP
    std::ifstream::pos_type GetFileSize(const char* filename);

    // Get address info for send data
    bool GetAddressInfo();

    // Initiate use of window socket DLL
    bool InitSocket();

    // Create a socket
    bool CreateSocket();

    // Connect to socket
    bool ConnectSocket();

    // Get TCP port number
    uint32_t GetPortNum();

    // Get trace file name
    char* GetFileName();

    // Get IP address
    char* GetIPAddress();

  private:
    // Private constructor called by Create function
    TcpClient(uint32_t port, addrinfo* addr_info, char* file_name, bool data_send);

    SOCKET     socket_;       // socket
    addrinfo*  address_info_; // TCP address info
    uint32_t   port_;         // TCP port number
    int64_t    file_position; // current file position read through TCP
    bool       data_sent_;    // data sent success flag
    bool       tcp_valid_;    // TCP active flag
    char*      file_name_;    // trace file name
    char       ip_str_[32];   // TCP IP address string
    std::mutex mutex_;        // mutex to protect data sent over TCP
};

#endif // TCPCLIENT_H_
