/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_REFERENCED_RESOURCE_TABLE_H
#define GFXRECON_DECODE_REFERENCED_RESOURCE_TABLE_H

#include "format/format.h"
#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class ReferencedResourceTable
{
  public:
    void AddResource(format::HandleId resource_id);

    void AddResource(format::HandleId parent_id, format::HandleId resource_id, bool add_children = false);

    void AddResource(size_t parent_id_count, const format::HandleId* parent_ids, format::HandleId resource_id);

    void AddResourceToContainer(format::HandleId container_id,
                                format::HandleId resource_id,
                                uint32_t         binding,
                                uint32_t         element);

    void AddResourceToUser(format::HandleId user_id, format::HandleId resource_id);

    void AddContainerToUser(format::HandleId user_id, format::HandleId container_id);

    void AddUserToUser(format::HandleId user_id, format::HandleId source_user_id);

    void AddContainer(format::HandleId pool_id, format::HandleId container_id);

    void AddUser(format::HandleId pool_id, format::HandleId user_id);

    void RemoveContainer(format::HandleId container_id);

    void RemoveUser(format::HandleId user_id);

    void ResetContainer(format::HandleId container_id);

    void ResetUser(format::HandleId user_id);

    void ResetContainers(format::HandleId pool_id);

    void ResetUsers(format::HandleId pool_id);

    void ClearContainers(format::HandleId pool_id);

    void ClearUsers(format::HandleId pool_id);

    void CopyContainerEntry(format::HandleId source_container_id,
                            uint32_t         source_binding,
                            uint32_t         source_element,
                            format::HandleId destination_container_id,
                            uint32_t         destination_binding,
                            uint32_t         destination_element);

    void ProcessUserSubmission(format::HandleId user_id);

    void GetReferencedResourceIds(std::unordered_set<format::HandleId>* referenced_ids,
                                  std::unordered_set<format::HandleId>* unreferenced_ids) const;

    void MarkResourceAsUsed(format::HandleId resource);

  private:
    // Track the referenced/used state of a resource (buffer, image, view, framebuffer).
    struct ResourceInfo
    {
        bool                                                              used{ false };
        bool                                                              is_child{ false };
        std::unordered_map<format::HandleId, std::weak_ptr<ResourceInfo>> child_infos;
    };

    // Track the referenced/used state of a resource container (descriptor set).
    struct ResourceContainerInfo
    {
        format::HandleId                                                  pool_id{ format::kNullHandleId };
        std::unordered_map<format::HandleId, std::weak_ptr<ResourceInfo>> resource_infos;

        // Table mapping a container binding to a handle.  Each binding contains a table of handles keyed by array
        // element index.
        std::unordered_map<uint32_t, std::unordered_map<uint32_t, format::HandleId>> resource_bindings;
    };

    // Track the state of a resource user (command buffer).
    struct ResourceUserInfo
    {
        format::HandleId                                                           pool_id{ format::kNullHandleId };
        std::unordered_map<format::HandleId, std::weak_ptr<ResourceInfo>>          resource_infos;
        std::unordered_map<format::HandleId, std::weak_ptr<ResourceContainerInfo>> container_infos;
    };

    typedef std::unordered_set<format::HandleId> PoolHandles;

  private:
    bool IsUsed(const ResourceInfo* resource_info) const;

  private:
    std::unordered_map<format::HandleId, std::shared_ptr<ResourceInfo>>          resources_;
    std::unordered_map<format::HandleId, std::shared_ptr<ResourceContainerInfo>> containers_;
    std::unordered_map<format::HandleId, std::shared_ptr<ResourceUserInfo>>      users_;
    std::unordered_map<format::HandleId, PoolHandles>                            container_pool_handles_;
    std::unordered_map<format::HandleId, PoolHandles>                            user_pool_handles_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_REFERENCED_RESOURCE_TABLE_H
