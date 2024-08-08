#ifndef GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H
#define GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H

#include "decode/referenced_resource_table.h"
#include "generated/generated_vulkan_consumer.h"
#include "util/defines.h"
#include "util/vulkan_modifier_base.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanExampleModifier : public util::VulkanModifierBase
{
  public:
    VulkanExampleModifier(){};

    virtual bool CanOptimize() override { return true; }
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_EXAMPLE_MODIFIER_H
