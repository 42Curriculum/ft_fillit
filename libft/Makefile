# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/16 12:29:56 by jjosephi          #+#    #+#              #
#    Updated: 2019/10/28 20:16:05 by jjosephi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror

$(NAME) :
	gcc -c $(FLAGS) *.c libft.h get_next_line.h
	ar rc libft.a *.o

all : $(NAME)

compile :
	gcc $(FLAGS) *.c

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f libft.a

re : fclean $(NAME)
