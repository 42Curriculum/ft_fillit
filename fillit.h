/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:46:17 by jjosePhi          #+#    #+#             */
/*   Updated: 2019/10/28 20:28:27 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include "./libft/get_next_line.h"
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

int					err_display();

int					solver(int (*p)[], t_board *b, char *m[], int i);
int					if_next_line(int pos, int i, int s, int m);
int					read_file(int fd, char **p, int (*pa)[], int size);
char				*ft_strfjoin(char **s1, char const *s2);
int					falloc(int flag, char **input, char **line, int *pn);
void				print_n_free(t_board **b);
int					p_count(int *str);
char				*new_board(int size, t_board **b);
int					check_hashes(char *buff);

#endif
