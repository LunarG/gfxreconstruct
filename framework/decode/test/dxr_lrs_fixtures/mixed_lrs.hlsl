// Fixture: a single unassociated (default) local root signature mixing descriptor tables and root descriptors. The
// descriptor tables map to GPU descriptor handles and the root descriptors to GPU VAs, so the SBT argument tail
// interleaves both resource value kinds. Exercises the descriptor-table path end to end through DXC.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo mixed_lrs.cso mixed_lrs.hlsl

#define MixedLRS_STR "DescriptorTable(SRV(t0)), SRV(t1), DescriptorTable(UAV(u0)), CBV(b0)"
LocalRootSignature MixedLRS = { MixedLRS_STR };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
