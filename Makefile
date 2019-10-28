
NAME = fillit
FILES = fillit.c solver.c stuff_we_need.c get_next_line.c main.c libft/libft.a
FLAGS = -Wall -Wextra -Werror

all :
	gcc $(FLAGS) $(FILES) -o $(NAME)

clean :
	/bin/rm -f fillit

fclean : clean
	/bin/rm -f fillit

re : fclean all