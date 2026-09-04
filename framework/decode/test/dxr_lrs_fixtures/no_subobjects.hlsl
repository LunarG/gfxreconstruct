// Fixture: a DXIL library with shader exports but no root signature subobjects. The resolver should produce neither a
// default local root signature nor any export associations, and must not crash on a library whose RDAT has no
// subobject table entries of interest.
//
// Compiled to a DXIL library with: dxc -T lib_6_3 -Fo no_subobjects.cso no_subobjects.hlsl

struct Payload
{
    float4 color;
};

[shader("raygeneration")] void RayGen() {}
[shader("miss")] void Miss(inout Payload payload) {}
