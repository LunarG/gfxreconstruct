//
// Created by crocdialer on 31.07.24.
//

#ifndef GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H
#define GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H

#include "util/spirv_parsing_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static void vulkan_check_buffer_references(const uint32_t* const spirv_code, uint32_t num_bytes)
{
    // check for buffer-references, issue warning
    gfxrecon::util::SpirVParsingUtil spirv_util;

    if (spirv_util.ParseBufferReferences(spirv_code, num_bytes))
    {
        auto buffer_reference_infos = spirv_util.GetBufferReferenceInfos();

        if (!buffer_reference_infos.empty())
        {
            GFXRECON_LOG_WARNING_ONCE("A Shader is using the 'SPV_KHR_physical_storage_buffer' feature. "
                                      "Resource tracking for buffers accessed via references is currently "
                                      "unsupported, so replay may fail.");
        }
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_CHECK_BUFFER_REFERENCES_H
