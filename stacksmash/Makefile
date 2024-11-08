BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld

optlevel := 

CBINS := smash_ex.exe smash_ex.stack-protect.exe smash_ex.stack-protect.pie.exe

all: $(CBINS)

smash_ex.exe: smash_ex.c
	$(CLANG) $(optlevel) -S -emit-llvm $< 
	sed -i -e "s/optnone/ /g" smash_ex.ll
	$(CLANG) -masm=intel -S smash_ex.ll
	$(CLANG) -no-pie smash_ex.ll -o $@

smash_ex.stack-protect.exe: smash_ex.c
	$(CLANG) $(optlevel) -fstack-protector -S -emit-llvm $< -o smash_ex.stack-protect.ll
	$(CLANG) -masm=intel  -S smash_ex.stack-protect.ll
	$(CLANG) -no-pie smash_ex.stack-protect.ll -o $@

smash_ex.stack-protect.pie.exe: smash_ex.c
	$(CLANG) $(optlevel) -fstack-protector -S -emit-llvm $< -o smash_ex.stack-protect.pie.ll
	$(CLANG) -masm=intel  -S smash_ex.stack-protect.pie.ll
	$(CLANG) smash_ex.stack-protect.pie.ll -o $@


.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS) *.exe
