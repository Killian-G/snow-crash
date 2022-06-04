#!/bin/sh

#export SNOWCRASH_ISO_PATH=~/sgoinfre/SnowCrash.iso

qemu-system-x86_64  \
    -enable-kvm     \
    -cdrom $SNOWCRASH_ISO_PATH    \
    -net nic,model=rtl8139  \
    -net user,hostfwd=tcp::3042-:4242,hostfwd=tcp::3047-:4747,hostfwd=tcp::3069-:6969