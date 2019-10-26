/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:46:17 by jjosePhi          #+#    #+#             */
/*   Updated: 2019/10/25 15:44:47 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include <fcntl.h>
# define P1 "#\n#\n#\n#"
# define P2 "##\n##"
# define P3 "####"
# define P4 ".#\n##\n#."
# define P5 "#.\n##\n.#"
# define P6 "#.\n#.\n##"
# define P7 ".#\n.#\n##"
# define P8 "##\n#.\n#."
# define P9 "##\n.#\n.#"
# define P10 "..#\n###"
# define P11 "#..\n###"
# define P12 "###\n..#"
# define P13 "###\n#.."
# define P14 ".#.\n###"
# define P15 "###\n.#."
# define P16 "#.\n##\n#."
# define P17 "##.\n.##"
# define P18 ".##\n##."
# define P19 ".#\n##\n.#"

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
int		err_display();
int 	f_1(char *board, int *pos,  int size);
int 	f_2(char *board, int *pos,  int size);
int 	f_3(char *board, int *pos,  int size);
int 	f_4(char *board, int *pos,  int size);
int 	f_6(char *board, int *pos,  int size);
int 	f_7(char *board, int *pos,  int size);
int 	f_8(char *board, int *pos,  int size);
int 	f_9(char *board, int *pos,  int size);
int 	f_10(char *board, int *pos,  int size);
int 	f_11(char *board, int *pos,  int size);
int 	f_12(char *board, int *pos,  int size);
int 	f_13(char *board, int *pos,  int size);
int 	f_14(char *board, int *pos,  int size);
int 	f_15(char *board, int *pos,  int size);
int 	f_16(char *board, int *pos,  int size);
int 	f_17(char *board, int *pos,  int size);
int 	f_18(char *board, int *pos,  int size);
int 	f_19(char *board, int *pos,  int size);

#endif