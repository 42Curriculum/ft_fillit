NAME 		:=	fillit

F_N			:=	fillit solver main stuff_we_need check_piece
FILES		:=	$(addprefix srcs/, $(addsuffix .c, $(F_N)))
OBJS		:=	$(addprefix objects/, $(addsuffix .o, $(F_N)))	

FLAGS		:= -Wall -Wextra -Werror
INCL		:= -I incl/ -I libft/

LIB 		:= libft
LIB_LINK	:= -L $(LIB) -l ft

.PHONY: all clean fclean re

all : $(NAME)

objects/%.o: srcs/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -c $(INCL) $< -o $@

$(NAME) : $(OBJS)
	@make -C $(LIB)
	@gcc $(LIB_LINK) $(OBJS) -o $(NAME)

clean :
	@/bin/rm -rf objects
	@make -C libft clean

fclean : clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re : fclean all
