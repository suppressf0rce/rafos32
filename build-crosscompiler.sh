export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

export BIN_UTILS_VER=2.30
export GCC_VER=7.3.0

export

cd $HOME/src

echo Downloading Binutils...
wget https://ftp.gnu.org/gnu/binutils/binutils-$BIN_UTILS_VER.tar.gz
echo Unpacking Binutils...
tar -xzf binutils-$BIN_UTILS_VER.tar.gz

echo Building Bintuils..
mkdir build-binutils
cd build-binutils
../binutils-$BIN_UTILS_VER/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

cd ..

echo Downloading GCC...
wget https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VER/gcc-$GCC_VER.tar.gz
echo Unpacking GCC...
tar -xzf gcc-$GCC_VER.tar.gz

echo Building GCC Crosscompiler...
# The $PREFIX/bin dir _must_ be in the PATH. We did that above.
which -- $TARGET-as || echo $TARGET-as is not in the PATH

mkdir build-gcc
cd build-gcc
../gcc-$GCC_VER/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

cd ..


#Deleting files after we are done Building (Clean the thrash)
echo Cleaning..,
rm binutils-$BIN_UTILS_VER.tar.gz
rm -rf binutils-$BIN_UTILS_VER
rm gcc-$GCC_VER.tar.gz
rm -rf gcc-$GCC_VER
echo Done!
