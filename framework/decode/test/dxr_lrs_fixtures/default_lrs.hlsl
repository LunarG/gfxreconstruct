// Fixture: a single unassociated local root signature, which is the library default. Two SRV root descriptors (GPU
// VAs at shader-binding-table tail offsets 0 and 8) followed by four root constants.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo default_lrs.cso default_lrs.hlsl

#define DefaultLRS_STR "SRV(t0), SRV(t1), RootConstants(num32BitConstants=4, b0)"
LocalRootSignature DefaultLRS = { DefaultLRS_STR };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
