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