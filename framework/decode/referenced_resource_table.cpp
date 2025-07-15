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

#include "decode/referenced_resource_table.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void ReferencedResourceTable::AddResource(format::HandleId resource_id)
{
    if (resource_id != format::kNullHandleId)
    {
        resources_.emplace(resource_id, std::make_shared<ResourceInfo>());
    }
}

void ReferencedResourceTable::AddResource(format::HandleId parent_id, format::HandleId resource_id, bool add_children)
{
    if ((parent_id != format::kNullHandleId) && (resource_id != format::kNullHandleId))
    {
        auto parent_entry = resources_.find(parent_id);

        if (parent_entry != resources_.end())
        {
            auto& parent_info = parent_entry->second;
            assert(parent_info != nullptr);

            auto resource_entry = resources_.find(resource_id);
            if (resource_entry == resources_.end())
            {
                // The resource is not in the table, so add it to both the table and to the parent's child list.
                auto resource_info      = std::make_shared<ResourceInfo>();
                resource_info->is_child = true;

                parent_info->child_infos.emplace(
                    std::make_pair(resource_id, std::weak_ptr<ResourceInfo>{ resource_info }));
                resources_.emplace(resource_id, resource_info);
            }
            else
            {
                // The resource has already been added to the table, but has multiple parent objects (e.g. a framebuffer
                // is created from multiple image views), so we add it to the parent's child list.
                parent_info->child_infos.emplace(
                    std::make_pair(resource_id, std::weak_ptr<ResourceInfo>{ resource_entry->second }));

                if (add_children)
                {
                    for (const auto& child : resource_entry->second->child_infos)
                    {
                        parent_info->child_infos.emplace(
                            std::make_pair(child.first, std::weak_ptr<ResourceInfo>{ child.second }));
                    }
                }
            }
        }
    }
}

void ReferencedResourceTable::AddResource(size_t                  parent_id_count,
                                          const format::HandleId* parent_ids,
                                          format::HandleId        resource_id)
{
    if ((parent_ids != nullptr) && (resource_id != format::kNullHandleId))
    {
        for (size_t i = 0; i < parent_id_count; ++i)
        {
            AddResource(parent_ids[i], resource_id);
        }
    }
}

void ReferencedResourceTable::AddResourceToContainer(format::HandleId container_id,
                                                     format::HandleId resource_id,
                                                     uint32_t         binding,
                                                     uint32_t         element)
{
    if ((container_id != format::kNullHandleId) && (resource_id != format::kNullHandleId))
    {
        auto container_entry = containers_.find(container_id);
        if (container_entry != containers_.end())
        {
            auto& container_info = container_entry->second;
            auto  resource_entry = resources_.find(resource_id);

            if (resource_entry != resources_.end())
            {
                auto& resource_info = resource_entry->second;
                assert((container_info != nullptr) && (resource_info != nullptr));

                container_info->resource_infos.emplace(resource_id, std::weak_ptr<ResourceInfo>{ resource_info });
                container_info->resource_bindings[binding].insert(std::make_pair(element, resource_id));
            }
        }
    }
}

void ReferencedResourceTable::AddResourceToUser(format::HandleId user_id, format::HandleId resource_id)
{
    if ((user_id != format::kNullHandleId) && (resource_id != format::kNullHandleId))
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info      = user_entry->second;
            auto  resource_entry = resources_.find(resource_id);

            if (resource_entry != resources_.end())
            {
                auto& resource_info = resource_entry->second;
                assert((user_info != nullptr) && (resource_info != nullptr));

                user_info->resource_infos.emplace(resource_id, std::weak_ptr<ResourceInfo>{ resource_info });
            }
        }
    }
}

void ReferencedResourceTable::AddContainerToUser(format::HandleId user_id, format::HandleId container_id)
{
    if ((user_id != format::kNullHandleId) && (container_id != format::kNullHandleId))
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info       = user_entry->second;
            auto  container_entry = containers_.find(container_id);

            if (container_entry != containers_.end())
            {
                auto& container_info = container_entry->second;
                assert((user_info != nullptr) && (container_info != nullptr));

                user_info->container_infos.emplace(container_id,
                                                   std::weak_ptr<ResourceContainerInfo>{ container_info });
            }
        }
    }
}

