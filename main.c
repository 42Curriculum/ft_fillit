/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:19:27 by asultanb          #+#    #+#             */
/*   Updated: 2019/10/22 19:28:46 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
		
int		main(int argc, char **argv)
{
	t_board	*board;
	int		fd;
	int		pieces_arr[26];
	int 	size;
	char	*pieces[19] = {P1, P2, P3, P4 ,P5, P6, P7, P8, P9, P10, P11, 
		P12, P13, P14, P15, P16, P17, P18, P19};

	ft_memset(pieces_arr, -1, 26);
	if (!(board = malloc(sizeof(t_board))))
		return (0);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(size = read_file(fd, pieces, &pieces_arr)))
			return (1);
		board->size = 2; //ft_sqrt(size);
		board->value = new_board(board->size);
		printf("board:\n%s\n", board->value);
		while (solver(&pieces_arr, board, pieces, 0) == FALSE)
		{
			free(board->value);
			board->value = new_board(++board->size);
			printf("new board:\n%s\n", board->value);
		}
		print_board(board->value);
	}
	else
		ft_putendl("usage: fillit wrong number of arguments");
	return (0);
}
