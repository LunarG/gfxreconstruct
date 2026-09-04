// Fixture: a global root signature alongside an unassociated local root signature. The resolver ignores the global
// root signature; only the local one (one SRV -> one GPU VA) contributes, as the library default.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo global_and_local.cso global_and_local.hlsl

#define LocalLRS_STR "SRV(t0)"
#define GlobalRS_STR "CBV(b0)"
LocalRootSignature  LocalLRS = { LocalLRS_STR };
GlobalRootSignature GlobalRS = { GlobalRS_STR };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
