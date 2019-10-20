/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:10 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/20 13:32:00 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_row(char *mpiece, int i)
{
	int	mod_i;

	mod_i = 1;
	while (mpiece[i + mod_i] != '\n' && i + mod_i <= 18)
	{
		if (mpiece[i + mod_i] == '#')
			return (TRUE);
		mod_i++;
	}
	mod_i = 1;
	while (i - mod_i >= 0 && mpiece[i - mod_i] != '\n')
	{
		if ( mpiece[i - mod_i] == '#')
			return (TRUE);
		mod_i++;
	}
	return (FALSE);
}

int check_col(char *mpiece, int i)
{
	int mod_i;
	
	mod_i = i % 5;
	while (mod_i < 18)
	{
		if (mpiece[mod_i] == '#')
			return (TRUE);
		mod_i += 5;
	}
	return (FALSE);
}

int make_piece(char *input, char *m_piece, int i, int n)
{
	while (input[i])
	{
		if (input[i] == '#' && m_piece[n] == '#')
		{
			i++;
			n++;
		}
		else if (input[i] == '.')
		{
			if (check_row(input, i) && check_row(input, i) && m_piece[n] == '.')
				n++;
			i++;
		}
		else if (input[i] == '\n') 
		{
			if (m_piece[n] == '\n')
				n++;
			i++;
		}
		else if (n == (int)ft_strlen(m_piece))
			return (TRUE);
	}
	return (FALSE);
}

int		get_piece(char *input, char **p_array, t_piece *pieces_list, int *size)
{
	int		i;

	i = 0;
	while (i < 19)
	{
		if (make_piece(input, p_array[i], 0, 0))
		{
			*size += ((i < 3) ? 4 : 6);
			ft_double_list_add(pieces_list, (i < 3) ? 4 : 6, i);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int		read_file(int fd, char **p_array, t_piece *pieces_list, int *size)
{
	char *line;
	char *input;
	int ln;
	
	ln = 0;
	input = ft_strnew(0);
	line = ft_strnew(0);
	while (get_next_line(fd, &line))
	{
		input = ft_strjoin(input, ft_strjoin(line, "\n"));
		if (ft_strlen(line) == 0 && ln == 4)
		{
			ln = -1;
			if (!(get_piece(input, p_array, pieces_list, size)))
				return (FALSE);
 			free (input);
			input = ft_strnew(0);
			free (line);
		}
		ln++;
	}
	return (TRUE);
}
