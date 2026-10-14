/*
** Copyright (c) 2024-2026 LunarG, Inc.
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

#include "spirv_parsing_util.h"
#include "util/spirv_helper.h"
#include "util/logging.h"

#include <unordered_map>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

GFXRECON_BEGIN_NAMESPACE(spirv_parsing)

using BufferReferenceInfo     = SpirVParsingUtil::BufferReferenceInfo;
using BufferReferenceLocation = SpirVParsingUtil::BufferReferenceLocation;

// bounds the walks over types and values, legal modules stay far below
constexpr uint32_t kMaxDepth = 64;

// stops the forward walk of a single loaded value
constexpr size_t kMaxEscapeValues = 4096;

static BufferReferenceLocation LocationOf(uint32_t storage_class)
{
    switch (storage_class)
    {
        case spv::StorageClassUniform:
            return BufferReferenceLocation::UNIFORM_BUFFER;
        case spv::StorageClassStorageBuffer:
            return BufferReferenceLocation::STORAGE_BUFFER;
        case spv::StorageClassShaderRecordBufferKHR:
            return BufferReferenceLocation::SHADER_RECORD_BUFFER;
        case spv::StorageClassPushConstant:
            return BufferReferenceLocation::PUSH_CONSTANT_BLOCK;
        default:
            return BufferReferenceLocation::INVALID;
    }
}

namespace
{
// Finds the buffer-device-addresses that a module reads from descriptor- or push-constant memory.
//
// - every PhysicalStorageBuffer pointer field of a block, read or not, never stepping into a pointee
// - pointer fields whose pointee starts with an array of pointers, as a chain (same key, element stride)
// - integer fields (uint64, uvec2) that the module converts to a pointer, or that leave the shader
class Module
{
  public:
    Module(const uint32_t* words, size_t num_words) : words_(words), num_words_(num_words) {}

    //! false for a malformed module
    bool Parse();

    void FindBufferReferences(std::set<BufferReferenceInfo>& buffer_references);

    //! the module cannot hold buffer-references, Parse stopped early
    bool skipped() const { return skipped_; }

  private:
    using Path = std::vector<uint32_t>;

    static uint32_t Op(const uint32_t* insn) { return insn[0] & 0xffffu; }
    static uint32_t Length(const uint32_t* insn) { return insn[0] >> 16; }

    const uint32_t* Def(uint32_t id) const;
    uint32_t        TypeOf(uint32_t id) const;
    uint32_t        ArrayStride(uint32_t type_id) const;
    bool            MemberOffset(uint32_t struct_id, uint32_t member, uint32_t& offset) const;

    bool IsPsbPointer(uint32_t type_id) const;
    bool IsUint64(uint32_t type_id) const;
    bool IsUvec2(uint32_t type_id) const;
    bool IsAddressInteger(uint32_t type_id) const;
    bool HoldsAddressInteger(uint32_t type_id, uint32_t depth) const;

    //! a descriptor-array selects a descriptor, not memory inside the block
    uint32_t PeelDescriptorArray(uint32_t type_id) const;

    //! element stride when a pointee starts with an array of pointers, 0 otherwise
    uint32_t ChainStride(uint32_t pointer_type_id, uint32_t pointee_type_id) const;

    bool BlockOf(uint32_t variable_id, BufferReferenceInfo& info, uint32_t& block_type_id) const;
    void Add(const BufferReferenceInfo& info);

    void WalkPointerFields(uint32_t type_id, BufferReferenceInfo info, uint32_t depth);
    void WalkIntegerFields(uint32_t type_id, BufferReferenceInfo info, uint32_t depth);

    //! value -> the block memory it was loaded from, 'path' indexes into the loaded value
    void TraceValue(uint32_t id, const Path& path, uint32_t depth);

    //! pointer -> variable and access-chain, then resolve the field
    void TracePointer(uint32_t id, const Path& path, uint32_t depth);
    //! the first 'num_ids' indices are access-chain ids, the rest are literals
    void Resolve(BufferReferenceInfo info, uint32_t block_type_id, const Path& indices, size_t num_ids);

    //! local variable that a pointer leads to through access-chains, 0 if none
    uint32_t LocalBase(uint32_t pointer_id) const;

    //! the arguments passed for a function-parameter, at every call-site
    std::vector<uint32_t> CallArguments(uint32_t parameter_id) const;

    //! access-chain ids as literal indices (a dynamic index becomes 0), followed by 'path'
    Path Literals(const Path& indices, const Path& path) const;

    //! paths into a loaded value whose content leaves the shader
    std::set<Path> EscapingPaths(uint32_t loaded_id);
    void           BuildUses();

    const uint32_t* words_;
    size_t          num_words_;
    bool            skipped_ = false;

    // result-id -> word position of the defining instruction
    std::vector<uint32_t> definitions_;

    std::unordered_map<uint32_t, uint32_t> bindings_;
    std::unordered_map<uint32_t, uint32_t> sets_;
    std::unordered_map<uint32_t, uint32_t> array_strides_;

    // (struct-type-id << 32 | member-index) -> byte-offset
    std::unordered_map<uint64_t, uint32_t> member_offsets_;

    std::vector<uint32_t>                                       block_variables_;
    std::unordered_set<uint32_t>                                local_variables_;
    std::vector<std::pair<uint32_t, uint32_t>>                  stores_;
    std::vector<uint32_t>                                       loads_;
    std::vector<uint32_t>                                       conversions_;
    std::vector<uint32_t>                                       calls_;
    std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>> parameters_; // id -> function-id, index

    // id -> word positions of the instructions using it, built on demand
    std::unordered_map<uint32_t, std::vector<uint32_t>> uses_;
    uint32_t                                            first_function_ = 0;
    bool                                                uses_built_     = false;

    // the module turns uvec2 into pointers, so uvec2 fields can hold addresses
    bool uvec2_addresses_ = false;

    // TracePointer reports address-sized integers in read-mode, instead of tracing further
    bool read_mode_ = false;

    std::unordered_set<uint32_t>   visited_;
    std::set<BufferReferenceInfo>* buffer_references_ = nullptr;
};
} // namespace

bool Module::Parse()
{
    // spirv-header is 5 words, the id-bound is word 3
    constexpr size_t spirv_header_size = 5;

    if (num_words_ < spirv_header_size)
    {
        return false;
    }

    bool     has_capability   = false;
    bool     has_psb_type     = false;
    uint32_t current_function = 0;
    uint32_t parameter_index  = 0;

    for (size_t i = spirv_header_size; i < num_words_;)
    {
        const uint32_t* insn   = words_ + i;
        const uint32_t  op     = Op(insn);
        const uint32_t  length = Length(insn);

        if (length == 0 || i + length > num_words_)
        {
            GFXRECON_LOG_WARNING("SpirVParsingUtil: malformed module, instruction at word %zu", i);
            return false;
        }

        // capabilities come first, without PhysicalStorageBufferAddresses there is nothing to find
        if (op != spv::OpCapability && definitions_.empty())
        {
            if (!has_capability)
            {
                skipped_ = true;
                return true;
            }
            definitions_.assign(words_[3], 0);
        }

        const bool     has_type     = OpcodeHasType(op);
        const uint32_t result_index = has_type ? 2 : 1;
        if ((OpcodeHasResult(op) || op == spv::OpTypeUntypedPointerKHR) && length > result_index &&
            insn[result_index] < definitions_.size())
        {
            definitions_[insn[result_index]] = static_cast<uint32_t>(i);
        }

        switch (op)
        {
            case spv::OpCapability:
                has_capability |= insn[1] == spv::CapabilityPhysicalStorageBufferAddresses;
                break;
            case spv::OpTypePointer:
            case spv::OpTypeUntypedPointerKHR:
            case spv::OpTypeForwardPointer:
                has_psb_type |= insn[2] == spv::StorageClassPhysicalStorageBuffer;
                break;
            case spv::OpDecorate:
                if (insn[2] == spv::DecorationBinding)
                {
                    bindings_[insn[1]] = insn[3];
                }
                else if (insn[2] == spv::DecorationDescriptorSet)
                {
                    sets_[insn[1]] = insn[3];
                }
                else if (insn[2] == spv::DecorationArrayStride)
                {
                    array_strides_[insn[1]] = insn[3];
                }
                break;
            case spv::OpMemberDecorate:
                if (insn[3] == spv::DecorationOffset)
                {
                    member_offsets_[(uint64_t{ insn[1] } << 32) | insn[2]] = insn[4];
                }
                break;
            case spv::OpVariable:
                if (LocationOf(insn[3]) != BufferReferenceLocation::INVALID)
                {
                    block_variables_.push_back(insn[2]);
                }
                else if (insn[3] == spv::StorageClassFunction || insn[3] == spv::StorageClassPrivate)
                {
                    local_variables_.insert(insn[2]);
                }
                break;
            case spv::OpFunction:
                // all types are known here, without a PhysicalStorageBuffer pointer there is nothing to find
                if (!has_psb_type)
                {
                    skipped_ = true;
                    return true;
                }
                if (first_function_ == 0)
                {
                    first_function_ = static_cast<uint32_t>(i);
                }
                current_function = insn[2];
                parameter_index  = 0;
                break;
            case spv::OpFunctionParameter:
                parameters_[insn[2]] = { current_function, parameter_index++ };
                break;
            case spv::OpFunctionCall:
                calls_.push_back(static_cast<uint32_t>(i));
                break;
            case spv::OpStore:
                stores_.emplace_back(insn[1], insn[2]);
                break;
            case spv::OpLoad:
                loads_.push_back(static_cast<uint32_t>(i));
                break;
            case spv::OpConvertUToPtr:
            case spv::OpBitcast:
                conversions_.push_back(static_cast<uint32_t>(i));
                break;
            default:
                break;
        }
        i += length;
    }

    // a module without functions
    skipped_ = !has_psb_type;
    return true;
}

void Module::FindBufferReferences(std::set<BufferReferenceInfo>& buffer_references)
{
    buffer_references_ = &buffer_references;

    for (const uint32_t variable_id : block_variables_)
    {
        BufferReferenceInfo info;
        uint32_t            block_type_id = 0;
        if (BlockOf(variable_id, info, block_type_id))
        {
            WalkPointerFields(PeelDescriptorArray(block_type_id), info, 0);
        }
    }

    for (const uint32_t position : conversions_)
    {
        const uint32_t* insn = words_ + position;

        // only integer -> pointer, a pointer -> pointer cast has its own origin
        if (IsPsbPointer(insn[1]) && !IsPsbPointer(TypeOf(insn[3])))
        {
            visited_.clear();
            TraceValue(insn[3], {}, 0);
        }
    }

    // an address can leave the shader through memory, without a conversion in this module
    read_mode_ = true;
    for (const uint32_t position : loads_)
    {
        const uint32_t* insn = words_ + position;
        if (HoldsAddressInteger(insn[1], 0))
        {
            for (const Path& path : EscapingPaths(insn[2]))
            {
                TracePointer(insn[3], path, 0);
            }
        }
    }
    read_mode_ = false;
}

const uint32_t* Module::Def(const uint32_t id) const
{
    return (id < definitions_.size() && definitions_[id] != 0) ? words_ + definitions_[id] : nullptr;
}

uint32_t Module::TypeOf(const uint32_t id) const
{
    const uint32_t* insn = Def(id);
    return (insn != nullptr && OpcodeHasType(Op(insn))) ? insn[1] : 0;
}

uint32_t Module::ArrayStride(const uint32_t type_id) const
{
    const auto it = array_strides_.find(type_id);
    return it != array_strides_.end() ? it->second : 0;
}

bool Module::MemberOffset(const uint32_t struct_id, const uint32_t member, uint32_t& offset) const
{
    const auto it = member_offsets_.find((uint64_t{ struct_id } << 32) | member);
    if (it == member_offsets_.end())
    {
        return false;
    }
    offset = it->second;
    return true;
}

bool Module::IsPsbPointer(const uint32_t type_id) const
{
    const uint32_t* type = Def(type_id);
    return type != nullptr && (Op(type) == spv::OpTypePointer || Op(type) == spv::OpTypeUntypedPointerKHR) &&
           type[2] == spv::StorageClassPhysicalStorageBuffer;
}

bool Module::IsUint64(const uint32_t type_id) const
{
    const uint32_t* type = Def(type_id);
    return type != nullptr && Op(type) == spv::OpTypeInt && type[2] == 64;
}

bool Module::IsUvec2(const uint32_t type_id) const
{
    const uint32_t* type = Def(type_id);
    if (type == nullptr || Op(type) != spv::OpTypeVector || type[3] != 2)
    {
        return false;
    }
    const uint32_t* component = Def(type[2]);
    return component != nullptr && Op(component) == spv::OpTypeInt && component[2] == 32;
}

bool Module::IsAddressInteger(uint32_t type_id) const
{
    return IsUint64(type_id) || (uvec2_addresses_ && IsUvec2(type_id));
}

bool Module::HoldsAddressInteger(uint32_t type_id, uint32_t depth) const
{
    const uint32_t* type = Def(type_id);
    if (type == nullptr || depth > kMaxDepth)
    {
        return false;
    }
    if (IsAddressInteger(type_id))
    {
        return true;
    }
    if (Op(type) == spv::OpTypeStruct)
    {
        for (uint32_t i = 2; i < Length(type); ++i)
        {
            if (HoldsAddressInteger(type[i], depth + 1))
            {
                return true;
            }
        }
        return false;
    }
    if (Op(type) == spv::OpTypeArray || Op(type) == spv::OpTypeRuntimeArray)
    {
        return HoldsAddressInteger(type[2], depth + 1);
    }
    return false;
}

uint32_t Module::PeelDescriptorArray(uint32_t type_id) const
{
    if (const uint32_t* type = Def(type_id); type != nullptr &&
                                             (Op(type) == spv::OpTypeArray || Op(type) == spv::OpTypeRuntimeArray) &&
                                             ArrayStride(type_id) == 0)
    {
        return type[2];
    }
    return type_id;
}

uint32_t Module::ChainStride(uint32_t pointer_type_id, uint32_t pointee_type_id) const
{
    // element stride of an array of pointers, 8 bytes if not decorated
    auto stride_of = [this](const uint32_t array_type_id) {
        const uint32_t stride = ArrayStride(array_type_id);
        return stride != 0 ? stride : static_cast<uint32_t>(sizeof(uint64_t));
    };

    const uint32_t* pointee = Def(pointee_type_id);
    if (pointee == nullptr)
    {
        return 0;
    }

    // T**, the stride sits on the outer pointer-type
    if (IsPsbPointer(pointee_type_id))
    {
        return stride_of(pointer_type_id);
    }
    if ((Op(pointee) == spv::OpTypeArray || Op(pointee) == spv::OpTypeRuntimeArray) && IsPsbPointer(pointee[2]))
    {
        return stride_of(pointee_type_id);
    }

    // a struct that starts with an array of pointers
    if (uint32_t offset = 0; Op(pointee) == spv::OpTypeStruct && Length(pointee) > 2 &&
                             MemberOffset(pointee_type_id, 0, offset) && offset == 0)
    {
        if (const uint32_t* member = Def(pointee[2]);
            member != nullptr && (Op(member) == spv::OpTypeArray || Op(member) == spv::OpTypeRuntimeArray) &&
            IsPsbPointer(member[2]))
        {
            return stride_of(pointee[2]);
        }
    }
    return 0;
}

bool Module::BlockOf(uint32_t variable_id, BufferReferenceInfo& info, uint32_t& block_type_id) const
{
    const uint32_t* variable = Def(variable_id);
    if (variable == nullptr || Op(variable) != spv::OpVariable)
    {
        return false;
    }
    info.source = LocationOf(variable[3]);
    if (info.source == BufferReferenceLocation::INVALID)
    {
        return false;
    }
    const uint32_t* pointer_type = Def(variable[1]);
    if (pointer_type == nullptr || Op(pointer_type) != spv::OpTypePointer)
    {
        return false;
    }
    block_type_id = pointer_type[3];

    if (info.source == BufferReferenceLocation::UNIFORM_BUFFER ||
        info.source == BufferReferenceLocation::STORAGE_BUFFER)
    {
        const auto set     = sets_.find(variable_id);
        const auto binding = bindings_.find(variable_id);
        info.set           = set != sets_.end() ? set->second : 0;
        info.binding       = binding != bindings_.end() ? binding->second : 0;
    }
    return true;
}

void Module::Add(const BufferReferenceInfo& info)
{
    buffer_references_->insert(info);
}

void Module::WalkPointerFields(uint32_t type_id, BufferReferenceInfo info, uint32_t depth)
{
    const uint32_t* type = Def(type_id);
    if (type == nullptr || depth > kMaxDepth)
    {
        return;
    }

    switch (Op(type))
    {
        case spv::OpTypePointer:
        case spv::OpTypeUntypedPointerKHR:
            if (type[2] != spv::StorageClassPhysicalStorageBuffer)
            {
                return;
            }
            Add(info);

            if (Op(type) == spv::OpTypePointer)
            {
                // pointer to an array of pointers, identified by an equal key with the element stride
                if (const uint32_t stride = ChainStride(type_id, type[3]))
                {
                    BufferReferenceInfo chain = info;
                    chain.array_stride        = stride;
                    Add(chain);
                }
            }
            // never step into the pointee, it is a different buffer
            return;
        case spv::OpTypeStruct:
            for (uint32_t member = 0; member + 2 < Length(type); ++member)
            {
                if (uint32_t offset = 0; MemberOffset(type_id, member, offset))
                {
                    BufferReferenceInfo member_info = info;
                    member_info.buffer_offset += offset;
                    WalkPointerFields(type[2 + member], member_info, depth + 1);
                }
            }
            return;
        case spv::OpTypeArray:
        case spv::OpTypeRuntimeArray:
            if (const uint32_t stride = ArrayStride(type_id))
            {
                info.array_stride = stride;
            }
            WalkPointerFields(type[2], info, depth + 1);
            return;
        default:
            return;
    }
}

void Module::WalkIntegerFields(uint32_t type_id, BufferReferenceInfo info, uint32_t depth)
{
    const uint32_t* type = Def(type_id);
    if (type == nullptr || depth > kMaxDepth)
    {
        return;
    }
    if (IsAddressInteger(type_id))
    {
        Add(info);
        return;
    }
    if (Op(type) == spv::OpTypeStruct)
    {
        for (uint32_t member = 0; member + 2 < Length(type); ++member)
        {
            if (uint32_t offset = 0; MemberOffset(type_id, member, offset))
            {
                BufferReferenceInfo member_info = info;
                member_info.buffer_offset += offset;
                WalkIntegerFields(type[2 + member], member_info, depth + 1);
            }
        }
    }
    else if (Op(type) == spv::OpTypeArray || Op(type) == spv::OpTypeRuntimeArray)
    {
        if (const uint32_t stride = ArrayStride(type_id))
        {
            info.array_stride = stride;
        }
        WalkIntegerFields(type[2], info, depth + 1);
    }
}

void Module::TraceValue(uint32_t id, const Path& path, uint32_t depth)
{
    if (depth > kMaxDepth || !visited_.insert(id).second)
    {
        return;
    }
    if (IsUvec2(TypeOf(id)))
    {
        uvec2_addresses_ = true;
    }

    const uint32_t* insn = Def(id);
    if (insn == nullptr)
    {
        return;
    }

    switch (Op(insn))
    {
        case spv::OpLoad:
            TracePointer(insn[3], path, depth + 1);
            return;
        case spv::OpCompositeExtract:
        {
            // OpCompositeExtract <type> <result> <composite> <literal-indices...>
            Path inner(insn + 4, insn + Length(insn));
            inner.insert(inner.end(), path.begin(), path.end());
            TraceValue(insn[3], inner, depth + 1);
            return;
        }
        case spv::OpCompositeConstruct:
            if (path.empty())
            {
                // uvec2 built from two uint32: the address starts at component 0
                TraceValue(insn[3], path, depth + 1);
            }
            else if (3 + path[0] < Length(insn))
            {
                TraceValue(insn[3 + path[0]], Path(path.begin() + 1, path.end()), depth + 1);
            }
            return;
        case spv::OpBitcast:
        case spv::OpCopyObject:
        case spv::OpCopyLogical:
            TraceValue(insn[3], path, depth + 1);
            return;
        case spv::OpIAdd:
        case spv::OpISub:
            // base + offset: only an address-sized operand can carry the base
            for (uint32_t i = 3; i <= 4; ++i)
            {
                if (const uint32_t operand_type = TypeOf(insn[i]); IsUint64(operand_type) || IsUvec2(operand_type))
                {
                    TraceValue(insn[i], path, depth + 1);
                }
            }
            return;
        case spv::OpPhi:
            // OpPhi <type> <result> (<value> <parent-block>)...
            for (uint32_t i = 3; i + 1 < Length(insn); i += 2)
            {
                TraceValue(insn[i], path, depth + 1);
            }
            return;
        case spv::OpSelect:
            TraceValue(insn[4], path, depth + 1);
            TraceValue(insn[5], path, depth + 1);
            return;
        case spv::OpFunctionParameter:
            for (const uint32_t argument : CallArguments(id))
            {
                TraceValue(argument, path, depth + 1);
            }
            return;
        default:
            // constants, conversions from 32-bit values and arithmetic do not carry a loaded address
            return;
    }
}

void Module::TracePointer(uint32_t id, const Path& path, uint32_t depth)
{
    // access-chain indices, outermost first, as ids
    Path indices;

    for (uint32_t step = 0; step < kMaxDepth; ++step)
    {
        const uint32_t* insn = Def(id);
        if (insn == nullptr)
        {
            return;
        }

        const uint32_t op = Op(insn);
        if (op == spv::OpAccessChain || op == spv::OpInBoundsAccessChain || op == spv::OpPtrAccessChain)
        {
            // OpPtrAccessChain has an extra element-index before the indices
            const uint32_t first = op == spv::OpPtrAccessChain ? 5 : 4;
            indices.insert(indices.begin(), insn + first, insn + Length(insn));
            id = insn[3];
        }
        else if (op == spv::OpCopyObject)
        {
            id = insn[3];
        }
        else if (op == spv::OpFunctionParameter)
        {
            // a pointer-parameter: continue at every call-site
            for (uint32_t argument : CallArguments(id))
            {
                TracePointer(argument, Literals(indices, path), depth + 1);
            }
            return;
        }
        else if (op == spv::OpVariable && local_variables_.contains(id))
        {
            if (read_mode_)
            {
                return;
            }

            // the access-chain into the local variable becomes a path into the stored value
            const Path stored_path = Literals(indices, path);

            // every store, regardless of its position in the module
            for (const auto& [pointer, object] : stores_)
            {
                if (pointer == id)
                {
                    TraceValue(object, stored_path, depth + 1);
                }
            }
            return;
        }
        else if (op == spv::OpVariable)
        {
            BufferReferenceInfo info;
            uint32_t            block_type_id = 0;
            if (BlockOf(id, info, block_type_id))
            {
                // literal indices from the value-path follow the access-chain ids
                const size_t num_ids = indices.size();
                indices.insert(indices.end(), path.begin(), path.end());
                Resolve(info, block_type_id, indices, num_ids);
            }
            return;
        }
        else
        {
            // e.g. an address stored in buffer-device-memory, it has no descriptor location
            return;
        }
    }
}

void Module::Resolve(BufferReferenceInfo info, uint32_t block_type_id, const Path& indices, size_t num_ids)
{
    uint32_t type_id = block_type_id;
    size_t   i       = 0;

    // the first index into a descriptor-array selects the descriptor
    if (PeelDescriptorArray(type_id) != type_id)
    {
        type_id = PeelDescriptorArray(type_id);
        i       = 1;
    }

    for (; i < indices.size(); ++i)
    {
        const uint32_t* type = Def(type_id);
        if (type == nullptr)
        {
            return;
        }

        if (Op(type) == spv::OpTypeStruct)
        {
            uint32_t member = indices[i];
            if (i < num_ids)
            {
                // struct-members are always selected by a constant
                const uint32_t* constant = Def(indices[i]);
                if (constant == nullptr || Op(constant) != spv::OpConstant)
                {
                    return;
                }
                member = constant[3];
            }

            uint32_t offset = 0;
            if (!MemberOffset(type_id, member, offset) || 2 + member >= Length(type))
            {
                return;
            }
            info.buffer_offset += offset;
            type_id = type[2 + member];
        }
        else if (Op(type) == spv::OpTypeArray || Op(type) == spv::OpTypeRuntimeArray)
        {
            // any element: the first one plus the stride
            if (const uint32_t stride = ArrayStride(type_id))
            {
                info.array_stride = stride;
            }
            type_id = type[2];
        }
        else if (Op(type) == spv::OpTypeVector)
        {
            // a component of the address, the address starts at the vector
            break;
        }
        else
        {
            return;
        }
    }

    if (read_mode_)
    {
        WalkIntegerFields(type_id, info, 0);
        return;
    }

    const uint32_t* type = Def(type_id);
    if (IsUint64(type_id) || IsUvec2(type_id) || IsPsbPointer(type_id) ||
        (type != nullptr && Op(type) == spv::OpTypeInt && type[2] == 32))
    {
        // a uint32 is the low half of a uvec2 built from two loads
        Add(info);
    }
}

uint32_t Module::LocalBase(uint32_t pointer_id) const
{
    for (uint32_t step = 0; step < kMaxDepth; ++step)
    {
        const uint32_t* insn = Def(pointer_id);
        if (insn == nullptr)
        {
            return 0;
        }
        if (Op(insn) != spv::OpAccessChain && Op(insn) != spv::OpInBoundsAccessChain)
        {
            return local_variables_.contains(pointer_id) ? pointer_id : 0;
        }
        pointer_id = insn[3];
    }
    return 0;
}

std::vector<uint32_t> Module::CallArguments(uint32_t parameter_id) const
{
    std::vector<uint32_t> arguments;

    auto parameter = parameters_.find(parameter_id);
    if (parameter != parameters_.end())
    {
        const auto [function_id, index] = parameter->second;

        // OpFunctionCall <type> <result> <function> <arguments...>
        for (const uint32_t position : calls_)
        {
            if (const uint32_t* call = words_ + position; call[3] == function_id && 4 + index < Length(call))
            {
                arguments.push_back(call[4 + index]);
            }
        }
    }
    return arguments;
}

Module::Path Module::Literals(const Path& indices, const Path& path) const
{
    Path literals;
    for (const uint32_t index : indices)
    {
        // a dynamic index selects an array element, which the walk does not distinguish
        const uint32_t* constant = Def(index);
        literals.push_back((constant != nullptr && Op(constant) == spv::OpConstant) ? constant[3] : 0);
    }
    literals.insert(literals.end(), path.begin(), path.end());
    return literals;
}

void Module::BuildUses()
{
    if (uses_built_)
    {
        return;
    }
    uses_built_ = true;

    for (size_t i = first_function_; i < num_words_;)
    {
        const uint32_t* insn   = words_ + i;
        const uint32_t  op     = Op(insn);
        const uint32_t  length = Length(insn);

        // every word that can be an id counts as a use, literals only add harmless edges
        const uint32_t first = OpcodeHasResult(op) ? (OpcodeHasType(op) ? 3 : 2) : 1;
        for (uint32_t k = first; k < length; ++k)
        {
            if (insn[k] < definitions_.size())
            {
                uses_[insn[k]].push_back(static_cast<uint32_t>(i));
            }
        }
        i += length;
    }
}

std::set<Module::Path> Module::EscapingPaths(uint32_t loaded_id)
{
    struct Value
    {
        uint32_t id;
        Path     path;

        // the value now sits inside a new composite, extracts no longer narrow the path
        bool embedded;
    };

    BuildUses();

    std::set<Path>               escaping;
    std::unordered_set<uint32_t> seen;
    std::vector<Value>           work = { { loaded_id, {}, false } };

    while (!work.empty() && seen.size() < kMaxEscapeValues)
    {
        Value value = std::move(work.back());
        work.pop_back();

        auto uses = uses_.find(value.id);
        if (!seen.insert(value.id).second || uses == uses_.end())
        {
            continue;
        }

        for (uint32_t position : uses->second)
        {
            const uint32_t* insn = words_ + position;

            switch (Op(insn))
            {
                case spv::OpStore:
                    if (insn[2] != value.id)
                    {
                        break;
                    }
                    if (const uint32_t local = LocalBase(insn[1]))
                    {
                        // a local copy, follow what is loaded back from it
                        for (const uint32_t load : loads_)
                        {
                            if (LocalBase(words_[load + 3]) == local)
                            {
                                work.push_back({ words_[load + 2], value.path, true });
                            }
                        }
                    }
                    else
                    {
                        escaping.insert(value.path);
                    }
                    break;
                case spv::OpConvertUToPtr:
                case spv::OpFunctionCall:
                case spv::OpReturnValue:
                case spv::OpAtomicStore:
                case spv::OpAtomicExchange:
                case spv::OpAtomicCompareExchange:
                    escaping.insert(value.path);
                    break;
                case spv::OpBitcast:
                    if (IsPsbPointer(insn[1]))
                    {
                        escaping.insert(value.path);
                    }
                    else
                    {
                        work.push_back({ .id = insn[2], .path = value.path, .embedded = value.embedded });
                    }
                    break;
                case spv::OpCompositeExtract:
                    if (insn[3] != value.id)
                    {
                        break;
                    }
                    if (value.embedded)
                    {
                        work.push_back({ .id = insn[2], .path = value.path, .embedded = true });
                    }
                    else
                    {
                        Path path = value.path;
                        path.insert(path.end(), insn + 4, insn + Length(insn));
                        work.push_back({ .id = insn[2], .path = std::move(path), .embedded = false });
                    }
                    break;
                case spv::OpCompositeConstruct:
                case spv::OpCompositeInsert:
                case spv::OpVectorShuffle:
                    work.push_back({ .id = insn[2], .path = value.path, .embedded = true });
                    break;
                case spv::OpIAdd:
                case spv::OpISub:
                case spv::OpCopyObject:
                case spv::OpCopyLogical:
                case spv::OpPhi:
                case spv::OpSelect:
                    work.push_back({ .id = insn[2], .path = value.path, .embedded = value.embedded });
                    break;
                default:
                    // compares, branches and other arithmetic keep the value inside the shader
                    break;
            }
        }
    }
    return escaping;
}

GFXRECON_END_NAMESPACE(spirv_parsing)

bool SpirVParsingUtil::ParseBufferReferences(const uint32_t* const spirv_code, size_t spirv_num_bytes)
{
    buffer_references_.clear();

    if (spirv_code == nullptr)
    {
        return false;
    }

    spirv_parsing::Module module(spirv_code, spirv_num_bytes / sizeof(uint32_t));
    if (!module.Parse())
    {
        return false;
    }
    if (module.skipped())
    {
        return true;
    }
    module.FindBufferReferences(buffer_references_);

    for (const auto& info : buffer_references_)
    {
        GFXRECON_LOG_DEBUG("buffer-reference: source: %u, set: %u, binding: %u, buffer-offset: %u, array-stride: %u",
                           static_cast<uint32_t>(info.source),
                           info.set,
                           info.binding,
                           info.buffer_offset,
                           info.array_stride);
    }
    return true;
}

std::vector<SpirVParsingUtil::BufferReferenceInfo> SpirVParsingUtil::GetBufferReferenceInfos() const
{
    return { buffer_references_.begin(), buffer_references_.end() };
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
