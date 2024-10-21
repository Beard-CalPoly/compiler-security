BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld

C_SRCS := $(wildcard *.c)

CBINS := $(C_SRCS:%.c=%)
CLLS := $(C_SRCS:%.c=%.c.ll)

all: $(CLLS) $(CBINS)

%: %.c
	$(CLANG) -lm -o $@ $<
	$(CLANG) -lm -no-pie -o $@.nopie $<

%.c.ll: %.c
	$(CLANG) -S  $<
	$(CLANG) -S  -emit-llvm -o $@ $<


.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS)
