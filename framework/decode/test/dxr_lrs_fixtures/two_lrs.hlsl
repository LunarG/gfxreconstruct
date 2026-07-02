// Fixture: two local root signatures. AssociatedLRS (one SRV -> one GPU VA) is bound explicitly to RayGen; DefaultLRS
// (two SRVs -> two GPU VAs) is left unassociated and so is the library default for the other exports. Exercises the
// explicit-association and implicit-default paths in one library.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo two_lrs.cso two_lrs.hlsl

#define AssociatedLRS_STR "SRV(t0)"
#define DefaultLRS_STR    "SRV(t0), SRV(t1)"
LocalRootSignature            AssociatedLRS = { AssociatedLRS_STR };
LocalRootSignature            DefaultLRS    = { DefaultLRS_STR };
SubobjectToExportsAssociation Assoc         = { "AssociatedLRS", "RayGen" };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
