/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:10 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/17 21:03:25 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_row(char *mpiece, int i)
{
	int	mod_i;

	mod_i = i % 4;
	if (mod_i != 3 && mpiece[i + 1] == '#')
		return (TRUE);
	if (mod_i != 0 && mpiece[i - 1] == '#')
		return (TRUE);
	return (FALSE);
}

int check_col(char *mpiece, int i)
{
	int mod_i;
	
	mod_i = i % 4;
	while (mod_i < 16)
	{
		if (mpiece[mod_i] == '#')
			return (TRUE);
		mod_i += 4;
	}
	return (FALSE);
}

int make_piece(char *input, char *m_piece, int i, int n)
{
	while (input[i])
	{
		if (input[i] == '\n')
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
			if (check_row(input, i) && check_col(input, i))
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
	int ln;
	int i;
	
	ln = 0;
	line = NULL;
	input = ft_strnew(1);
	line = ft_strnew(1);
	while (get_next_line(fd, &line))
	{
		input = ft_strjoin(input, ft_strjoin(line, "\n"));
		if (ft_strlen(line) == 0 && ln == 4)
		{
			ln = -1;
			i = 0;
			while (i < 19) 
			{
				printf("%i\n", i);
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
	printf("line: \n%s", input);
	return 0;
}

int		main(int argc, char **argv)
{
	int 	fd; //file descriptor
	char	*pieces[19] = {P1, P2, P3, P4 ,P5, P6, P7, P8, P9,
	P10, P11, P12, P13, P14, P15, P16, P17, P18, P19};
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
