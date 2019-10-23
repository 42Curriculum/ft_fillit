/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:46:17 by jjosePhi          #+#    #+#             */
/*   Updated: 2019/10/22 19:11:20 by asultanb         ###   ########.fr       */
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

typedef struct		s_board
{
	int				size;
	char			*value;
}					t_board;

char	*new_board(int size);
int		solver(int (*pieces_arr)[], t_board *board, char *m_pieces[], int i);
int		read_file(int fd, char **p_array, int (*pieces_arr)[]);
int		p_count(int *str);
void	print_board(char *board, int size);

#endif
