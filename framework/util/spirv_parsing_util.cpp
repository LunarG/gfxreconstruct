/*
** Copyright (c) 2024 LunarG, Inc.
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
#include <functional>
#include <optional>
#include <deque>
#include "spirv_reflect.h"
#include "util/alignment_utils.h"
#include "util/spirv_helper.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static bool check_type_potential_ref(const SpvReflectTypeDescription* td, bool allow_uvec2)
{
    if (td->storage_class == spv::StorageClassPhysicalStorageBuffer ||
        // uint64_t
        (td->op == SpvOpTypeInt && td->traits.numeric.scalar.width == 64 && !td->traits.numeric.scalar.signedness))
    {
        return true;
    }

    const bool is_uvec2 = td->traits.numeric.vector.component_count == 2 && td->traits.numeric.scalar.width == 32 &&
                          !td->traits.numeric.scalar.signedness;
    return allow_uvec2 && is_uvec2 &&
           (td->op == SpvOpTypeVector || td->op == SpvOpTypeRuntimeArray || td->op == SpvOpTypeArray);
}

// Instruction represents a single Spv::Op instruction.
class SpirVParsingUtil::Instruction
{
  public:
    explicit Instruction(const uint32_t* spirv)
    {
        GFXRECON_ASSERT(spirv != nullptr);

        words_ = spirv;

        const bool has_result = OpcodeHasResult(opcode());
        if (OpcodeHasType(opcode()))
        {
            type_id_index_ = 1;
            operand_index_++;
            if (has_result)
            {
                result_id_index_ = 2;
                operand_index_++;
            }
        }
        else if (has_result)
        {
            result_id_index_ = 1;
            operand_index_++;
        }
    }

    //! the word used to define the Instruction
    [[nodiscard]] uint32_t word(uint32_t index) const { return words_[index]; }

    //! skips pass any optional Result or Result Type word
    [[nodiscard]] uint32_t operand(uint32_t index) const { return words_[operand_index_ + index]; }

    //! number of words used as operands
    [[nodiscard]] uint32_t num_operands() const { return length() - operand_index_; }

    //! length of instruction in words
    [[nodiscard]] uint32_t length() const { return words_[0] >> 16; }

    //! the instruction's op-code
    [[nodiscard]] spv::Op opcode() const { return static_cast<spv::Op>(words_[0] & 0x0ffffu); }

    //! operand id, return 0 if no result
    [[nodiscard]] uint32_t resultId() const { return (result_id_index_ == 0) ? 0 : words_[result_id_index_]; }

    //! operand id, return 0 if no type
    [[nodiscard]] uint32_t typeId() const { return (type_id_index_ == 0) ? 0 : words_[type_id_index_]; }

    //! constant values can safely be returned as uint32_t
    [[nodiscard]] uint32_t constant_value() const
    {
        GFXRECON_ASSERT(opcode() == spv::OpConstant);
        return words_[3];
    }

  private:
    // store minimal extra data
    uint32_t result_id_index_ = 0;
    uint32_t type_id_index_   = 0;
    uint32_t operand_index_   = 1;

    const uint32_t* words_ = nullptr;
};

const SpirVParsingUtil::Instruction* SpirVParsingUtil::FindDef(uint32_t id)
{
    auto it = definitions_.find(id);
    if (it == definitions_.end())
    {
        return nullptr;
    }
    return it->second;
}

const SpirVParsingUtil::Instruction* SpirVParsingUtil::FindVariableStoring(uint32_t variable_id)
{
    for (const Instruction* store_insn : store_instructions_)
    {
        if (store_insn->operand(0) == variable_id)
        {
            // Note: This will find the first store, there could be multiple
            return FindDef(store_insn->operand(1));
        }
    }
    return nullptr;
}

bool SpirVParsingUtil::GetVariableDecorations(const Instruction*   variable_insn,
                                              BufferReferenceInfo& buffer_reference_info)
{
    const uint32_t variable_id   = variable_insn->resultId();
    const uint32_t storage_class = variable_insn->operand(0);

    switch (storage_class)
    {

        case spv::StorageClassUniform:
            buffer_reference_info.source = BufferReferenceLocation::UNIFORM_BUFFER;
            break;

        case spv::StorageClassStorageBuffer:
            buffer_reference_info.source = BufferReferenceLocation::STORAGE_BUFFER;
            break;

        case spv::StorageClassShaderRecordBufferKHR:
            buffer_reference_info.source = BufferReferenceLocation::SHADER_RECORD_BUFFER;
            break;

        case spv::StorageClassPushConstant:
            buffer_reference_info.source = BufferReferenceLocation::PUSH_CONSTANT_BLOCK;
            return true;

        default:
            GFXRECON_LOG_WARNING_ONCE("Storage class %u not handled\n", storage_class);
            return false;
    }

    for (const Instruction* insn : decorations_instructions_)
    {
        if (insn->operand(0) != variable_id)
        {
            continue;
        }
        if (insn->operand(1) == spv::DecorationDescriptorSet)
        {
            buffer_reference_info.set = insn->operand(2);
        }
        else if (insn->operand(1) == spv::DecorationBinding)
        {
            buffer_reference_info.binding = insn->operand(2);
        }
    }
    return true;
}

uint32_t SpirVParsingUtil::ResolveStructTypeId(uint32_t type_id)
{
    // bounded, a member-type is at most a handful of pointer/array indirections away from its struct
    constexpr uint32_t max_indirections = 8;

    for (uint32_t i = 0; i < max_indirections; ++i)
    {
        const Instruction* type_insn = FindDef(type_id);

        if (type_insn == nullptr)
        {
            break;
        }

        switch (type_insn->opcode())
        {
            case spv::OpTypeStruct:
                return type_id;
            case spv::OpTypePointer:
                // OpTypePointer <result-id> <storage-class> <pointee-type>
                type_id = type_insn->operand(1);
                break;
            case spv::OpTypeArray:
            case spv::OpTypeRuntimeArray:
                // OpTypeArray <result-id> <element-type> [<length>]
                type_id = type_insn->operand(0);
                break;
            default:
                return 0;
        }
    }
    return 0;
}

std::optional<uint32_t> SpirVParsingUtil::GetMemberOffset(uint32_t struct_type_id, uint32_t member_index) const
{
    if (const auto struct_it = member_offsets_.find(struct_type_id); struct_it != member_offsets_.end())
    {
        if (const auto member_it = struct_it->second.find(member_index); member_it != struct_it->second.end())
        {
            return member_it->second;
        }
    }
    return std::nullopt;
}

bool SpirVParsingUtil::ParseBufferReferences(const uint32_t* const spirv_code, size_t spirv_num_bytes)
{
    if (spirv_code == nullptr)
    {
        return false;
    }

    definitions_.clear();
    member_offsets_.clear();
    store_instructions_.clear();
    decorations_instructions_.clear();
    buffer_reference_map_.clear();

    // use in combination with spirv-reflect
    std::optional<SpvReflectShaderModule> spv_shader_module;

    // spirv-header is 5 d-words
    constexpr uint32_t spirv_header_size = 5;
    const uint32_t*    spirv_ptr         = spirv_code;
    const uint32_t*    spirv_end         = spirv_code + (spirv_num_bytes / sizeof(uint32_t));

    // skip header
    spirv_ptr += spirv_header_size;

    std::vector<Instruction> instructions;

    bool found_buffer_ref = false;

    // build up instructions object to make it easier to work with the SPIR-V
    // also checks for required capability
    while (spirv_ptr < spirv_end)
    {
        Instruction& insn = instructions.emplace_back(spirv_ptr);
        spirv_ptr += insn.length();
        GFXRECON_ASSERT(insn.length() > 0);

        if (insn.opcode() == spv::OpCapability && insn.word(1) == spv::CapabilityPhysicalStorageBufferAddresses)
        {
            found_buffer_ref = true;
        }

        // arrived at 'OpFunction' -> we have seen all metadata incl. capabilities
        if (insn.opcode() == spv::OpFunction)
        {
            // CapabilityPhysicalStorageBufferAddresses not found
            if (!found_buffer_ref)
            {
                return true;
            }
        }
    }
    if (spirv_ptr != spirv_end)
    {
        GFXRECON_LOG_WARNING("error during SpirV-parsing, mismatching instruction-lengths");
        return false;
    }
    instructions.shrink_to_fit();

    // build the result-id -> instruction lookup once
    for (const Instruction& insn : instructions)
    {
        if (insn.resultId() != 0)
        {
            definitions_[insn.resultId()] = &insn;
        }

        // collect member-offsets, the only authoritative source for a struct's layout
        // OpMemberDecorate <struct-type> <member-index> Offset <byte-offset>
        if (insn.opcode() == spv::OpMemberDecorate && insn.num_operands() >= 4 &&
            insn.operand(2) == spv::DecorationOffset)
        {
            member_offsets_[insn.operand(0)][insn.operand(1)] = insn.operand(3);
        }
    }

    if (spv_shader_module == std::nullopt)
    {
        // spirv-reflect parsing only on-demand
        spv_shader_module = SpvReflectShaderModule();
        spvReflectCreateShaderModule(spirv_num_bytes, spirv_code, &spv_shader_module.value());
    }

    // only consider uvec2 as potential BDAs when the module actually casts uvec2 into a buffer-pointers
    bool allow_uvec2_ref = false;
    {
        auto is_uvec2_value = [this](uint32_t id) {
            const Instruction* value = FindDef(id);
            const Instruction* vec   = value != nullptr ? FindDef(value->typeId()) : nullptr;
            if (vec == nullptr || vec->opcode() != spv::OpTypeVector || vec->operand(1) != 2)
            {
                return false;
            }
            const Instruction* comp = FindDef(vec->operand(0));
            return comp != nullptr && comp->opcode() == spv::OpTypeInt && comp->operand(0) == 32;
        };
        auto is_physical_storage_pointer = [this](uint32_t type_id) {
            const Instruction* type = FindDef(type_id);
            return type != nullptr && type->opcode() == spv::OpTypePointer &&
                   type->operand(0) == spv::StorageClassPhysicalStorageBuffer;
        };
        for (const Instruction& insn : instructions)
        {
            // direct uvec2 -> physical-storage-buffer pointer bitcast
            if (insn.opcode() == spv::OpBitcast && is_physical_storage_pointer(insn.typeId()) &&
                is_uvec2_value(insn.operand(0)))
            {
                allow_uvec2_ref = true;
                break;
            }
            // uvec2 -> uint64 (bitcast) -> pointer (OpConvertUToPtr)
            if (insn.opcode() == spv::OpConvertUToPtr)
            {
                const Instruction* src = FindDef(insn.operand(0));
                if (src != nullptr && src->opcode() == spv::OpBitcast && is_uvec2_value(src->operand(0)))
                {
                    allow_uvec2_ref = true;
                    break;
                }
            }
        }
    }

    // forward spirv-reflect-pass
    constexpr bool use_forward_spirv_reflect_pass = true;

    if constexpr (use_forward_spirv_reflect_pass)
    {
        // define a function to walk blocks breadth-first and check for buffer-references
        auto check_buffer_references = [this, allow_uvec2_ref](const SpvReflectTypeDescription* type,
                                                               BufferReferenceLocation          source,
                                                               uint32_t                         set,
                                                               uint32_t                         binding) {
            struct queue_item_t
            {
                const SpvReflectTypeDescription* type_description = nullptr;
                uint32_t                         offset           = 0;
                uint32_t                         stride           = 0;
                std::vector<std::string>         member_names;
            };
            // iterate bfs
            std::deque<queue_item_t> queue = { { type } };

            while (!queue.empty())
            {
                auto queue_item = std::move(queue.front());
                queue.pop_front();

                if (auto& [td, offset, stride, member_names] = queue_item; td)
                {
                    member_names.emplace_back(td->struct_member_name ? td->struct_member_name : "unknown");

                    // we pick up potential buffer-references here and confirm later.
                    bool is_potential_ref = check_type_potential_ref(td, allow_uvec2_ref);

                    if (td->op == SpvOpTypeArray || td->op == SpvOpTypeRuntimeArray)
                    {
                        stride = td->traits.array.stride;
                    }

                    if (is_potential_ref)
                    {
                        BufferReferenceInfo ref_info;
                        ref_info.source        = source;
                        ref_info.set           = set;
                        ref_info.binding       = binding;
                        ref_info.buffer_offset = offset;
                        ref_info.array_stride  = stride;

                        // insert into map
                        GFXRECON_ASSERT(offset % 8 == 0);
                        buffer_reference_map_[ref_info] = member_names;
                    }

                    // members are located via the module's Offset-decorations, which are correct for
                    // any block-layout (std140, std430, scalar)
                    const uint32_t struct_type_id = ResolveStructTypeId(td->id);

                    for (uint32_t j = 0; j < td->member_count; ++j)
                    {
                        auto member_offset = GetMemberOffset(struct_type_id, j);

                        if (!member_offset.has_value())
                        {
                            GFXRECON_LOG_DEBUG(
                                "No Offset-decoration for member %u of type-id %u, skipping", j, struct_type_id);
                            continue;
                        }
                        queue.push_back({ td->members + j, offset + *member_offset, stride, member_names });
                    }
                }
            }
        };

        // check descriptor sets
        uint32_t num_descriptor_set;
        spvReflectEnumerateDescriptorSets(&*spv_shader_module, &num_descriptor_set, nullptr);
        std::vector<SpvReflectDescriptorSet*> descriptor_sets(num_descriptor_set);
        spvReflectEnumerateDescriptorSets(&*spv_shader_module, &num_descriptor_set, descriptor_sets.data());

        for (const auto& descriptor_set : descriptor_sets)
        {
            for (uint32_t i = 0; i < descriptor_set->binding_count; ++i)
            {
                auto*                   binding = descriptor_set->bindings[i];
                BufferReferenceLocation source  = BufferReferenceLocation::INVALID;

                switch (binding->descriptor_type)
                {
                    case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case SPV_REFLECT_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                        source = BufferReferenceLocation::UNIFORM_BUFFER;
                        break;
                    case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case SPV_REFLECT_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                        source = BufferReferenceLocation::STORAGE_BUFFER;
                        break;
                    default:
                        break;
                }
                check_buffer_references(binding->type_description, source, descriptor_set->set, binding->binding);
            }
        }

        // check push-constants
        uint32_t num_push_constant_blocks;
        spvReflectEnumeratePushConstantBlocks(&*spv_shader_module, &num_push_constant_blocks, nullptr);
        std::vector<SpvReflectBlockVariable*> push_constant_blocks(num_push_constant_blocks);
        spvReflectEnumeratePushConstantBlocks(
            &*spv_shader_module, &num_push_constant_blocks, push_constant_blocks.data());

        for (const auto& block : push_constant_blocks)
        {
            check_buffer_references(block->type_description, BufferReferenceLocation::PUSH_CONSTANT_BLOCK, 0, 0);
        }
    } // forward spirv-reflect pass

    auto track_back_instruction = [this, &spv_shader_module](const Instruction* object_insn,
                                                             uint32_t           initial_array_stride = 0) {
        // keep track of access-chain
        std::vector<uint32_t> access_indices;

        // We are where a buffer-reference was accessed, now walk back to find where it came from
        while (object_insn)
        {
            bool ptr_access_chain = false;

            switch (object_insn->opcode())
            {
                case spv::OpFunctionParameter:
                case spv::OpConvertUToPtr:
                case spv::OpCopyLogical:
                case spv::OpCompositeExtract:
                case spv::OpLoad:
                    object_insn = FindDef(object_insn->operand(0));
                    break;
                case spv::OpPtrAccessChain:
                    ptr_access_chain = true;
                    // fall through
                case spv::OpAccessChain:
                {
                    uint32_t              i = ptr_access_chain ? 2 : 1;
                    std::vector<uint32_t> indices;
                    for (; i < object_insn->num_operands(); ++i)
                    {
                        if (auto ins = FindDef(object_insn->operand(i)))
                        {
                            if (ins->opcode() == spv::OpConstant)
                            {
                                // store access-chain index
                                indices.push_back(ins->constant_value());
                            }
                        }
                    }
                    // insert new indices in front
                    access_indices.insert(access_indices.begin(), indices.begin(), indices.end());

                    // continue with base object
                    object_insn = FindDef(object_insn->operand(0));
                    break;
                }
                case spv::OpVariable:
                {
                    const uint32_t storage_class = object_insn->operand(0);
                    if (storage_class == spv::StorageClassFunction ||
                        storage_class == spv::StorageClassShaderRecordBufferKHR)
                    {
                        // When casting to a struct, can get a 2nd function variable, just keep following
                        object_insn = FindVariableStoring(object_insn->resultId());
                    }
                    else
                    {
                        BufferReferenceInfo buffer_reference_info = {};
                        buffer_reference_info.array_stride        = initial_array_stride;

                        if (GetVariableDecorations(object_insn, buffer_reference_info))
                        {
                            SpvReflectResult                 spv_result;
                            const SpvReflectTypeDescription* td = nullptr;

                            // access-chain starts with descriptor-binding root
                            std::string root_name;

                            if (buffer_reference_info.source == BufferReferenceLocation::PUSH_CONSTANT_BLOCK)
                            {
                                const SpvReflectBlockVariable* block = spvReflectGetEntryPointPushConstantBlock(
                                    &spv_shader_module.value(), spv_shader_module->entry_point_name, &spv_result);
                                GFXRECON_ASSERT(spv_result == SPV_REFLECT_RESULT_SUCCESS);
                                td = block->type_description;
                            }
                            else
                            {
                                const SpvReflectDescriptorBinding* spv_descriptor_binding =
                                    spvReflectGetDescriptorBinding(&spv_shader_module.value(),
                                                                   buffer_reference_info.binding,
                                                                   buffer_reference_info.set,
                                                                   &spv_result);
                                GFXRECON_ASSERT(spv_result == SPV_REFLECT_RESULT_SUCCESS);
                                td = spv_descriptor_binding->type_description;

                                // spirv_reflect sets the name by tracking SPIR-V instructions like OpName. Some
                                // optimizations may remove these instructions, resulting in a nullptr name. Actually we
                                // can find some title removes all such names.
                                root_name = spv_descriptor_binding->name ? spv_descriptor_binding->name : "";
                            }

                            if (root_name.empty())
                            {
                                // e.g. push-constant-block or anonymous uniform-block
                                // store typename instead
                                root_name = td->type_name ? "(" + std::string(td->type_name) + ")" : "";
                            }
                            std::vector<std::string> access_chain_names = { root_name };

                            // follow access-chain
                            for (uint32_t idx : access_indices)
                            {
                                if (idx < td->member_count)
                                {
                                    if (td->op == SpvOpTypeArray || td->op == SpvOpTypeRuntimeArray)
                                    {
                                        // only inherit stride when the array element is itself a PSB pointer.
                                        if (td->storage_class == spv::StorageClassPhysicalStorageBuffer)
                                        {
                                            buffer_reference_info.array_stride = td->traits.array.stride;
                                        }
                                        continue;
                                    }

                                    // member-offset from the module's Offset-decoration
                                    auto member_offset = GetMemberOffset(ResolveStructTypeId(td->id), idx);

                                    if (!member_offset.has_value())
                                    {
                                        GFXRECON_LOG_WARNING(
                                            "No Offset-decoration for member %u of type-id %u (op: %s), "
                                            "cannot determine a buffer-offset",
                                            idx,
                                            td->id,
                                            string_SpvOpcode(td->op));
                                        return;
                                    }
                                    buffer_reference_info.buffer_offset += *member_offset;
                                    td = td->members + idx;

                                    access_chain_names.emplace_back(td->struct_member_name ? td->struct_member_name
                                                                                           : "unknown");
                                }
                                else
                                {
                                    GFXRECON_LOG_WARNING("Access-chain index is out-of-bounds for op: %s",
                                                         string_SpvOpcode(td->op));
                                    return;
                                }
                            }
                            access_indices.clear();

                            if (td->op == SpvOpTypeRuntimeArray)
                            {
                                buffer_reference_info.array_stride = td->traits.array.stride;
                            }

                            // buffer-references traced back to either pointer-type, uin64_t or arrays of those
                            if (td->op == SpvOpTypePointer || td->op == SpvOpTypeForwardPointer ||
                                (td->op == SpvOpTypeInt && td->traits.numeric.scalar.width == 64) ||
                                td->op == SpvOpTypeRuntimeArray)
                            {
                                buffer_reference_map_[buffer_reference_info] = access_chain_names;
                            }
                            else
                            {
                                GFXRECON_LOG_WARNING(
                                    "Traced back a potential buffer-reference, but type does not match: %s",
                                    string_SpvOpcode(td->op));
                            }
                        }
                        object_insn = nullptr;
                    }
                    break;
                }
                default:
                    GFXRECON_LOG_WARNING("Failed to track back the Function Variable OpStore, hit a %s",
                                         string_SpvOpcode(object_insn->opcode()));
                    object_insn = nullptr;
                    break;
            }
        }
    };

    // now we walk the SPIR-V one more time to find remaining occurrences of buffer-references.
    // that's e.g. cases when a uint64_t is casted. we can only tell by following back the dereferencing spv::OpLoad
    for (const Instruction& insn : instructions)
    {
        const uint32_t opcode = insn.opcode();

        if (opcode == spv::OpStore)
        {
            store_instructions_.push_back(&insn);
        }
        else if (opcode == spv::OpDecorate)
        {
            decorations_instructions_.push_back(&insn);
        }

        // There is always a load that does the dereferencing
        if (opcode != spv::OpLoad)
        {
            continue;
        }

        // Confirms the load is used for a buffer device address
        const Instruction* type_pointer_insn = FindDef(insn.typeId());
        if (!type_pointer_insn || type_pointer_insn->opcode() != spv::OpTypePointer ||
            type_pointer_insn->operand(0) != spv::StorageClassPhysicalStorageBuffer)
        {
            continue;
        }

        const Instruction* load_pointer_insn = FindDef(insn.operand(0));

        // Detect pointer-to-pointer (Slang-style arrays of buffer device addresses):
        // when a PhysicalStorageBuffer pointer's pointee is also a PhysicalStorageBuffer pointer,
        // look up ArrayStride decoration to propagate the array stride.
        uint32_t pointer_array_stride = 0;
        {
            const Instruction* pointee_type_insn = FindDef(type_pointer_insn->operand(1));
            if (pointee_type_insn && pointee_type_insn->opcode() == spv::OpTypePointer &&
                pointee_type_insn->operand(0) == spv::StorageClassPhysicalStorageBuffer)
            {
                for (const Instruction* decor : decorations_instructions_)
                {
                    if (decor->operand(0) == type_pointer_insn->resultId() &&
                        decor->operand(1) == spv::DecorationArrayStride)
                    {
                        pointer_array_stride = decor->operand(2);
                        break;
                    }
                }
                if (pointer_array_stride == 0)
                {
                    pointer_array_stride = sizeof(VkDeviceAddress);
                }
            }
        }

        if (load_pointer_insn && load_pointer_insn->opcode() == spv::OpVariable &&
            load_pointer_insn->operand(0) == spv::StorageClassFunction)
        {
            const Instruction* object_insn = FindVariableStoring(load_pointer_insn->resultId());
            if (!object_insn)
            {
                continue;
            }

            track_back_instruction(object_insn, pointer_array_stride);
        }
        else if (load_pointer_insn && (load_pointer_insn->opcode() == spv::OpAccessChain ||
                                       load_pointer_insn->opcode() == spv::OpPtrAccessChain))
        {
            track_back_instruction(load_pointer_insn, pointer_array_stride);
        }
    }

    GFXRECON_LOG_DEBUG("%s: spirv: %d", __func__, spirv_num_bytes);

    for (const auto& [buffer_reference_info, chain_names] : buffer_reference_map_)
    {
        std::string name;
        for (const auto& sn : chain_names)
        {
            name += sn + " -> ";
        }
        name = name.substr(0, name.size() - 4);

        char buf[128];
        if (buffer_reference_info.source == BufferReferenceLocation::PUSH_CONSTANT_BLOCK)
        {
            snprintf(buf, sizeof(buf), "push-constant-block");
        }
        else
        {
            snprintf(
                buf, sizeof(buf), "set: %u, binding: %u", buffer_reference_info.set, buffer_reference_info.binding);
        }

        GFXRECON_LOG_DEBUG("buffer-reference: %s (%s, buffer-offset: %u, array-stride: %u)",
                           name.c_str(),
                           buf,
                           buffer_reference_info.buffer_offset,
                           buffer_reference_info.array_stride);
    }
    // cleanup spirv-module
    if (spv_shader_module != std::nullopt)
    {
        spvReflectDestroyShaderModule(&spv_shader_module.value());
    }

    // successfully parsed
    return true;
}

std::vector<SpirVParsingUtil::BufferReferenceInfo> SpirVParsingUtil::GetBufferReferenceInfos() const
{
    std::vector<BufferReferenceInfo> ret;
    ret.reserve(buffer_reference_map_.size());
    for (const auto& [buffer_ref_info, chain_names] : buffer_reference_map_)
    {
        ret.push_back(buffer_ref_info);
    }
    return ret;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
