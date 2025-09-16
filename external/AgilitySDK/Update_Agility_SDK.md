# Current Agility SDK Version 
- Version: `1.616.1` https://www.nuget.org/packages/Microsoft.Direct3D.D3D12/1.616.1

# Download Agility SDK
- Find the target version in this webiste https://devblogs.microsoft.com/directx/directx12agility/.
- The download button `Download package` is in the right side.

# Install Agility SDK
- Extract `microsoft.direct3d.d3d12.x.xxx.x.nupkg`. `7-Zip` could do it.
- Copy `microsoft.direct3d.d3d12.x.xxx.x\build\native` folder to `gfxreconstruct\external\AgilitySDK`.
- Modify `D3D12SDKVersion` in `tools\optimize\main.cpp` and `tools\replay\desktop_main.cpp`. Also `D3D12SDKPath` if needed.

# Generate code
- Run python `gfxreconstruct\framework\generated\generate_dx12.py`

# Fix compiler errors
- It could have new objects, new functions and new types. It needs to add new ApiCallId enums, new ObjectInfo structs and encode and decode.
- The code generartion mightn't be able to process correctly for some features. They need custom code, like union and more.
- It could have new code formats or data types in headers. The code generation needs to be modified to prase them correctly.
- Some new features could be big changes for custom code that not be able to implement immediately. Please add issues about it.
