To fully support building gfxreconstruct as ARM64X, you also need to have libraries that are build as both ARM64 and ARM64EC. The compression libraries are build both ways and then "spliced" together. zlib, zstd, and lz4 are all build as both ARM64EC and ARM64, and for both Release and Debug modes. Rename the libraries after building to and combine them with the link command:

(Note, I renamed these after build to make it easier to know which one was which by adding the ARM64 and ARM64EC suffixes).

link.exe /lib /machine:arm64x /out:liblz4_static.lib liblz4_static-ARM64.lib liblz4_static-ARM64EC.lib
link.exe /lib /machine:arm64x /out:liblz4_staticd.lib liblz4_staticd-ARM64.lib liblz4_staticd-ARM64EC.lib

link.exe /lib /machine:arm64x /out:zstdd.lib zstdd_static-ARM64.lib zstdd_static-ARM64EC.lib
link.exe /lib /machine:arm64x /out:zstd.lib zstd_static-ARM64.lib zstd_static-ARM64EC.lib

link.exe /lib /machine:arm64x /out:zlib.lib zs-ARM64.lib zs-ARM64EC.lib
link.exe /lib /machine:arm64x /out:zlibd.lib zsd-ARM64.lib zsd-ARM64EC.lib

Don't forget to update the headers ;-)

Last update: 03/04/2026 - Richard Wright (richard@lunarg.com)

zstd************************
git clone https://github.com/facebook/zstd.git
cd zstd
cmake . -Bbuild-cmake -G "Visual Studio 17 2022" -A ARM64
cd build-cmake
cmake --build . --config Release
cmake --build . --config Debug
Rename static libs zstd(d)_static-ARM64.lib

cmake . -Bbuild-cmake -G "Visual Studio 17 2022" -A ARM64
cd build-cmake
cmake --build . --config Release
cmake --build . --config Debug
Rename static libs zstd(d)_static-ARM64EC.lib

Four files:
zstd_static-ARM64.lib
zstdd_static-ARM64.lib
zstd_static-ARM64EC.lib
zstdd_static-ARM64EC.lib

link.exe /lib /machine:arm64x /out:zstd.lib zstd_static-ARM64.lib zstd_static-ARM64EC.lib
link.exe /lib /machine:arm64x /out:zstdd.lib zstdd_static-ARM64.lib zstddstatic-ARM64EC.lib
No warnings or errors.
Use dumpbin /headers to find ARM64 and ARM64EC in the first four files, and both in the last two files.

lz4**************************
git clone https://github.com/lz4/lz4.git	
There is no cmake support, but there is a Visual Studio 2022 solution
It does not contain ARM64 or ARM64EC configurations. Use the configuration manager to create ARM64 and ARM64EC configs.
You can just build the lz4 subproject and it will create liblz4_static.libs.

You end up with:
liblz4_static-ARM64.lib
liblz4d_static-ARM64.lib
liblz4_static-ARM64EC.lib
liblz4d_static-ARM64EC.lib

link.exe /lib /machine:arm64x /out:liblz4_static.lib liblz4_static-ARM64.lib liblz4_static-ARM64EC.lib
link.exe /lib /machine:arm64x /out:liblz4_staticd.lib liblz4d_static-ARM64.lib liblz4d_static-ARM64EC.lib

Use dumpbin /headers to find ARM64 and ARM64EC in the first four files, and both in the last two files.

zlib ***********************************
zlib.net, download the .zip source and extract.
zlib-1.3.2
We have cmake files again.
zs-ARM64.lib
zsd-ARM64.lib
zs-ARM64EC.lib
zsd-ARM64.lib

link.exe /lib /machine:arm64x /out:zlib.lib zs-ARM64.lib zs-ARM64EC.lib
link.exe /lib /machine:arm64x /out:zlibd.lib zsd-ARM64.lib zsd-ARM64EC.lib

Use dumpbin /headers to find ARM64 and ARM64EC in the first four files, and both in the last two files.











