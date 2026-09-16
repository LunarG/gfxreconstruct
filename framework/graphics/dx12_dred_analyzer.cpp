/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#if defined(D3D12_SUPPORT) && defined(WIN32)

#include "graphics/dx12_util.h"
#include "util/logging.h"
#include "generated/generated_dx12_enum_to_string.h"
#include "nlohmann/json.hpp"

#include <cstdint>
#include <exception>
#include <filesystem>
#include <fstream>
#include <functional>
#include <sstream>
#include <string>
#include <system_error>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)
GFXRECON_BEGIN_NAMESPACE(dx12)

namespace
{

std::string BreadcrumbOpToString(D3D12_AUTO_BREADCRUMB_OP op)
{
    std::string full   = gfxrecon::util::ToString(op);
    std::string prefix = "D3D12_AUTO_BREADCRUMB_OP_";
    auto        pos    = full.find(prefix);
    if (pos != std::string::npos)
        return full.substr(pos + prefix.length());
    else
        return full;
}

std::string DredWideToUtf8(const wchar_t* w)
{
    if (w == nullptr)
        return std::string();
    int len = ::WideCharToMultiByte(CP_UTF8, 0, w, -1, nullptr, 0, nullptr, nullptr);
    if (len <= 1)
        return std::string();
    std::string out(static_cast<size_t>(len - 1), '\0');
    ::WideCharToMultiByte(CP_UTF8, 0, w, -1, out.data(), len, nullptr, nullptr);
    return out;
}

std::string DredObjectName(const char* name_a, const wchar_t* name_w)
{
    if (name_a != nullptr && name_a[0] != '\0')
        return std::string(name_a);
    std::string ws = DredWideToUtf8(name_w);
    return ws.empty() ? std::string("<unnamed>") : ws;
}

// Capture id 0 means "unknown"; emit JSON null so consumers don't read it as a real id.
nlohmann::ordered_json IdOrNull(uint64_t id)
{
    return (id != 0) ? nlohmann::ordered_json(id) : nlohmann::ordered_json(nullptr);
}

enum class DredBreadcrumbStatus
{
    kEmpty,
    kCompleted,
    kNotStarted,
    kInFlight
};

const char* DredStatusName(DredBreadcrumbStatus status)
{
    switch (status)
    {
        case DredBreadcrumbStatus::kEmpty:
            return "empty";
        case DredBreadcrumbStatus::kCompleted:
            return "completed";
        case DredBreadcrumbStatus::kNotStarted:
            return "not_started";
        case DredBreadcrumbStatus::kInFlight:
            return "in_flight";
        default:
            return "unknown";
    }
}

// Both values are uncapped running totals, so completed <= total under a conformant runtime; treat
// completed >= total as completed defensively.
DredBreadcrumbStatus ClassifyBreadcrumbStatus(UINT total_ops, UINT completed_ops)
{
    if (total_ops == 0)
        return DredBreadcrumbStatus::kEmpty;
    if (completed_ops >= total_ops)
        return DredBreadcrumbStatus::kCompleted;
    if (completed_ops == 0)
        return DredBreadcrumbStatus::kNotStarted;
    return DredBreadcrumbStatus::kInFlight;
}

// json is the serialized list; first_name/first_id carry the head entry for the summary digest.
struct DredAllocList
{
    nlohmann::ordered_json json  = nlohmann::ordered_json::array();
    uint32_t               count = 0;
    std::string            first_name;
    uint64_t               first_id = 0;
};

DredAllocList DredAllocationsToJson(const D3D12_DRED_ALLOCATION_NODE1*          node,
                                    const std::function<uint64_t(const void*)>& resolve_capture_id)
{
    DredAllocList result;
    while (node != nullptr)
    {
        const std::string name = DredObjectName(node->ObjectNameA, node->ObjectNameW);
        const uint64_t id = (resolve_capture_id && (node->pObject != nullptr)) ? resolve_capture_id(node->pObject) : 0;
        if (result.count == 0)
        {
            result.first_name = name;
            result.first_id   = id;
        }
        nlohmann::ordered_json elem;
        elem["name"]            = name;
        elem["object_id"]       = IdOrNull(id);
        elem["allocation_type"] = static_cast<int>(node->AllocationType);
        result.json.push_back(std::move(elem));
        ++result.count;
        node = node->pNext;
    }
    return result;
}

// out_status lets the caller tally per-status counts without re-deriving them from the JSON.
nlohmann::ordered_json BreadcrumbNodeToJson(int                                         index,
                                            const D3D12_AUTO_BREADCRUMB_NODE1*          node,
                                            const std::function<uint64_t(const void*)>& resolve_capture_id,
                                            DredBreadcrumbStatus&                       out_status)
{
    const UINT total     = node->BreadcrumbCount;
    const UINT completed = (node->pLastBreadcrumbValue != nullptr) ? *node->pLastBreadcrumbValue : 0;
    out_status           = ClassifyBreadcrumbStatus(total, completed);

    const uint64_t list_id =
        (resolve_capture_id && (node->pCommandList != nullptr)) ? resolve_capture_id(node->pCommandList) : 0;
    const uint64_t queue_id =
        (resolve_capture_id && (node->pCommandQueue != nullptr)) ? resolve_capture_id(node->pCommandQueue) : 0;

    nlohmann::ordered_json jnode;
    jnode["index"]            = index;
    jnode["command_list"]     = DredObjectName(node->pCommandListDebugNameA, node->pCommandListDebugNameW);
    jnode["command_list_id"]  = IdOrNull(list_id);
    jnode["command_queue"]    = DredObjectName(node->pCommandQueueDebugNameA, node->pCommandQueueDebugNameW);
    jnode["command_queue_id"] = IdOrNull(queue_id);
    jnode["total_ops"]        = total;
    jnode["completed_ops"]    = completed;
    jnode["status"]           = DredStatusName(out_status);

    if ((out_status == DredBreadcrumbStatus::kInFlight) && (node->pCommandHistory != nullptr))
    {
        nlohmann::ordered_json boundary;
        boundary["completed_ops"] = completed;
        if (completed > 0)
        {
            nlohmann::ordered_json last;
            last["index"]                 = completed - 1;
            last["op"]                    = BreadcrumbOpToString(node->pCommandHistory[completed - 1]);
            boundary["last_completed_op"] = std::move(last);
        }
        nlohmann::ordered_json next;
        next["index"] = completed;
        next["op"]    = BreadcrumbOpToString(node->pCommandHistory[completed]);
        for (UINT i = 0; (node->pBreadcrumbContexts != nullptr) && (i < node->BreadcrumbContextsCount); ++i)
        {
            if (node->pBreadcrumbContexts[i].BreadcrumbIndex == completed)
            {
                const std::string ctx = DredWideToUtf8(node->pBreadcrumbContexts[i].pContextString);
                if (!ctx.empty())
                    next["context"] = ctx;
                break;
            }
        }
        boundary["next_incomplete_op"] = std::move(next);
        jnode["fault_boundary"]        = std::move(boundary);
    }

    if ((node->pCommandHistory != nullptr) && (total > 0))
    {
        nlohmann::ordered_json history = nlohmann::ordered_json::array();
        for (UINT i = 0; i < total; ++i)
        {
            history.push_back(BreadcrumbOpToString(node->pCommandHistory[i]));
        }
        jnode["command_history"] = std::move(history);
    }

    if (node->BreadcrumbContextsCount && node->pBreadcrumbContexts)
    {
        nlohmann::ordered_json contexts = nlohmann::ordered_json::array();
        for (UINT i = 0; i < node->BreadcrumbContextsCount; ++i)
        {
            nlohmann::ordered_json ctx;
            ctx["breadcrumb_index"] = node->pBreadcrumbContexts[i].BreadcrumbIndex;
            ctx["context"]          = DredWideToUtf8(node->pBreadcrumbContexts[i].pContextString);
            contexts.push_back(std::move(ctx));
        }
        jnode["contexts"] = std::move(contexts);
    }

    return jnode;
}

// Precondition: jnode has a "fault_boundary" (the caller only passes in-flight nodes).
nlohmann::ordered_json SuspectFromNode(const nlohmann::ordered_json& jnode)
{
    const nlohmann::ordered_json& boundary = jnode.at("fault_boundary");

    nlohmann::ordered_json suspect;
    suspect["command_queue"]    = jnode.at("command_queue");
    suspect["command_list"]     = jnode.at("command_list");
    suspect["command_list_id"]  = jnode.at("command_list_id");
    suspect["halted_after_ops"] = jnode.at("completed_ops");
    suspect["total_ops"]        = jnode.at("total_ops");
    if (boundary.contains("last_completed_op"))
        suspect["last_completed_op"] = boundary.at("last_completed_op");
    suspect["next_incomplete_op"] = boundary.at("next_incomplete_op");
    return suspect;
}

// Renders from the summary JSON (the single source of truth) so the console and gfxrecon_dred.json
// never diverge.
void LogDredSummary(const nlohmann::ordered_json& summary)
{
    const nlohmann::ordered_json& counts = summary.at("breadcrumb_nodes");
    GFXRECON_LOG_ERROR("=== DRED Device-Removed Summary ===");
    GFXRECON_LOG_ERROR("Breadcrumb nodes: %u total | %u completed | %u in-flight | %u not-started",
                       counts.value("total", 0u),
                       counts.value("completed", 0u),
                       counts.value("in_flight", 0u),
                       counts.value("not_started", 0u));

    const nlohmann::ordered_json& suspects = summary.at("prime_suspects");
    if (suspects.empty())
    {
        GFXRECON_LOG_ERROR(
            "No in-flight command list found (GPU may have faulted outside breadcrumbed work; see full dump).");
    }
    else
    {
        GFXRECON_LOG_ERROR("PRIME SUSPECT(S) - GPU stopped mid-execution:");
        for (const nlohmann::ordered_json& s : suspects)
        {
            std::ostringstream line;
            line << "  - queue '" << s.value("command_queue", std::string("<unnamed>")) << "' / list '"
                 << s.value("command_list", std::string("<unnamed>")) << "'";
            if (!s.at("command_list_id").is_null())
                line << " [capture id " << s.at("command_list_id").get<uint64_t>() << "]";
            line << ": GPU halted after " << s.value("halted_after_ops", 0u) << "/" << s.value("total_ops", 0u)
                 << " ops";
            GFXRECON_LOG_ERROR("%s", line.str().c_str());

            if (s.contains("last_completed_op"))
            {
                const nlohmann::ordered_json& last = s.at("last_completed_op");
                GFXRECON_LOG_ERROR("      last completed op [%u]: %s",
                                   last.value("index", 0u),
                                   last.value("op", std::string()).c_str());
            }
            const nlohmann::ordered_json& next = s.at("next_incomplete_op");
            std::ostringstream            next_line;
            next_line << "      next/incomplete op [" << next.value("index", 0u)
                      << "]: " << next.value("op", std::string());
            if (next.contains("context"))
                next_line << " [context: " << next.value("context", std::string()) << "]";
            GFXRECON_LOG_ERROR("%s", next_line.str().c_str());
        }
    }

    const nlohmann::ordered_json& pf = summary.at("page_fault");
    if (!pf.is_null())
    {
        GFXRECON_LOG_ERROR("Page fault GPU VA: %s%s",
                           pf.value("gpu_va", std::string("0x0")).c_str(),
                           pf.value("null_dereference", false)
                               ? "  (null-pointer dereference - typically an unmapped/zero GPU address, e.g. "
                                 "an unremapped DXR shader-table or acceleration-structure address)"
                               : "");
        const uint32_t                existing_count = pf.value("existing_allocation_count", 0u);
        const uint32_t                freed_count    = pf.value("recent_freed_allocation_count", 0u);
        const nlohmann::ordered_json& reported       = pf.at("reported_allocation");
        const std::string             kind = reported.is_null() ? std::string() : reported.value("kind", std::string());
        const std::string             id_note =
            (reported.is_null() || reported.at("object_id").is_null())
                            ? std::string()
                            : (" [capture id " + std::to_string(reported.at("object_id").get<uint64_t>()) + "]");
        if (kind == "recently_freed")
        {
            GFXRECON_LOG_ERROR("Possible use-after-free: %u recently-freed allocation(s); most-recent freed: '%s'%s",
                               freed_count,
                               reported.value("name", std::string()).c_str(),
                               id_note.c_str());
        }
        else if (kind == "existing")
        {
            GFXRECON_LOG_ERROR("Allocations near fault: %u existing, %u recently-freed; an existing allocation: '%s'%s",
                               existing_count,
                               freed_count,
                               reported.value("name", std::string()).c_str(),
                               id_note.c_str());
        }
        else
        {
            GFXRECON_LOG_ERROR("Allocations near fault: %u existing, %u recently-freed", existing_count, freed_count);
        }
    }
}

} // namespace