void ReferencedResourceTable::AddUserToUser(format::HandleId user_id, format::HandleId source_user_id)
{
    if ((user_id != format::kNullHandleId) && (source_user_id != format::kNullHandleId))
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info         = user_entry->second;
            auto  source_user_entry = users_.find(source_user_id);

            if (source_user_entry != users_.end())
            {
                auto& source_user_info = source_user_entry->second;
                assert((user_info != nullptr) && (source_user_info != nullptr));

                // Copy resource and container info from source user to destination user.
                auto&       resource_infos         = user_info->resource_infos;
                auto&       container_infos        = user_info->container_infos;
                const auto& source_resource_infos  = source_user_info->resource_infos;
                const auto& source_container_infos = source_user_info->container_infos;

                for (auto& source_resource_info : source_resource_infos)
                {
                    if (!source_resource_info.second.expired())
                    {
                        resource_infos.insert(source_resource_info);
                    }
                }

                for (auto& source_container_info : source_container_infos)
                {
                    if (!source_container_info.second.expired())
                    {
                        container_infos.insert(source_container_info);
                    }
                }
            }
        }
    }
}

void ReferencedResourceTable::AddContainer(format::HandleId pool_id, format::HandleId container_id)
{
    if ((pool_id != format::kNullHandleId) && (container_id != format::kNullHandleId))
    {
        auto container_info     = std::make_shared<ResourceContainerInfo>();
        container_info->pool_id = pool_id;
        containers_.emplace(container_id, std::move(container_info));
        container_pool_handles_[pool_id].insert(container_id);
    }
}

void ReferencedResourceTable::AddUser(format::HandleId pool_id, format::HandleId user_id)
{
    if ((pool_id != format::kNullHandleId) && (user_id != format::kNullHandleId))
    {
        auto user_info     = std::make_shared<ResourceUserInfo>();
        user_info->pool_id = pool_id;
        users_.emplace(user_id, std::move(user_info));
        user_pool_handles_[pool_id].insert(user_id);
    }
}

void ReferencedResourceTable::RemoveContainer(format::HandleId container_id)
{
    if (container_id != format::kNullHandleId)
    {
        auto container_entry = containers_.find(container_id);
        if (container_entry != containers_.end())
        {
            auto& container_info = container_entry->second;
            assert(container_info != nullptr);

            container_pool_handles_[container_info->pool_id].erase(container_id);
            containers_.erase(container_entry);
        }
    }
}

void ReferencedResourceTable::RemoveUser(format::HandleId user_id)
{
    if (user_id != format::kNullHandleId)
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info = user_entry->second;
            assert(user_info != nullptr);

            user_pool_handles_[user_info->pool_id].erase(user_id);
            users_.erase(user_entry);
        }
    }
}

void ReferencedResourceTable::ResetContainer(format::HandleId container_id)
{
    if (container_id != format::kNullHandleId)
    {
        auto container_entry = containers_.find(container_id);
        if (container_entry != containers_.end())
        {
            auto& container_info = container_entry->second;
            assert(container_info != nullptr);

            container_info->resource_infos.clear();
            container_info->resource_bindings.clear();
        }
    }
}

void ReferencedResourceTable::ResetUser(format::HandleId user_id)
{
    if (user_id != format::kNullHandleId)
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info = user_entry->second;
            assert(user_info != nullptr);

            user_info->resource_infos.clear();
            user_info->container_infos.clear();
        }
    }
}

void ReferencedResourceTable::ResetContainers(format::HandleId pool_id)
{
    if (pool_id != format::kNullHandleId)
    {
        auto& container_ids = container_pool_handles_[pool_id];
        for (auto container_id : container_ids)
        {
            ResetContainer(container_id);
        }
    }
}

void ReferencedResourceTable::ResetUsers(format::HandleId pool_id)
{
    if (pool_id != format::kNullHandleId)
    {
        auto& user_ids = user_pool_handles_[pool_id];
        for (auto user_id : user_ids)
        {
            ResetUser(user_id);
        }
    }
}

void ReferencedResourceTable::ClearContainers(format::HandleId pool_id)
{
    if (pool_id != format::kNullHandleId)
    {
        auto& container_ids = container_pool_handles_[pool_id];
        for (auto container_id : container_ids)
        {
            containers_.erase(container_id);
        }

        container_ids.clear();
    }
}

