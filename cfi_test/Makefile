BASEDIR := /home/srbeard/courses/csc429-compilers/llvm-install
BINDIR := $(BASEDIR)/bin

CLANG := $(BINDIR)/clang
OPT := $(BINDIR)/opt
lld := $(BINDIR)/lld


CBINS := cfi_ex.exe 

all: $(CBINS)

cfi_ex.exe: cfi_ex.c
	$(CLANG) -O1 -S -emit-llvm $< 
	$(CLANG) -S $(basename $<).ll
	$(CLANG) -no-pie $(basename $<).ll -o $@

cfi_ex.canary.exe: cfi_ex.c
	$(CLANG) -fstack-protector -O1 -S -emit-llvm $< -o $(basename $@).ll 
	$(CLANG) -S $(basename $@).ll
	$(CLANG) -no-pie $(basename $@).ll -o $@

cfi_ex.protected.exe: cfi_ex.c
	$(CLANG) -O1 -flto -fsanitize=cfi-icall -S -emit-llvm $< -o $(basename $@).ll 
	$(CLANG) -S $(basename $@).ll
	$(CLANG) -fuse-ld=gold -O1 -flto -fsanitize=cfi-icall -no-pie $< -o $@
	#$(CLANG) -O1 -flto -fsanitize-cfi-canonical-jump-tables -no-pie $< -o $@





.PHONY: clean
clean:
	rm -rf *.o *.ll *.s $(CBINS) *.exe
