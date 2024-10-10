#!/bin/bash

set -e

export MACOSX_DEPLOYMENT_TARGET=11.0

INSTALLDIR="${INSTALLDIR:-"$HOME/deps"}"
NPROCS="${NPROCS:-$(getconf _NPROCESSORS_ONLN)}"
ZSTD=1.5.5
LZ4=1.9.4
ZLIB=1.3.1

mkdir deps-build
cd deps-build

export PKG_CONFIG_PATH="$INSTALLDIR/lib/pkgconfig:$PKG_CONFIG_PATH"
export CFLAGS="-I$INSTALLDIR/include -Os $CFLAGS"
export CXXFLAGS="-I$INSTALLDIR/include -Os $CXXFLAGS"

cat > SHASUMS <<EOF
9c4396cc829cfae319a6e2615202e82aad41372073482fce286fac78646d3ee4  zstd-$ZSTD.tar.gz
0b0e3aa07c8c063ddf40b082bdf7e37a1562bda40a0ff5272957f3e987e0e54b  lz4-$LZ4.tar.gz
9a93b2b7dfdac77ceba5a558a580e74667dd6fede4585b91eefb60f03b72df23  zlib-$ZLIB.tar.gz
EOF

curl -L \
	-O "https://github.com/facebook/zstd/releases/download/v$ZSTD/zstd-$ZSTD.tar.gz" \
	-O "https://github.com/lz4/lz4/releases/download/v$LZ4/lz4-$LZ4.tar.gz" \
	-O "https://www.zlib.net/zlib-$ZLIB.tar.gz" \

shasum -a 256 --check SHASUMS

echo "Installing lz4..."
tar xf "lz4-$LZ4.tar.gz"
cd "lz4-$LZ4"
cmake -B build-dir build/cmake -DCMAKE_OSX_ARCHITECTURES="x86_64;arm64" -DCMAKE_PREFIX_PATH="$INSTALLDIR" -DCMAKE_INSTALL_PREFIX="$INSTALLDIR" -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON -DCMAKE_BUILD_TYPE=MinSizeRel
make -C build-dir "-j$NPROCS"
make -C build-dir install
cd ..

echo "Installing zstd..."
tar xf "zstd-$ZSTD.tar.gz"
cd "zstd-$ZSTD"
cmake -B build-dir build/cmake -DCMAKE_OSX_ARCHITECTURES="x86_64;arm64" -DCMAKE_PREFIX_PATH="$INSTALLDIR" -DCMAKE_INSTALL_PREFIX="$INSTALLDIR" -DZSTD_BUILD_SHARED=OFF -DCMAKE_BUILD_TYPE=MinSizeRel
make -C build-dir "-j$NPROCS"
make -C build-dir install
cd ..

echo "Installing zlib..."
tar xf "zlib-$ZLIB.tar.gz"
cd "zlib-$ZLIB"
cmake -B build-dir build/cmake -DCMAKE_OSX_ARCHITECTURES="x86_64;arm64" -DCMAKE_PREFIX_PATH="$INSTALLDIR" -DCMAKE_INSTALL_PREFIX="$INSTALLDIR" -DZLIB_BUILD_EXAMPLES=OFF -DCMAKE_BUILD_TYPE=MinSizeRel
make -C build-dir "-j$NPROCS"
make -C build-dir install
cd ..

echo "Cleaning up..."
cd ..
rm -r deps-build
