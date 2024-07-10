#!/bin/bash

# * Create linker script
echo -e "SECTIONS\n{\t.data 0x41414134 : {KEEP(*(.data))}\n}" > link.ld

# * Compile file (try replacing -fno-pie with -no-pie if the addresses are wrong on your local machine)
gcc -w --std=c99 -g -m32 -fno-pie -fno-stack-protector link.ld q3.c -o q3

# * Run file under no-ASLR wrapper (DISABLED , enable by uncommenting the first line and commenting the second one)
# setarch `uname -m` -R ./q4
./q3 "$1" "$2"

# * Delete files created during script
rm link.ld





