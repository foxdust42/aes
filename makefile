.PHONY:
	make
make:
	gcc --std=c11 -Wall -Wpedantic -Werror -Wno-error=unused-parameter -Wextra -o aes main.c