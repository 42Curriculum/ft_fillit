
NAME = fillit
FILES = fillit.c solver.c stuff_we_need.c main.c libft/libft.a check_piece.c
FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) :
	gcc $(FLAGS) $(FILES) -o $(NAME)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f fillit

re : fclean all