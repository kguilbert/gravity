#!/bin/bash

source /usr/local/angstrom/arm/environment-setup

pushd ./ThirdParty >& /dev/null
./buildARM.sh || exit 1
popd >& /dev/null

pushd ./src/api/cpp >& /dev/null
make clean || exit 1
make CROSS=arm-angstrom-linux-gnueabi- || exit 1
popd >& /dev/null

pushd ./src/components/cpp/ServiceDirectory >& /dev/null
make clean || exit 1
make CROSS=arm-angstrom-linux-gnueabi- || exit 1
popd >& /dev/null

rm -rf bin lib include
mkdir bin
cp src/components/cpp/ServiceDirectory/ServiceDirectory bin

mkdir lib
cp ThirdParty/lib/* lib
cp src/api/cpp/*.a lib
cp src/api/cpp/*.so lib
cp src/api/java/*.so lib
cp src/api/java/*.jar lib

mkdir include
cp -r src/api/cpp/*.h include
mkdir include/protobuf
cp src/api/cpp/protobuf/GravityDataProductPB.pb.h include/protobuf
cp -r ThirdParty/include/* include

echo building Gravity ARM tarball...
rm gravityARM.tgz
tar czf gravityARM.tgz bin lib include
