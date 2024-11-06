#!/bin/bash -x

readelf --syms smash_ex.stack-protect.exe | grep FUNC | grep GLOBAL | grep -v _

echo " "


readelf --syms smash_ex.stack-protect.pie.exe | grep FUNC | grep GLOBAL | grep -v _
