/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:19:27 by asultanb          #+#    #+#             */
/*   Updated: 2019/10/20 13:01:31 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int 	fd;
	char	*pieces[19] = {P1, P2, P3, P4 ,P5, P6, P7, P8, P9,
	P10, P11, P12, P13, P14, P15, P16, P17, P18, P19};
	t_board *board;
	t_piece *piece_list;
	int size;
	
	if (!(board = malloc(sizeof(t_board))) || !(piece_list = malloc(sizeof(t_piece))))
			return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(read_file(fd, pieces, piece_list, &size)))
			return (0);
		board->size = size;
		new_board(size);
		if(solver(piece_list, board, pieces))
			ft_putstr(board->value);
	}
	else
		ft_putendl("usage: fillit wrong number of arguments");
	return 0;
}
