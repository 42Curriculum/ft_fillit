NAME = fillit
FILES = ./srcs/fillit.c ./srcs/solver.c ./srcs/stuff_we_need.c ./srcs/main.c libft/libft.a ./srcs/check_piece.c
FLAGS = -Wall -Wextra -Werror -o
INCL = ./incl/fillit.h

all : $(NAME)

$(NAME) :
	make -C libft/
	gcc $(FLAGS) $(NAME) $(FILES) -I $(INCL) -L. libft/libft.a

clean :
	/bin/rm -f *.o
	make -C libft/ clean

fclean : clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re : fclean all