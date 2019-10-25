/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s6_10.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:41:22 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/24 15:45:26 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_6(char *board, int *pos,  int size)//.#\n##\n#.
{
	int i;

	i = 0;
	while (board[*pos + i] && i <= (size * size))
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z') ||
		(i == (*pos + size * 2) + 1 && (i % size != 0)))
		{
			*pos += 1;
			i = 0;
		}
		if (i == (*pos + (size * 2) + 1))
			return (TRUE);
		if ((i == 0 || i == (*pos + size)))
		{
			i += size;
		}
		else if (i == (*pos + size * 2) + 1)
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + (size * 2) + 1))
			return (TRUE);
	return (FALSE);
}

int f_7(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 1;
	while (i <= (size * size) && board[*pos + i])
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if ((i == 1 || i == (*pos + size + 1)))
		{
			i += size;
		}
		else if (i == (*pos + size * 2) + 1)
			i--;
		else if (i == (*pos + size * 2))
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + size * 2))
		return (TRUE);
	return (FALSE);
}

int f_8(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
	while ((i <= (size * size) && board[*pos + i]) || (*pos % size == 0))
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 1)
			i += size - 1;
		else if (i == (*pos + size))
			i += size;
		else if (i == (*pos + (size * 2)))
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + (size * 2) && i <= (size *size)))
		return (TRUE);
	return (FALSE);
}

int f_9(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
	while (i <= (size * size) && board[*pos + i])
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z') || (*pos % size == 0))
		{
			*pos += 1;
			i = 0;
		}
		if ((i == 1 || i == (*pos + size + 1)))
		{
			i += size;
		}
		else if (i == (*pos + (size * 2) + 1))
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + (size * 2) + 1))
		return (TRUE);
	return (FALSE);
}

int f_10(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 2;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 2)
		{
			i += size - 2;
		}
		else if (i == (*pos + size + 2))
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + (size + 2)))
		return (TRUE);
	return (FALSE);
}