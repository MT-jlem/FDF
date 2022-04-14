all: *.c
	cc -Wall -Wextra -Werror *.c -o fdf

fclean:
	rm fdf