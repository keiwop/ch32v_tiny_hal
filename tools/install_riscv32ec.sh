#! /bin/sh

BUILD_DIR   = /_/bld
INSTALL_DIR = /_/opt/riscv32ec  # Add $INSTALL_DIR/bin to your $PATH


mkdir -p $BUILD_DIR
cd $BUILD_DIR
git clone --recursive https://github.com/riscv-collab/riscv-gnu-toolchain

cd riscv-gnu-toolchain
./configure --prefix=$INSTALL_DIR --with-arch=rv32ec --with-abi=ilp32e
make -j15 newlib
