// Fixture: a local root signature associated explicitly with one export (RayGen) via SubobjectToExportsAssociation.
// Exercises the explicit per-export association path. Two SRV root descriptors map to GPU VAs at tail offsets 0 and 8.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo associated_lrs.cso associated_lrs.hlsl

#define MyLRS_STR "SRV(t0), SRV(t1)"
LocalRootSignature            MyLRS   = { MyLRS_STR };
SubobjectToExportsAssociation MyAssoc = { "MyLRS", "RayGen" };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
