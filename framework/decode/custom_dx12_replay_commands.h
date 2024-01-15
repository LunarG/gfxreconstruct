/*
** Copyright (c) 2023 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_ENCODE_CUSTOM_DX12_REPLAY_COMMANDS_H
#define GFXRECON_ENCODE_CUSTOM_DX12_REPLAY_COMMANDS_H

#include "format/api_call_id.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <format::ApiCallId Id>
struct CustomReplayPreCall
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase*, Args...)
    {}
};

template <format::ApiCallId Id>
struct CustomReplayPostCall
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase*, Args...)
    {}
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList_ResourceBarrier(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12Device_CreateConstantBufferView(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12Device_CreateShaderResourceView(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12Device_CreateRenderTargetView(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12Device_CreateDepthStencilView(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList_OMSetRenderTargets(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList4_BeginRenderPass(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList4_BeginRenderPass(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList_DrawInstanced(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList_DrawInstanced(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList_DrawIndexedInstanced(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList_DrawIndexedInstanced(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList_Dispatch(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList_Dispatch(args...);
    }
};

template <>
struct CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PreCall_ID3D12GraphicsCommandList_ExecuteIndirect(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12GraphicsCommandList_ExecuteIndirect(args...);
    }
};

template <>
struct CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists>
{
    template <typename... Args>
    static void Dispatch(Dx12ReplayConsumerBase* replay, Args... args)
    {
        replay->PostCall_ID3D12CommandQueue_ExecuteCommandLists(args...);
    }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CUSTOM_DX12_REPLAY_COMMANDS_H
