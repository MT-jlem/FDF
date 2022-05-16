NAME = fdf

CC = cc

SRC = fdf.c ft_atoi.c ft_substr.c ft_split.c  get_next_line.c get_next_line_utils.c drawing.c

OBJ = $(SRC:%.c=%.o)


all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

fclean:
	rm fdf *.o