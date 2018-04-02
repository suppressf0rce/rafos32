#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/rafos.kernel isodir/boot/rafos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "rafos" {
	multiboot /boot/rafos.kernel
}
EOF
grub-mkrescue -o rafos.iso isodir
