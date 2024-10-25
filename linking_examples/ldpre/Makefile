all: hello

%: %.c
	clang -Wall $< -o $@

%.static: %.c
	clang -static -Wall $< -o $@


.PHONY: clean
clean:
	rm hello hello.static
