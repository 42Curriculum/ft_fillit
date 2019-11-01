/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:19:27 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/01 16:34:51 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				err_display(void)
{
	write(1, "error\n", 6);
	exit(1);
}

static t_board	*var_init(char *pieces[])
{
	t_board *board;

	pieces[0] = P1;
	pieces[1] = P2;
	pieces[2] = P3;
	pieces[3] = P4;
	pieces[4] = P5;
	pieces[5] = P6;
	pieces[6] = P7;
	pieces[7] = P8;
	pieces[8] = P9;
	pieces[9] = P10;
	pieces[10] = P11;
	pieces[11] = P12;
	pieces[12] = P13;
	pieces[13] = P14;
	pieces[14] = P15;
	pieces[15] = P16;
	pieces[16] = P17;
	pieces[17] = P18;
	pieces[18] = P19;
	board = ft_memalloc(sizeof(t_board));
	return (board);
}

int				main(int argc, char **argv)
{
	t_board	*board;
	int		fd;
	int		pieces_arr[26];
	int		size;
	char	*pieces[19];

	ft_memset(pieces_arr, -1, 4 * 26);
	board = var_init(pieces);
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY | O_DIRECTORY)) >= 0 && close(fd))
			return (err_display());
		if ((fd = open(argv[1], O_RDONLY)) <= 0)
			return (err_display());
		if (!(size = read_file(fd, pieces, &pieces_arr, 0)))
			return (err_display() && close(fd));
		board->size = size - 1;
		board->value = new_board(board->size, &board);
		while (solver(&pieces_arr, board, pieces, 0) == FALSE)
			board->value = new_board(++board->size, &board);
		print_n_free(&board);
	}
	else
		ft_putendl("usage: fillit input_file");
	return (0);
}
