#!/bin/bash -x

CLANG=/home/srbeard/courses/csc429-compilers/llvm-install/bin/clang 

$CLANG -c foo.c
$CLANG -c main.c
$CLANG foo.o main.o -o assembled_ver
$CLANG -no-pie foo.o main.o -o assembled_nopie

objdump -d main.o > main.dump
objdump -d foo.o > foo.dump
objdump -d assembled_ver   > assembled.dump
objdump -d assembled_nopie > assembled_nopie.dump

$CLANG -S foo.c
$CLANG -S main.c
$CLANG foo.s main.s -o compiled_ver
strip compiled_ver -o stripped_ver

$CLANG -S -emit-llvm foo.c
$CLANG -S -emit-llvm main.c
$CLANG foo.ll main.ll -o llvm_ver
