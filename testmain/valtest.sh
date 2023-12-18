#!/bin/bash
make -C .. -s all clean
cp ../writing.a ./
cc testmain.c writing.a -o test.a -g
valgrind ./test.a
rm test.a