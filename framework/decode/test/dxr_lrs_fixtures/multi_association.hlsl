// Fixture: one local root signature referenced by two SubobjectToExportsAssociation records, the second listing two
// exports. The spec allows a subobject to be named by multiple association records and a record to list multiple
// exports, so RayGen, Miss, and ClosestHit must all resolve to SharedLRS. Two SRV root descriptors map to GPU VAs at
// tail offsets 0 and 8.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo multi_association.cso multi_association.hlsl

#define SharedLRS_STR "SRV(t0), SRV(t1)"
LocalRootSignature            SharedLRS   = { SharedLRS_STR };
SubobjectToExportsAssociation RayGenAssoc = { "SharedLRS", "RayGen" };
SubobjectToExportsAssociation HitAssoc    = { "SharedLRS", "Miss;ClosestHit" };

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
[shader("closesthit")] void ClosestHit(inout Payload payload, in BuiltInTriangleIntersectionAttributes attribs) {}
