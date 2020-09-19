/*
** Copyright (c) 2020 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_REFERENCED_RESOURCE_TABLE_H
#define GFXRECON_DECODE_REFERENCED_RESOURCE_TABLE_H

#include "format/format.h"
#include "util/defines.h"

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

    void AddResource(format::HandleId parent_id, format::HandleId resource_id);

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

  private:
    // Track the referenced/used state of a resource (buffer, image, view, framebuffer).
    struct ResourceInfo
    {
        bool                                     used{ false };
        bool                                     is_child{ false };
        std::vector<std::weak_ptr<ResourceInfo>> child_infos;
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
