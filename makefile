.PHONY:
	make
make:
	gcc --std=c11 -Wall -Wpedantic -Werror -Wno-error=unused-parameter -Wextra -c -o aes.o aes/aes.c
	gcc --std=c11 -Wall -Wpedantic -Werror -Wno-error=unused-parameter -Wextra -c -o main.o main.c
	gcc --std=c11 -Wall -Wpedantic -Werror -Wno-error=unused-parameter -Wextra -o aes_prog main.o aes.o