void ReferencedResourceTable::ClearUsers(format::HandleId pool_id)
{
    if (pool_id != format::kNullHandleId)
    {
        auto& user_ids = user_pool_handles_[pool_id];
        for (auto user_id : user_ids)
        {
            users_.erase(user_id);
        }

        user_ids.clear();
    }
}

void ReferencedResourceTable::CopyContainerEntry(format::HandleId source_container_id,
                                                 uint32_t         source_binding,
                                                 uint32_t         source_element,
                                                 format::HandleId destination_container_id,
                                                 uint32_t         destination_binding,
                                                 uint32_t         destination_element)
{
    if (source_container_id != format::kNullHandleId)
    {
        const auto container_entry = containers_.find(source_container_id);
        if (container_entry != containers_.end())
        {
            const auto& container_info = container_entry->second;
            const auto  binding_entry  = container_info->resource_bindings.find(source_binding);
            if (binding_entry != container_info->resource_bindings.end())
            {
                const auto& binding_elements = binding_entry->second;
                const auto  element_entry    = binding_elements.find(source_element);
                if (element_entry != binding_elements.end())
                {
                    AddResourceToContainer(
                        destination_container_id, element_entry->second, destination_binding, destination_element);
                }
            }
        }
    }
}

void ReferencedResourceTable::ProcessUserSubmission(format::HandleId user_id)
{
    if (user_id != format::kNullHandleId)
    {
        auto user_entry = users_.find(user_id);
        if (user_entry != users_.end())
        {
            auto& user_info = user_entry->second;
            assert(user_info != nullptr);

            auto& resource_infos  = user_info->resource_infos;
            auto& container_infos = user_info->container_infos;

            for (auto& resource_info : resource_infos)
            {
                if (!resource_info.second.expired())
                {
                    auto resource_info_ptr  = resource_info.second.lock();
                    resource_info_ptr->used = true;

                    for (auto& child : resource_info_ptr->child_infos)
                    {
                        auto child_info_ptr  = child.second.lock();
                        child_info_ptr->used = true;
                    }
                }
            }

            for (auto& container_info : container_infos)
            {
                if (!container_info.second.expired())
                {
                    auto container_info_ptr = container_info.second.lock();
                    for (auto& resource_info : container_info_ptr->resource_infos)
                    {
                        if (!resource_info.second.expired())
                        {
                            auto resource_info_ptr  = resource_info.second.lock();
                            resource_info_ptr->used = true;

                            for (auto& child : resource_info_ptr->child_infos)
                            {
                                auto child_info_ptr  = child.second.lock();
                                child_info_ptr->used = true;
                            }
                        }
                    }
                }
            }
        }
    }
}

void ReferencedResourceTable::GetReferencedResourceIds(std::unordered_set<format::HandleId>* referenced_ids,
                                                       std::unordered_set<format::HandleId>* unreferenced_ids) const
{
    for (auto resource_entry : resources_)
    {
        auto& resource_info = resource_entry.second;

        if (!resource_info->is_child)
        {
            bool used = IsUsed(resource_info.get());

            if (used && (referenced_ids != nullptr))
            {
                referenced_ids->insert(resource_entry.first);

                for (const auto& child : resource_entry.second->child_infos)
                {
                    referenced_ids->insert(child.first);
                }
            }
            else if (!used && (unreferenced_ids != nullptr))
            {
                unreferenced_ids->insert(resource_entry.first);
            }
        }
    }
}

bool ReferencedResourceTable::IsUsed(const ResourceInfo* resource_info) const
{
    assert(resource_info != nullptr);

    if (resource_info->used)
    {
        return true;
    }
    else
    {
        // If the resource was not used directly, check to see if it was used indirectly through a child.
        for (const auto& child_info : resource_info->child_infos)
        {
            if (!child_info.second.expired())
            {
                const auto child_info_ptr = child_info.second.lock();
                if (IsUsed(child_info_ptr.get()))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void ReferencedResourceTable::MarkResourceAsUsed(format::HandleId resource)
{
    auto resource_entry = resources_.find(resource);
    if (resource_entry != resources_.end())
    {
        resource_entry->second->used = true;
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
