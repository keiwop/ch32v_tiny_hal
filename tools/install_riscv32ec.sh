#! /bin/sh

cd /_/bld/
git clone --recursive https://github.com/riscv-collab/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv32ec --with-arch=rv32ec --with-abi=ilp32e
make -j15 newlib
