NAME = fdf

CC = cc

SRC = fdf.c ft_atoi.c ft_substr.c ft_split.c  get_next_line.c get_next_line_utils.c \
	draw.c map.c hook.c utils.c draw2.c utils2.c

OBJ = $(SRC:%.c=%.o)


all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

bonus: $(NAME)

clean:
	-rm *.o

fclean:
	-rm fdf *.o

re: fclean all
	