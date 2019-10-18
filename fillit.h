/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:46:17 by jjosePhi          #+#    #+#             */
/*   Updated: 2019/10/17 19:24:53 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include <fcntl.h>
# define P1 "#\n#\n#\n#"// 4
# define P2 "##\n##"//////  4
# define P3 "####"//4
# define P4 ".#\n##\n#."//6
# define P5 "#.\n##\n.#"//
# define P6 "#.\n#.\n##"//
# define P7 ".#\n.#\n##"//
# define P8 "##\n#.\n#."//
# define P9 "##\n.#\n.#"//
# define P10 "..#\n###"//
# define P11 "#..\n###"//
# define P12 "###\n..#"//
# define P13 "###\n#.."//
# define P14 ".#.\n###"//
# define P15 "###\n.#."//
# define P16 "#.\n##\n#."
# define P17 "##.\n.##"//6
# define P18 ".##\n##."//
# define P19 ".#\n##\n.#"//6

typedef struct		s_pieces
{
	int				size;//piece area
	int				value;// p1,p2 etc..
	char			letter;// letter to print for output
	struct s_pieces *next;
	struct s_pieces *prev;
}					t_piece;
typedef struct		s_board
{
	int				size;
	char			*value;
}					t_board;
t_piece *ft_double_list_add(t_piece *prev, int size, char *str);
t_piece *ft_double_lst_init(int size, char *piece);

#endif
