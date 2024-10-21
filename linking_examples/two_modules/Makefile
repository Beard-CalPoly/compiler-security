BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld

C_SRCS := $(wildcard *.c)

CBINS := $(C_SRCS:%.c=%)
CLLS := $(C_SRCS:%.c=%.c.ll)

all: $(CLLS)

%: %.c
	$(CLANG) -g -o $@ $<

%.c.ll: %.c
	$(CLANG) -S  $<
	$(CLANG) -S  -emit-llvm -o $@ $<

hello:
	$(OPT) -disable-output fun.c.o1.ll -passes=lab0

.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS)
