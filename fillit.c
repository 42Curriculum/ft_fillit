/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:10 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/14 21:19:32 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "fillit.h"

int error_check(char *piece)
{

}


int reader(t_piece **piece_l, int fd)
{
	char *line;
	char *piece;
	t_piece *current;
	int ln;
	
	ln = 0;
	while (get_next_line(fd, line))
	{
		if (ft_strlen(line) == 0 && error_check(line) == FALSE)
		{
			current = ft_double_list_add(&current, ft_strlen(piece), piece);
	}
}

int		main(int argc, char **argv)
{
	int b; //buffer reader
	int fd; //file descriptor
	t_piece *pieces;// pieces list
	
	pieces = ft_double_lst_init(0,"");
	fd = open(argv[1], O_RDONLY);
	//Read file
	if (!(reader(&pieces, fd)))
		return (FALSE);
	//If no error place pieces in list and check size; - F
	//define board size with pieces len => Sqrt(EParea) - F
	//Solve - S
	
} */