/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:42:10 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/28 22:44:55 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fillit.h"

static int	check_row(char *mpiece, int i)
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
		if (mpiece[i - mod_i] == '#')
			return (TRUE);
		mod_i++;
	}
	return (FALSE);
}

static int	check_col(char *mpiece, int i)
{
	int mod_i;

	mod_i = i;
	while (mod_i <= 19)
	{
		if (mpiece[mod_i] == '#')
			return (TRUE);
		mod_i += 5;
	}
	mod_i = i;
	while (mod_i >= 0)
	{
		if (mpiece[mod_i] == '#')
			return (TRUE);
		mod_i -= 5;
	}
	return (FALSE);
}

static int	make_piece(char *input, char *m_piece, int i, int n)
{
	while (input[i])
	{
		if (input[i] != '#' && input[i] != '.' && input[i] != '\n')
			return (FALSE);
		if (input[i] == '#' && (i = i + 1) && (m_piece[n++] != '#'))
			return (FALSE);
		else if (input[i] == '.')
		{
			if (check_row(input, i) && check_col(input, i))
			{
				if (m_piece[n] != '.')
					return (FALSE);
				n++;
			}
			i++;
		}
		else if (input[i] == '\n')
		{
			i++;
			if (m_piece[n] == '\n')
				n++;
		}
	}
	return (n == (int)ft_strlen(m_piece)) ? TRUE : FALSE;
}

static int	get_piece(char *input, char **p_array, int (*pieces_arr)[],
						int *size)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < 19)
	{
		if (check_hashes(input) && make_piece(input, p_array[i], 0, 0))
		{
			*size += 4;
			while ((*pieces_arr)[k] >= 0)
				k++;
			(*pieces_arr)[k] = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int			read_file(int fd, char **p_array, int (*pieces_arr)[], int size)
{
	char	*line;
	char	*input;
	int		ln;
	int		pn;

	ln = 1;
	pn = falloc(0, &input, &line, &pn);
	while (get_next_line(fd, &line) && (++ln))
	{
		input = ft_strfjoin(&input, line);
		if (ft_strlen(line) == 0 && ln == 6 && (ln = 1))
		{
			if (!(get_piece(input, p_array, pieces_arr, &size)))
				return (0);
			falloc(1, &input, &line, &pn);
		}
		else if (ft_strlen(line) != 4 && (falloc(2, &input, &line, &pn)))
			return (0);
	}
	if (ft_strlen(input) == 20 && ln == 5 && (falloc(2, &input, &line, &pn)))
		if (!(get_piece(input, p_array, pieces_arr, &size) && (++pn)))
			return (0);
	if (ln != 5)
		return (0);
	return ((pn == 1) ? 2 : size / pn);
}