void AnalyzeDeviceRemoved(ID3D12Device* device, const std::function<uint64_t(const void*)>& resolve_capture_id)
{
    ID3D12DeviceRemovedExtendedData1ComPtr dred = nullptr;
    if (FAILED(device->QueryInterface(IID_PPV_ARGS(&dred))) || (dred == nullptr))
    {
        GFXRECON_LOG_ERROR("DRED: ID3D12DeviceRemovedExtendedData1 is unavailable; cannot analyze the device "
                           "removal. Ensure replay was launched with --debug-device-lost.");
        return;
    }

    nlohmann::ordered_json nodes_json    = nlohmann::ordered_json::array();
    nlohmann::ordered_json suspects_json = nlohmann::ordered_json::array();
    uint32_t               n_completed = 0, n_in_flight = 0, n_not_started = 0;

    int                                 node_count  = 0;
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1 breadcrumbs = {};
    if (SUCCEEDED(dred->GetAutoBreadcrumbsOutput1(&breadcrumbs)))
    {
        for (const D3D12_AUTO_BREADCRUMB_NODE1* node = breadcrumbs.pHeadAutoBreadcrumbNode; node != nullptr;
             node                                    = node->pNext, ++node_count)
        {
            DredBreadcrumbStatus   status = DredBreadcrumbStatus::kEmpty;
            nlohmann::ordered_json jnode  = BreadcrumbNodeToJson(node_count, node, resolve_capture_id, status);

            switch (status)
            {
                case DredBreadcrumbStatus::kCompleted:
                    ++n_completed;
                    break;
                case DredBreadcrumbStatus::kInFlight:
                    ++n_in_flight;
                    break;
                case DredBreadcrumbStatus::kNotStarted:
                    ++n_not_started;
                    break;
                default:
                    break;
            }

            if ((status == DredBreadcrumbStatus::kInFlight) && jnode.contains("fault_boundary"))
            {
                suspects_json.push_back(SuspectFromNode(jnode));
            }
            nodes_json.push_back(std::move(jnode));
        }
    }
    const uint32_t n_total = static_cast<uint32_t>(node_count);

    bool          have_pf = false;
    uint64_t      pf_va   = 0;
    DredAllocList existing, freed;

    D3D12_DRED_PAGE_FAULT_OUTPUT1 page_fault = {};
    if (SUCCEEDED(dred->GetPageFaultAllocationOutput1(&page_fault)))
    {
        have_pf  = true;
        pf_va    = page_fault.PageFaultVA;
        existing = DredAllocationsToJson(page_fault.pHeadExistingAllocationNode, resolve_capture_id);
        freed    = DredAllocationsToJson(page_fault.pHeadRecentFreedAllocationNode, resolve_capture_id);
    }

    std::ostringstream va_stream;
    va_stream << "0x" << std::hex << pf_va;
    const std::string pf_va_str = va_stream.str();

    nlohmann::ordered_json pf_json = nullptr;
    if (have_pf)
    {
        pf_json                             = nlohmann::ordered_json::object();
        pf_json["gpu_va"]                   = pf_va_str;
        pf_json["existing_allocations"]     = std::move(existing.json);
        pf_json["recent_freed_allocations"] = std::move(freed.json);
    }

    nlohmann::ordered_json summary;
    {
        nlohmann::ordered_json counts;
        counts["total"]             = n_total;
        counts["completed"]         = n_completed;
        counts["in_flight"]         = n_in_flight;
        counts["not_started"]       = n_not_started;
        summary["breadcrumb_nodes"] = std::move(counts);
    }
    summary["prime_suspects"] = std::move(suspects_json);
    if (have_pf)
    {
        nlohmann::ordered_json pf_summary;
        pf_summary["gpu_va"]                        = pf_va_str;
        pf_summary["null_dereference"]              = (pf_va == 0);
        pf_summary["existing_allocation_count"]     = existing.count;
        pf_summary["recent_freed_allocation_count"] = freed.count;
        // DRED's existing / recently-freed lists are not sorted by proximity to the fault VA, so this
        // names the first entry DRED reported (most-recent first for the freed list), not a "nearest".
        if (freed.count > 0)
        {
            nlohmann::ordered_json reported;
            reported["kind"]                  = "recently_freed";
            reported["name"]                  = freed.first_name;
            reported["object_id"]             = IdOrNull(freed.first_id);
            pf_summary["reported_allocation"] = std::move(reported);
        }
        else if (existing.count > 0)
        {
            nlohmann::ordered_json reported;
            reported["kind"]                  = "existing";
            reported["name"]                  = existing.first_name;
            reported["object_id"]             = IdOrNull(existing.first_id);
            pf_summary["reported_allocation"] = std::move(reported);
        }
        else
        {
            pf_summary["reported_allocation"] = nullptr;
        }
        summary["page_fault"] = std::move(pf_summary);
    }
    else
    {
        summary["page_fault"] = nullptr;
    }

    nlohmann::ordered_json root;
    root["schema"]           = "gfxrecon-dred/2";
    root["summary"]          = std::move(summary);
    root["page_fault"]       = std::move(pf_json);
    root["breadcrumb_nodes"] = std::move(nodes_json);

    std::string           json_path;
    std::error_code       ec;
    std::filesystem::path p = std::filesystem::current_path(ec) / "gfxrecon_dred.json";
    json_path               = p.string();
    std::ofstream f(p, std::ios::binary | std::ios::trunc);
    if (f.is_open())
    {
        f << root.dump(2, ' ', false, nlohmann::ordered_json::error_handler_t::replace) << "\n";
        f.close();
        if (!f)
        {
            GFXRECON_LOG_WARNING("DRED: failed to write the full dump to '%s'.", json_path.c_str());
            json_path.clear();
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("DRED: failed to create the full dump file '%s'.", json_path.c_str());
        json_path.clear();
    }

    // Never let a JSON-key mismatch turn the diagnostic into an unhandled exception on this fatal path.
    try
    {
        LogDredSummary(root.at("summary"));
    }
    catch (const std::exception& e)
    {
        GFXRECON_LOG_ERROR("DRED: failed to render the device-removed summary (%s).", e.what());
    }

    if (!json_path.empty())
    {
        GFXRECON_LOG_ERROR(
            "Full DRED dump (all %u nodes, command histories, allocations): %s", n_total, json_path.c_str());
    }
}

GFXRECON_END_NAMESPACE(dx12)
GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // defined(D3D12_SUPPORT) && defined(WIN32)
