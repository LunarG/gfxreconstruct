/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
** IN THE SOFTWARE.
*/

#ifndef GFXRECON_DX12_STATE_TABLE_H
#define GFXRECON_DX12_STATE_TABLE_H

#include "format/format.h"
#include "generated/generated_dx12_wrappers.h"
#include "util/defines.h"

#include <functional>
#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class Dx12StateTable
{
  public:
    Dx12StateTable() {}

    ~Dx12StateTable() {}

    // clang-format off
    bool InsertWrapper(format::HandleId id, ID3D10Blob_Wrapper* wrapper)                               { return InsertEntry(id, wrapper, id3d10_blob_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandAllocator_Wrapper* wrapper)                   { return InsertEntry(id, wrapper, id3d12_command_allocator_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandQueue_Wrapper* wrapper)                       { return InsertEntry(id, wrapper, id3d12_command_queue_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12CommandSignature_Wrapper* wrapper)                   { return InsertEntry(id, wrapper, id3d12_command_signature_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug_Wrapper* wrapper)                              { return InsertEntry(id, wrapper, id3d12_debug_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug1_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, id3d12_debug1_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Debug2_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, id3d12_debug2_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandList_Wrapper* wrapper)                   { return InsertEntry(id, wrapper, id3d12_debug_command_list_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandList1_Wrapper* wrapper)                  { return InsertEntry(id, wrapper, id3d12_debug_command_list1_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugCommandQueue_Wrapper* wrapper)                  { return InsertEntry(id, wrapper, id3d12_debug_command_queue_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugDevice_Wrapper* wrapper)                        { return InsertEntry(id, wrapper, id3d12_debug_device_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DebugDevice1_Wrapper* wrapper)                       { return InsertEntry(id, wrapper, id3d12_debug_device1_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DescriptorHeap_Wrapper* wrapper)                     { return InsertEntry(id, wrapper, id3d12_descriptor_heap_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Device_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, id3d12_device_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceRemovedExtendedData_Wrapper* wrapper)          { return InsertEntry(id, wrapper, id3d12_device_removed_extended_data_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper)  { return InsertEntry(id, wrapper, id3d12_device_removed_extended_data_settings_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Fence_Wrapper* wrapper)                              { return InsertEntry(id, wrapper, id3d12_fence_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12GraphicsCommandList_Wrapper* wrapper)                { return InsertEntry(id, wrapper, id3d12_graphics_command_list_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Heap_Wrapper* wrapper)                               { return InsertEntry(id, wrapper, id3d12_heap_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12InfoQueue_Wrapper* wrapper)                          { return InsertEntry(id, wrapper, id3d12_info_queue_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12LifetimeOwner_Wrapper* wrapper)                      { return InsertEntry(id, wrapper, id3d12_lifetime_owner_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12LifetimeTracker_Wrapper* wrapper)                    { return InsertEntry(id, wrapper, id3d12_lifetime_tracker_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12MetaCommand_Wrapper* wrapper)                        { return InsertEntry(id, wrapper, id3d12_meta_command_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12PipelineLibrary_Wrapper* wrapper)                    { return InsertEntry(id, wrapper, id3d12_pipeline_library_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12PipelineState_Wrapper* wrapper)                      { return InsertEntry(id, wrapper, id3d12_pipeline_state_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12ProtectedResourceSession_Wrapper* wrapper)           { return InsertEntry(id, wrapper, id3d12_protected_resource_session_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12QueryHeap_Wrapper* wrapper)                          { return InsertEntry(id, wrapper, id3d12_query_heap_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Resource_Wrapper* wrapper)                           { return InsertEntry(id, wrapper, id3d12_resource_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12RootSignature_Wrapper* wrapper)                      { return InsertEntry(id, wrapper, id3d12_root_signature_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12RootSignatureDeserializer_Wrapper* wrapper)          { return InsertEntry(id, wrapper, id3d12_root_signature_deserializer_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12SharingContract_Wrapper* wrapper)                    { return InsertEntry(id, wrapper, id3d12_sharing_contract_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12StateObject_Wrapper* wrapper)                        { return InsertEntry(id, wrapper, id3d12_state_object_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12StateObjectProperties_Wrapper* wrapper)              { return InsertEntry(id, wrapper, id3d12_state_object_properties_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12SwapChainAssistant_Wrapper* wrapper)                 { return InsertEntry(id, wrapper, id3d12_swap_chain_assistant_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12Tools_Wrapper* wrapper)                              { return InsertEntry(id, wrapper, id3d12_tools_map_); }
    bool InsertWrapper(format::HandleId id, ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper) { return InsertEntry(id, wrapper, id3d12_versioned_root_signature_deserializer_map_); }
    bool InsertWrapper(format::HandleId id, ID3DDestructionNotifier_Wrapper* wrapper)                  { return InsertEntry(id, wrapper, id3d_destruction_notifier_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIAdapter_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, idxgi_adapter_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDecodeSwapChain_Wrapper* wrapper)                     { return InsertEntry(id, wrapper, idxgi_decode_swap_chain_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDevice_Wrapper* wrapper)                              { return InsertEntry(id, wrapper, idxgi_device_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIDisplayControl_Wrapper* wrapper)                      { return InsertEntry(id, wrapper, idxgi_display_control_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIFactory_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, idxgi_factory_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIFactoryMedia_Wrapper* wrapper)                        { return InsertEntry(id, wrapper, idxgi_factory_media_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIKeyedMutex_Wrapper* wrapper)                          { return InsertEntry(id, wrapper, idxgi_keyed_mutex_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIOutput_Wrapper* wrapper)                              { return InsertEntry(id, wrapper, idxgi_output_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIOutputDuplication_Wrapper* wrapper)                   { return InsertEntry(id, wrapper, idxgi_output_duplication_map_); }
    bool InsertWrapper(format::HandleId id, IDXGIResource_Wrapper* wrapper)                            { return InsertEntry(id, wrapper, idxgi_resource_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISurface_Wrapper* wrapper)                             { return InsertEntry(id, wrapper, idxgi_surface_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISwapChain_Wrapper* wrapper)                           { return InsertEntry(id, wrapper, idxgi_swap_chain_map_); }
    bool InsertWrapper(format::HandleId id, IDXGISwapChainMedia_Wrapper* wrapper)                      { return InsertEntry(id, wrapper, idxgi_swap_chain_media_map_); }

    bool RemoveWrapper(const ID3D10Blob_Wrapper* wrapper)                               { return RemoveEntry(wrapper, id3d10_blob_map_); }
    bool RemoveWrapper(const ID3D12CommandAllocator_Wrapper* wrapper)                   { return RemoveEntry(wrapper, id3d12_command_allocator_map_); }
    bool RemoveWrapper(const ID3D12CommandQueue_Wrapper* wrapper)                       { return RemoveEntry(wrapper, id3d12_command_queue_map_); }
    bool RemoveWrapper(const ID3D12CommandSignature_Wrapper* wrapper)                   { return RemoveEntry(wrapper, id3d12_command_signature_map_); }
    bool RemoveWrapper(const ID3D12Debug_Wrapper* wrapper)                              { return RemoveEntry(wrapper, id3d12_debug_map_); }
    bool RemoveWrapper(const ID3D12Debug1_Wrapper* wrapper)                             { return RemoveEntry(wrapper, id3d12_debug1_map_); }
    bool RemoveWrapper(const ID3D12Debug2_Wrapper* wrapper)                             { return RemoveEntry(wrapper, id3d12_debug2_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandList_Wrapper* wrapper)                   { return RemoveEntry(wrapper, id3d12_debug_command_list_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandList1_Wrapper* wrapper)                  { return RemoveEntry(wrapper, id3d12_debug_command_list1_map_); }
    bool RemoveWrapper(const ID3D12DebugCommandQueue_Wrapper* wrapper)                  { return RemoveEntry(wrapper, id3d12_debug_command_queue_map_); }
    bool RemoveWrapper(const ID3D12DebugDevice_Wrapper* wrapper)                        { return RemoveEntry(wrapper, id3d12_debug_device_map_); }
    bool RemoveWrapper(const ID3D12DebugDevice1_Wrapper* wrapper)                       { return RemoveEntry(wrapper, id3d12_debug_device1_map_); }
    bool RemoveWrapper(const ID3D12DescriptorHeap_Wrapper* wrapper)                     { return RemoveEntry(wrapper, id3d12_descriptor_heap_map_); }
    bool RemoveWrapper(const ID3D12Device_Wrapper* wrapper)                             { return RemoveEntry(wrapper, id3d12_device_map_); }
    bool RemoveWrapper(const ID3D12DeviceRemovedExtendedData_Wrapper* wrapper)          { return RemoveEntry(wrapper, id3d12_device_removed_extended_data_map_); }
    bool RemoveWrapper(const ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper)  { return RemoveEntry(wrapper, id3d12_device_removed_extended_data_settings_map_); }
    bool RemoveWrapper(const ID3D12Fence_Wrapper* wrapper)                              { return RemoveEntry(wrapper, id3d12_fence_map_); }
    bool RemoveWrapper(const ID3D12GraphicsCommandList_Wrapper* wrapper)                { return RemoveEntry(wrapper, id3d12_graphics_command_list_map_); }
    bool RemoveWrapper(const ID3D12Heap_Wrapper* wrapper)                               { return RemoveEntry(wrapper, id3d12_heap_map_); }
    bool RemoveWrapper(const ID3D12InfoQueue_Wrapper* wrapper)                          { return RemoveEntry(wrapper, id3d12_info_queue_map_); }
    bool RemoveWrapper(const ID3D12LifetimeOwner_Wrapper* wrapper)                      { return RemoveEntry(wrapper, id3d12_lifetime_owner_map_); }
    bool RemoveWrapper(const ID3D12LifetimeTracker_Wrapper* wrapper)                    { return RemoveEntry(wrapper, id3d12_lifetime_tracker_map_); }
    bool RemoveWrapper(const ID3D12MetaCommand_Wrapper* wrapper)                        { return RemoveEntry(wrapper, id3d12_meta_command_map_); }
    bool RemoveWrapper(const ID3D12PipelineLibrary_Wrapper* wrapper)                    { return RemoveEntry(wrapper, id3d12_pipeline_library_map_); }
    bool RemoveWrapper(const ID3D12PipelineState_Wrapper* wrapper)                      { return RemoveEntry(wrapper, id3d12_pipeline_state_map_); }
    bool RemoveWrapper(const ID3D12ProtectedResourceSession_Wrapper* wrapper)           { return RemoveEntry(wrapper, id3d12_protected_resource_session_map_); }
    bool RemoveWrapper(const ID3D12QueryHeap_Wrapper* wrapper)                          { return RemoveEntry(wrapper, id3d12_query_heap_map_); }
    bool RemoveWrapper(const ID3D12Resource_Wrapper* wrapper)                           { return RemoveEntry(wrapper, id3d12_resource_map_); }
    bool RemoveWrapper(const ID3D12RootSignature_Wrapper* wrapper)                      { return RemoveEntry(wrapper, id3d12_root_signature_map_); }
    bool RemoveWrapper(const ID3D12RootSignatureDeserializer_Wrapper* wrapper)          { return RemoveEntry(wrapper, id3d12_root_signature_deserializer_map_); }
    bool RemoveWrapper(const ID3D12SharingContract_Wrapper* wrapper)                    { return RemoveEntry(wrapper, id3d12_sharing_contract_map_); }
    bool RemoveWrapper(const ID3D12StateObject_Wrapper* wrapper)                        { return RemoveEntry(wrapper, id3d12_state_object_map_); }
    bool RemoveWrapper(const ID3D12StateObjectProperties_Wrapper* wrapper)              { return RemoveEntry(wrapper, id3d12_state_object_properties_map_); }
    bool RemoveWrapper(const ID3D12SwapChainAssistant_Wrapper* wrapper)                 { return RemoveEntry(wrapper, id3d12_swap_chain_assistant_map_); }
    bool RemoveWrapper(const ID3D12Tools_Wrapper* wrapper)                              { return RemoveEntry(wrapper, id3d12_tools_map_); }
    bool RemoveWrapper(const ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper) { return RemoveEntry(wrapper, id3d12_versioned_root_signature_deserializer_map_); }
    bool RemoveWrapper(const ID3DDestructionNotifier_Wrapper* wrapper)                  { return RemoveEntry(wrapper, id3d_destruction_notifier_map_); }
    bool RemoveWrapper(const IDXGIAdapter_Wrapper* wrapper)                             { return RemoveEntry(wrapper, idxgi_adapter_map_); }
    bool RemoveWrapper(const IDXGIDecodeSwapChain_Wrapper* wrapper)                     { return RemoveEntry(wrapper, idxgi_decode_swap_chain_map_); }
    bool RemoveWrapper(const IDXGIDevice_Wrapper* wrapper)                              { return RemoveEntry(wrapper, idxgi_device_map_); }
    bool RemoveWrapper(const IDXGIDisplayControl_Wrapper* wrapper)                      { return RemoveEntry(wrapper, idxgi_display_control_map_); }
    bool RemoveWrapper(const IDXGIFactory_Wrapper* wrapper)                             { return RemoveEntry(wrapper, idxgi_factory_map_); }
    bool RemoveWrapper(const IDXGIFactoryMedia_Wrapper* wrapper)                        { return RemoveEntry(wrapper, idxgi_factory_media_map_); }
    bool RemoveWrapper(const IDXGIKeyedMutex_Wrapper* wrapper)                          { return RemoveEntry(wrapper, idxgi_keyed_mutex_map_); }
    bool RemoveWrapper(const IDXGIOutput_Wrapper* wrapper)                              { return RemoveEntry(wrapper, idxgi_output_map_); }
    bool RemoveWrapper(const IDXGIOutputDuplication_Wrapper* wrapper)                   { return RemoveEntry(wrapper, idxgi_output_duplication_map_); }
    bool RemoveWrapper(const IDXGIResource_Wrapper* wrapper)                            { return RemoveEntry(wrapper, idxgi_resource_map_); }
    bool RemoveWrapper(const IDXGISurface_Wrapper* wrapper)                             { return RemoveEntry(wrapper, idxgi_surface_map_); }
    bool RemoveWrapper(const IDXGISwapChain_Wrapper* wrapper)                           { return RemoveEntry(wrapper, idxgi_swap_chain_map_); }
    bool RemoveWrapper(const IDXGISwapChainMedia_Wrapper* wrapper)                      { return RemoveEntry(wrapper, idxgi_swap_chain_media_map_); }

    void VisitWrappers(std::function<void(const ID3D10Blob_Wrapper*)> visitor) const                               { for (auto entry : id3d10_blob_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12CommandAllocator_Wrapper*)> visitor) const                   { for (auto entry : id3d12_command_allocator_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12CommandQueue_Wrapper*)> visitor) const                       { for (auto entry : id3d12_command_queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12CommandSignature_Wrapper*)> visitor) const                   { for (auto entry : id3d12_command_signature_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Debug_Wrapper*)> visitor) const                              { for (auto entry : id3d12_debug_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Debug1_Wrapper*)> visitor) const                             { for (auto entry : id3d12_debug1_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Debug2_Wrapper*)> visitor) const                             { for (auto entry : id3d12_debug2_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DebugCommandList_Wrapper*)> visitor) const                   { for (auto entry : id3d12_debug_command_list_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DebugCommandList1_Wrapper*)> visitor) const                  { for (auto entry : id3d12_debug_command_list1_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DebugCommandQueue_Wrapper*)> visitor) const                  { for (auto entry : id3d12_debug_command_queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DebugDevice_Wrapper*)> visitor) const                        { for (auto entry : id3d12_debug_device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DebugDevice1_Wrapper*)> visitor) const                       { for (auto entry : id3d12_debug_device1_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DescriptorHeap_Wrapper*)> visitor) const                     { for (auto entry : id3d12_descriptor_heap_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Device_Wrapper*)> visitor) const                             { for (auto entry : id3d12_device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DeviceRemovedExtendedData_Wrapper*)> visitor) const          { for (auto entry : id3d12_device_removed_extended_data_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12DeviceRemovedExtendedDataSettings_Wrapper*)> visitor) const  { for (auto entry : id3d12_device_removed_extended_data_settings_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Fence_Wrapper*)> visitor) const                              { for (auto entry : id3d12_fence_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12GraphicsCommandList_Wrapper*)> visitor) const                { for (auto entry : id3d12_graphics_command_list_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Heap_Wrapper*)> visitor) const                               { for (auto entry : id3d12_heap_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12InfoQueue_Wrapper*)> visitor) const                          { for (auto entry : id3d12_info_queue_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12LifetimeOwner_Wrapper*)> visitor) const                      { for (auto entry : id3d12_lifetime_owner_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12LifetimeTracker_Wrapper*)> visitor) const                    { for (auto entry : id3d12_lifetime_tracker_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12MetaCommand_Wrapper*)> visitor) const                        { for (auto entry : id3d12_meta_command_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12PipelineLibrary_Wrapper*)> visitor) const                    { for (auto entry : id3d12_pipeline_library_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12PipelineState_Wrapper*)> visitor) const                      { for (auto entry : id3d12_pipeline_state_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12ProtectedResourceSession_Wrapper*)> visitor) const           { for (auto entry : id3d12_protected_resource_session_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12QueryHeap_Wrapper*)> visitor) const                          { for (auto entry : id3d12_query_heap_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Resource_Wrapper*)> visitor) const                           { for (auto entry : id3d12_resource_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12RootSignature_Wrapper*)> visitor) const                      { for (auto entry : id3d12_root_signature_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12RootSignatureDeserializer_Wrapper*)> visitor) const          { for (auto entry : id3d12_root_signature_deserializer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12SharingContract_Wrapper*)> visitor) const                    { for (auto entry : id3d12_sharing_contract_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12StateObject_Wrapper*)> visitor) const                        { for (auto entry : id3d12_state_object_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12StateObjectProperties_Wrapper*)> visitor) const              { for (auto entry : id3d12_state_object_properties_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12SwapChainAssistant_Wrapper*)> visitor) const                 { for (auto entry : id3d12_swap_chain_assistant_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12Tools_Wrapper*)> visitor) const                              { for (auto entry : id3d12_tools_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3D12VersionedRootSignatureDeserializer_Wrapper*)> visitor) const { for (auto entry : id3d12_versioned_root_signature_deserializer_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const ID3DDestructionNotifier_Wrapper*)> visitor) const                  { for (auto entry : id3d_destruction_notifier_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIAdapter_Wrapper*)> visitor) const                             { for (auto entry : idxgi_adapter_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIDecodeSwapChain_Wrapper*)> visitor) const                     { for (auto entry : idxgi_decode_swap_chain_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIDevice_Wrapper*)> visitor) const                              { for (auto entry : idxgi_device_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIDisplayControl_Wrapper*)> visitor) const                      { for (auto entry : idxgi_display_control_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIFactory_Wrapper*)> visitor) const                             { for (auto entry : idxgi_factory_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIFactoryMedia_Wrapper*)> visitor) const                        { for (auto entry : idxgi_factory_media_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIKeyedMutex_Wrapper*)> visitor) const                          { for (auto entry : idxgi_keyed_mutex_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIOutput_Wrapper*)> visitor) const                              { for (auto entry : idxgi_output_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIOutputDuplication_Wrapper*)> visitor) const                   { for (auto entry : idxgi_output_duplication_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGIResource_Wrapper*)> visitor) const                            { for (auto entry : idxgi_resource_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGISurface_Wrapper*)> visitor) const                             { for (auto entry : idxgi_surface_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGISwapChain_Wrapper*)> visitor) const                           { for (auto entry : idxgi_swap_chain_map_) { visitor(entry.second); } }
    void VisitWrappers(std::function<void(const IDXGISwapChainMedia_Wrapper*)> visitor) const                      { for (auto entry : idxgi_swap_chain_media_map_) { visitor(entry.second); } }
    // clang-format on

    //
    // Helper functions for state initialization.
    //

    // clang-format off
    ID3D10Blob_Wrapper*       GetID3D10Blob_Wrapper(format::HandleId id)       { return GetWrapper<ID3D10Blob_Wrapper>(id, id3d10_blob_map_); }
    const ID3D10Blob_Wrapper* GetID3D10Blob_Wrapper(format::HandleId id) const { return GetWrapper<ID3D10Blob_Wrapper>(id, id3d10_blob_map_); }

    ID3D12CommandAllocator_Wrapper*       GetID3D12CommandAllocator_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12CommandAllocator_Wrapper>(id, id3d12_command_allocator_map_); }
    const ID3D12CommandAllocator_Wrapper* GetID3D12CommandAllocator_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandAllocator_Wrapper>(id, id3d12_command_allocator_map_); }

    ID3D12CommandQueue_Wrapper*       GetID3D12CommandQueue_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12CommandQueue_Wrapper>(id, id3d12_command_queue_map_); }
    const ID3D12CommandQueue_Wrapper* GetID3D12CommandQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandQueue_Wrapper>(id, id3d12_command_queue_map_); }

    ID3D12CommandSignature_Wrapper*       GetID3D12CommandSignature_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12CommandSignature_Wrapper>(id, id3d12_command_signature_map_); }
    const ID3D12CommandSignature_Wrapper* GetID3D12CommandSignature_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12CommandSignature_Wrapper>(id, id3d12_command_signature_map_); }

    ID3D12Debug_Wrapper*       GetID3D12Debug_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Debug_Wrapper>(id, id3d12_debug_map_); }
    const ID3D12Debug_Wrapper* GetID3D12Debug_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug_Wrapper>(id, id3d12_debug_map_); }

    ID3D12Debug1_Wrapper*       GetID3D12Debug1_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Debug1_Wrapper>(id, id3d12_debug1_map_); }
    const ID3D12Debug1_Wrapper* GetID3D12Debug1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug1_Wrapper>(id, id3d12_debug1_map_); }

    ID3D12Debug2_Wrapper*       GetID3D12Debug2_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Debug2_Wrapper>(id, id3d12_debug2_map_); }
    const ID3D12Debug2_Wrapper* GetID3D12Debug2_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Debug2_Wrapper>(id, id3d12_debug2_map_); }

    ID3D12DebugCommandList_Wrapper*       GetID3D12DebugCommandList_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DebugCommandList_Wrapper>(id, id3d12_debug_command_list_map_); }
    const ID3D12DebugCommandList_Wrapper* GetID3D12DebugCommandList_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandList_Wrapper>(id, id3d12_debug_command_list_map_); }

    ID3D12DebugCommandList1_Wrapper*       GetID3D12DebugCommandList1_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DebugCommandList1_Wrapper>(id, id3d12_debug_command_list1_map_); }
    const ID3D12DebugCommandList1_Wrapper* GetID3D12DebugCommandList1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandList1_Wrapper>(id, id3d12_debug_command_list1_map_); }

    ID3D12DebugCommandQueue_Wrapper*       GetID3D12DebugCommandQueue_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DebugCommandQueue_Wrapper>(id, id3d12_debug_command_queue_map_); }
    const ID3D12DebugCommandQueue_Wrapper* GetID3D12DebugCommandQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugCommandQueue_Wrapper>(id, id3d12_debug_command_queue_map_); }

    ID3D12DebugDevice_Wrapper*       GetID3D12DebugDevice_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DebugDevice_Wrapper>(id, id3d12_debug_device_map_); }
    const ID3D12DebugDevice_Wrapper* GetID3D12DebugDevice_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugDevice_Wrapper>(id, id3d12_debug_device_map_); }

    ID3D12DebugDevice1_Wrapper*       GetID3D12DebugDevice1_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DebugDevice1_Wrapper>(id, id3d12_debug_device1_map_); }
    const ID3D12DebugDevice1_Wrapper* GetID3D12DebugDevice1_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DebugDevice1_Wrapper>(id, id3d12_debug_device1_map_); }

    ID3D12DescriptorHeap_Wrapper*       GetID3D12DescriptorHeap_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DescriptorHeap_Wrapper>(id, id3d12_descriptor_heap_map_); }
    const ID3D12DescriptorHeap_Wrapper* GetID3D12DescriptorHeap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DescriptorHeap_Wrapper>(id, id3d12_descriptor_heap_map_); }

    ID3D12Device_Wrapper*       GetID3D12Device_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Device_Wrapper>(id, id3d12_device_map_); }
    const ID3D12Device_Wrapper* GetID3D12Device_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Device_Wrapper>(id, id3d12_device_map_); }

    ID3D12DeviceRemovedExtendedData_Wrapper*       GetID3D12DeviceRemovedExtendedData_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DeviceRemovedExtendedData_Wrapper>(id, id3d12_device_removed_extended_data_map_); }
    const ID3D12DeviceRemovedExtendedData_Wrapper* GetID3D12DeviceRemovedExtendedData_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceRemovedExtendedData_Wrapper>(id, id3d12_device_removed_extended_data_map_); }

    ID3D12DeviceRemovedExtendedDataSettings_Wrapper*       GetID3D12DeviceRemovedExtendedDataSettings_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(id, id3d12_device_removed_extended_data_settings_map_); }
    const ID3D12DeviceRemovedExtendedDataSettings_Wrapper* GetID3D12DeviceRemovedExtendedDataSettings_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12DeviceRemovedExtendedDataSettings_Wrapper>(id, id3d12_device_removed_extended_data_settings_map_); }

    ID3D12Fence_Wrapper*       GetID3D12Fence_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Fence_Wrapper>(id, id3d12_fence_map_); }
    const ID3D12Fence_Wrapper* GetID3D12Fence_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Fence_Wrapper>(id, id3d12_fence_map_); }

    ID3D12GraphicsCommandList_Wrapper*       GetID3D12GraphicsCommandList_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12GraphicsCommandList_Wrapper>(id, id3d12_graphics_command_list_map_); }
    const ID3D12GraphicsCommandList_Wrapper* GetID3D12GraphicsCommandList_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12GraphicsCommandList_Wrapper>(id, id3d12_graphics_command_list_map_); }

    ID3D12Heap_Wrapper*       GetID3D12Heap_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Heap_Wrapper>(id, id3d12_heap_map_); }
    const ID3D12Heap_Wrapper* GetID3D12Heap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Heap_Wrapper>(id, id3d12_heap_map_); }

    ID3D12InfoQueue_Wrapper*       GetID3D12InfoQueue_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12InfoQueue_Wrapper>(id, id3d12_info_queue_map_); }
    const ID3D12InfoQueue_Wrapper* GetID3D12InfoQueue_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12InfoQueue_Wrapper>(id, id3d12_info_queue_map_); }

    ID3D12LifetimeOwner_Wrapper*       GetID3D12LifetimeOwner_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12LifetimeOwner_Wrapper>(id, id3d12_lifetime_owner_map_); }
    const ID3D12LifetimeOwner_Wrapper* GetID3D12LifetimeOwner_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12LifetimeOwner_Wrapper>(id, id3d12_lifetime_owner_map_); }

    ID3D12LifetimeTracker_Wrapper*       GetID3D12LifetimeTracker_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12LifetimeTracker_Wrapper>(id, id3d12_lifetime_tracker_map_); }
    const ID3D12LifetimeTracker_Wrapper* GetID3D12LifetimeTracker_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12LifetimeTracker_Wrapper>(id, id3d12_lifetime_tracker_map_); }

    ID3D12MetaCommand_Wrapper*       GetID3D12MetaCommand_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12MetaCommand_Wrapper>(id, id3d12_meta_command_map_); }
    const ID3D12MetaCommand_Wrapper* GetID3D12MetaCommand_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12MetaCommand_Wrapper>(id, id3d12_meta_command_map_); }

    ID3D12PipelineLibrary_Wrapper*       GetID3D12PipelineLibrary_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12PipelineLibrary_Wrapper>(id, id3d12_pipeline_library_map_); }
    const ID3D12PipelineLibrary_Wrapper* GetID3D12PipelineLibrary_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12PipelineLibrary_Wrapper>(id, id3d12_pipeline_library_map_); }

    ID3D12PipelineState_Wrapper*       GetID3D12PipelineState_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12PipelineState_Wrapper>(id, id3d12_pipeline_state_map_); }
    const ID3D12PipelineState_Wrapper* GetID3D12PipelineState_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12PipelineState_Wrapper>(id, id3d12_pipeline_state_map_); }

    ID3D12ProtectedResourceSession_Wrapper*       GetID3D12ProtectedResourceSession_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12ProtectedResourceSession_Wrapper>(id, id3d12_protected_resource_session_map_); }
    const ID3D12ProtectedResourceSession_Wrapper* GetID3D12ProtectedResourceSession_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12ProtectedResourceSession_Wrapper>(id, id3d12_protected_resource_session_map_); }

    ID3D12QueryHeap_Wrapper*       GetID3D12QueryHeap_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12QueryHeap_Wrapper>(id, id3d12_query_heap_map_); }
    const ID3D12QueryHeap_Wrapper* GetID3D12QueryHeap_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12QueryHeap_Wrapper>(id, id3d12_query_heap_map_); }

    ID3D12Resource_Wrapper*       GetID3D12Resource_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Resource_Wrapper>(id, id3d12_resource_map_); }
    const ID3D12Resource_Wrapper* GetID3D12Resource_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Resource_Wrapper>(id, id3d12_resource_map_); }

    ID3D12RootSignature_Wrapper*       GetID3D12RootSignature_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12RootSignature_Wrapper>(id, id3d12_root_signature_map_); }
    const ID3D12RootSignature_Wrapper* GetID3D12RootSignature_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12RootSignature_Wrapper>(id, id3d12_root_signature_map_); }

    ID3D12RootSignatureDeserializer_Wrapper*       GetID3D12RootSignatureDeserializer_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12RootSignatureDeserializer_Wrapper>(id, id3d12_root_signature_deserializer_map_); }
    const ID3D12RootSignatureDeserializer_Wrapper* GetID3D12RootSignatureDeserializer_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12RootSignatureDeserializer_Wrapper>(id, id3d12_root_signature_deserializer_map_); }

    ID3D12SharingContract_Wrapper*       GetID3D12SharingContract_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12SharingContract_Wrapper>(id, id3d12_sharing_contract_map_); }
    const ID3D12SharingContract_Wrapper* GetID3D12SharingContract_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12SharingContract_Wrapper>(id, id3d12_sharing_contract_map_); }

    ID3D12StateObject_Wrapper*       GetID3D12StateObject_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12StateObject_Wrapper>(id, id3d12_state_object_map_); }
    const ID3D12StateObject_Wrapper* GetID3D12StateObject_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12StateObject_Wrapper>(id, id3d12_state_object_map_); }

    ID3D12StateObjectProperties_Wrapper*       GetID3D12StateObjectProperties_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12StateObjectProperties_Wrapper>(id, id3d12_state_object_properties_map_); }
    const ID3D12StateObjectProperties_Wrapper* GetID3D12StateObjectProperties_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12StateObjectProperties_Wrapper>(id, id3d12_state_object_properties_map_); }

    ID3D12SwapChainAssistant_Wrapper*       GetID3D12SwapChainAssistant_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12SwapChainAssistant_Wrapper>(id, id3d12_swap_chain_assistant_map_); }
    const ID3D12SwapChainAssistant_Wrapper* GetID3D12SwapChainAssistant_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12SwapChainAssistant_Wrapper>(id, id3d12_swap_chain_assistant_map_); }

    ID3D12Tools_Wrapper*       GetID3D12Tools_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12Tools_Wrapper>(id, id3d12_tools_map_); }
    const ID3D12Tools_Wrapper* GetID3D12Tools_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12Tools_Wrapper>(id, id3d12_tools_map_); }

    ID3D12VersionedRootSignatureDeserializer_Wrapper*       GetID3D12VersionedRootSignatureDeserializer_Wrapper(format::HandleId id)       { return GetWrapper<ID3D12VersionedRootSignatureDeserializer_Wrapper>(id, id3d12_versioned_root_signature_deserializer_map_); }
    const ID3D12VersionedRootSignatureDeserializer_Wrapper* GetID3D12VersionedRootSignatureDeserializer_Wrapper(format::HandleId id) const { return GetWrapper<ID3D12VersionedRootSignatureDeserializer_Wrapper>(id, id3d12_versioned_root_signature_deserializer_map_); }

    ID3DDestructionNotifier_Wrapper*       GetID3DDestructionNotifier_Wrapper(format::HandleId id)       { return GetWrapper<ID3DDestructionNotifier_Wrapper>(id, id3d_destruction_notifier_map_); }
    const ID3DDestructionNotifier_Wrapper* GetID3DDestructionNotifier_Wrapper(format::HandleId id) const { return GetWrapper<ID3DDestructionNotifier_Wrapper>(id, id3d_destruction_notifier_map_); }

    IDXGIAdapter_Wrapper*       GetIDXGIAdapter_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIAdapter_Wrapper>(id, idxgi_adapter_map_); }
    const IDXGIAdapter_Wrapper* GetIDXGIAdapter_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIAdapter_Wrapper>(id, idxgi_adapter_map_); }

    IDXGIDecodeSwapChain_Wrapper*       GetIDXGIDecodeSwapChain_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIDecodeSwapChain_Wrapper>(id, idxgi_decode_swap_chain_map_); }
    const IDXGIDecodeSwapChain_Wrapper* GetIDXGIDecodeSwapChain_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDecodeSwapChain_Wrapper>(id, idxgi_decode_swap_chain_map_); }

    IDXGIDevice_Wrapper*       GetIDXGIDevice_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIDevice_Wrapper>(id, idxgi_device_map_); }
    const IDXGIDevice_Wrapper* GetIDXGIDevice_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDevice_Wrapper>(id, idxgi_device_map_); }

    IDXGIDisplayControl_Wrapper*       GetIDXGIDisplayControl_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIDisplayControl_Wrapper>(id, idxgi_display_control_map_); }
    const IDXGIDisplayControl_Wrapper* GetIDXGIDisplayControl_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIDisplayControl_Wrapper>(id, idxgi_display_control_map_); }

    IDXGIFactory_Wrapper*       GetIDXGIFactory_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIFactory_Wrapper>(id, idxgi_factory_map_); }
    const IDXGIFactory_Wrapper* GetIDXGIFactory_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIFactory_Wrapper>(id, idxgi_factory_map_); }

    IDXGIFactoryMedia_Wrapper*       GetIDXGIFactoryMedia_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIFactoryMedia_Wrapper>(id, idxgi_factory_media_map_); }
    const IDXGIFactoryMedia_Wrapper* GetIDXGIFactoryMedia_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIFactoryMedia_Wrapper>(id, idxgi_factory_media_map_); }

    IDXGIKeyedMutex_Wrapper*       GetIDXGIKeyedMutex_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIKeyedMutex_Wrapper>(id, idxgi_keyed_mutex_map_); }
    const IDXGIKeyedMutex_Wrapper* GetIDXGIKeyedMutex_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIKeyedMutex_Wrapper>(id, idxgi_keyed_mutex_map_); }

    IDXGIOutput_Wrapper*       GetIDXGIOutput_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIOutput_Wrapper>(id, idxgi_output_map_); }
    const IDXGIOutput_Wrapper* GetIDXGIOutput_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIOutput_Wrapper>(id, idxgi_output_map_); }

    IDXGIOutputDuplication_Wrapper*       GetIDXGIOutputDuplication_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIOutputDuplication_Wrapper>(id, idxgi_output_duplication_map_); }
    const IDXGIOutputDuplication_Wrapper* GetIDXGIOutputDuplication_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIOutputDuplication_Wrapper>(id, idxgi_output_duplication_map_); }

    IDXGIResource_Wrapper*       GetIDXGIResource_Wrapper(format::HandleId id)       { return GetWrapper<IDXGIResource_Wrapper>(id, idxgi_resource_map_); }
    const IDXGIResource_Wrapper* GetIDXGIResource_Wrapper(format::HandleId id) const { return GetWrapper<IDXGIResource_Wrapper>(id, idxgi_resource_map_); }

    IDXGISurface_Wrapper*       GetIDXGISurface_Wrapper(format::HandleId id)       { return GetWrapper<IDXGISurface_Wrapper>(id, idxgi_surface_map_); }
    const IDXGISurface_Wrapper* GetIDXGISurface_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISurface_Wrapper>(id, idxgi_surface_map_); }

    IDXGISwapChain_Wrapper*       GetIDXGISwapChain_Wrapper(format::HandleId id)       { return GetWrapper<IDXGISwapChain_Wrapper>(id, idxgi_swap_chain_map_); }
    const IDXGISwapChain_Wrapper* GetIDXGISwapChain_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISwapChain_Wrapper>(id, idxgi_swap_chain_map_); }

    IDXGISwapChainMedia_Wrapper*       GetIDXGISwapChainMedia_Wrapper(format::HandleId id)       { return GetWrapper<IDXGISwapChainMedia_Wrapper>(id, idxgi_swap_chain_media_map_); }
    const IDXGISwapChainMedia_Wrapper* GetIDXGISwapChainMedia_Wrapper(format::HandleId id) const { return GetWrapper<IDXGISwapChainMedia_Wrapper>(id, idxgi_swap_chain_media_map_); }

    // clang-format on

  private:
    template <typename T>
    bool InsertEntry(format::HandleId id, T* wrapper, std::map<format::HandleId, T*>& map)
    {
        const auto& inserted = map.insert(std::make_pair(id, wrapper));
        return inserted.second;
    }

    template <typename Wrapper>
    bool RemoveEntry(const Wrapper* wrapper, std::map<format::HandleId, Wrapper*>& map)
    {
        assert(wrapper != nullptr);
        return (map.erase(wrapper->GetCaptureId()) != 0);
    }

    template <typename T>
    T* GetWrapper(format::HandleId id, std::map<format::HandleId, T*>& map)
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

    template <typename T>
    const T* GetWrapper(format::HandleId id, const std::map<format::HandleId, T*>& map) const
    {
        auto entry = map.find(id);
        return (entry != map.end()) ? entry->second : nullptr;
    }

  private:
    // clang-format off
    std::map<format::HandleId, ID3D10Blob_Wrapper*>                               id3d10_blob_map_;
    std::map<format::HandleId, ID3D12CommandAllocator_Wrapper*>                   id3d12_command_allocator_map_;
    std::map<format::HandleId, ID3D12CommandQueue_Wrapper*>                       id3d12_command_queue_map_;
    std::map<format::HandleId, ID3D12CommandSignature_Wrapper*>                   id3d12_command_signature_map_;
    std::map<format::HandleId, ID3D12Debug_Wrapper*>                              id3d12_debug_map_;
    std::map<format::HandleId, ID3D12Debug1_Wrapper*>                             id3d12_debug1_map_;
    std::map<format::HandleId, ID3D12Debug2_Wrapper*>                             id3d12_debug2_map_;
    std::map<format::HandleId, ID3D12DebugCommandList_Wrapper*>                   id3d12_debug_command_list_map_;
    std::map<format::HandleId, ID3D12DebugCommandList1_Wrapper*>                  id3d12_debug_command_list1_map_;
    std::map<format::HandleId, ID3D12DebugCommandQueue_Wrapper*>                  id3d12_debug_command_queue_map_;
    std::map<format::HandleId, ID3D12DebugDevice_Wrapper*>                        id3d12_debug_device_map_;
    std::map<format::HandleId, ID3D12DebugDevice1_Wrapper*>                       id3d12_debug_device1_map_;
    std::map<format::HandleId, ID3D12DescriptorHeap_Wrapper*>                     id3d12_descriptor_heap_map_;
    std::map<format::HandleId, ID3D12Device_Wrapper*>                             id3d12_device_map_;
    std::map<format::HandleId, ID3D12DeviceRemovedExtendedData_Wrapper*>          id3d12_device_removed_extended_data_map_;
    std::map<format::HandleId, ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>  id3d12_device_removed_extended_data_settings_map_;
    std::map<format::HandleId, ID3D12Fence_Wrapper*>                              id3d12_fence_map_;
    std::map<format::HandleId, ID3D12GraphicsCommandList_Wrapper*>                id3d12_graphics_command_list_map_;
    std::map<format::HandleId, ID3D12Heap_Wrapper*>                               id3d12_heap_map_;
    std::map<format::HandleId, ID3D12InfoQueue_Wrapper*>                          id3d12_info_queue_map_;
    std::map<format::HandleId, ID3D12LifetimeOwner_Wrapper*>                      id3d12_lifetime_owner_map_;
    std::map<format::HandleId, ID3D12LifetimeTracker_Wrapper*>                    id3d12_lifetime_tracker_map_;
    std::map<format::HandleId, ID3D12MetaCommand_Wrapper*>                        id3d12_meta_command_map_;
    std::map<format::HandleId, ID3D12PipelineLibrary_Wrapper*>                    id3d12_pipeline_library_map_;
    std::map<format::HandleId, ID3D12PipelineState_Wrapper*>                      id3d12_pipeline_state_map_;
    std::map<format::HandleId, ID3D12ProtectedResourceSession_Wrapper*>           id3d12_protected_resource_session_map_;
    std::map<format::HandleId, ID3D12QueryHeap_Wrapper*>                          id3d12_query_heap_map_;
    std::map<format::HandleId, ID3D12Resource_Wrapper*>                           id3d12_resource_map_;
    std::map<format::HandleId, ID3D12RootSignature_Wrapper*>                      id3d12_root_signature_map_;
    std::map<format::HandleId, ID3D12RootSignatureDeserializer_Wrapper*>          id3d12_root_signature_deserializer_map_;
    std::map<format::HandleId, ID3D12SharingContract_Wrapper*>                    id3d12_sharing_contract_map_;
    std::map<format::HandleId, ID3D12StateObject_Wrapper*>                        id3d12_state_object_map_;
    std::map<format::HandleId, ID3D12StateObjectProperties_Wrapper*>              id3d12_state_object_properties_map_;
    std::map<format::HandleId, ID3D12SwapChainAssistant_Wrapper*>                 id3d12_swap_chain_assistant_map_;
    std::map<format::HandleId, ID3D12Tools_Wrapper*>                              id3d12_tools_map_;
    std::map<format::HandleId, ID3D12VersionedRootSignatureDeserializer_Wrapper*> id3d12_versioned_root_signature_deserializer_map_;
    std::map<format::HandleId, ID3DDestructionNotifier_Wrapper*>                  id3d_destruction_notifier_map_;
    std::map<format::HandleId, IDXGIAdapter_Wrapper*>                             idxgi_adapter_map_;
    std::map<format::HandleId, IDXGIDecodeSwapChain_Wrapper*>                     idxgi_decode_swap_chain_map_;
    std::map<format::HandleId, IDXGIDevice_Wrapper*>                              idxgi_device_map_;
    std::map<format::HandleId, IDXGIDisplayControl_Wrapper*>                      idxgi_display_control_map_;
    std::map<format::HandleId, IDXGIFactory_Wrapper*>                             idxgi_factory_map_;
    std::map<format::HandleId, IDXGIFactoryMedia_Wrapper*>                        idxgi_factory_media_map_;
    std::map<format::HandleId, IDXGIKeyedMutex_Wrapper*>                          idxgi_keyed_mutex_map_;
    std::map<format::HandleId, IDXGIOutput_Wrapper*>                              idxgi_output_map_;
    std::map<format::HandleId, IDXGIOutputDuplication_Wrapper*>                   idxgi_output_duplication_map_;
    std::map<format::HandleId, IDXGIResource_Wrapper*>                            idxgi_resource_map_;
    std::map<format::HandleId, IDXGISurface_Wrapper*>                             idxgi_surface_map_;
    std::map<format::HandleId, IDXGISwapChain_Wrapper*>                           idxgi_swap_chain_map_;
    std::map<format::HandleId, IDXGISwapChainMedia_Wrapper*>                      idxgi_swap_chain_media_map_;
    // clang-format on
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_STATE_TABLE_H
