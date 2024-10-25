all: nothing io math

math: math.c
	clang -Wall $< -o $@ -lm
	clang -static -Wall $< -o $@.static -lm

%: %.c
	clang -Wall $< -o $@
	clang -static -Wall $< -o $@.static

