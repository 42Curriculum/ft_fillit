/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:10 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/17 19:46:32 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_row_clmn(char *mpiece, int i)
{
	int row;
	int column;
	int mod_i;
	
	mod_i = i % 4;
	row = FALSE;
	column = FALSE;
	// exception if i is 15 && i = 0
	if (mod_i != 3 && mpiece[i + 1] == '#')
		row = TRUE;
	if (mod_i != 0 && mpiece[i - 1] == '#')
		row = TRUE;
	while (mod_i < 16)
	{
		if (mpiece[mod_i] == '#')
		{
			column = TRUE;
			break ;
		}
		mod_i += 4;
	}
	if (column && row)
		return (TRUE);
	else
		return (FALSE);
}

int make_piece(char *input, char *m_piece, int i, int n)
{
	while (input[i])
	{
		if (m_piece[n] == '\n')
			n++;
		if (input[i] == '#')
		{
			if (m_piece[n] == '#')
			{
				i++;
				n++;
			}
			else
				return (FALSE);
		}
		else if (input[i] == '.')
		{
			if (check_row_clmn(input, i))
			{
				if (m_piece[n] == '.')
					n++;
				else
					return (FALSE);
			}
			i++;
		}
	}
	if (n == (int)ft_strlen(m_piece))
		return (TRUE);
	return (FALSE);
}

int reader(int fd, char **p_array)
{
	char *line;
	char *input;
	//t_piece *current;
	int ln;
	int i;
	
	ln = 0;
	input = ft_strnew(0);
	line = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		input = ft_strjoin(input, line);
		//printf("line len: %lu\n", ft_strlen(line));
		// function to print error, free all memory & exit program
		
		if (ft_strlen(line) == 0 && ln == 4)
		{
			ln = -1;
			i = 0;
			while (i < 19) 
			{
				if (make_piece(input, p_array[i], 0, 0))
				{
					printf("YES %i \n%s\n", i, p_array[i]);
					break ;
				}
				i++;
			}
 			free (input);
			free (line);
		}
		ln++;
	}
	return 0;
}

int		main(int argc, char **argv)
{
	//int b; //buffer reader
	int 	fd; //file descriptor
	//t_piece *pieces;// pieces list
	char	*pieces[19] = {P1, P2, P3, P4 ,P5, P6, P7, P8, P9,
	P10, P11, P12, P13, P14, P15, P16, P17, P18, P19};
	//pieces = ft_double_lst_init(0,"");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		//Read file
		if (!(reader(fd, pieces)))
			return (FALSE);
		//If no error place pieces in list and check size; - F
		//define board size with pieces len => Sqrt(EParea) - F
		//Solve - S
	}
	else
		ft_putendl("usage: fillit wrong number of arguments");
	return 0;
}
