/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s11_15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:52:08 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/24 18:37:22 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_11(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 0)
			i += size;
		else if (i > (*pos + size) && i % size == 0)
			return (FALSE);
		else 
			i++;
		if (i == (*pos + (size + 2)))
			return (TRUE);
	}
	if (i == (*pos + (size + 2)))
		return (TRUE);
	return (FALSE);
}

int f_12(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
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
			i += size;
		else if (((i == 1) || (i == 2)) && (i % size == 0))
			return (FALSE);
		else 
			i++;
		if (i == (*pos + (size + 2)))
			return (TRUE);
	}
	if (i == (*pos + (size + 2)))
		return (TRUE);
	return (FALSE);
}

int f_13(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
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
			i = (*pos + size);
		else if (((i == 1) || (i == 2)) && (i % size == 0))
			return (FALSE);
		else 
			i++;
		if (i == (*pos + size))
			return (TRUE);
	}
	if (i == (*pos + size))
		return (TRUE);
	return (FALSE);
}

int f_14(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;
	int n;

	n = 0;
	i = 1;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{	
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 1)
			i = (*pos + size);
		else if (( (i == (*pos + size) || (i == (*pos + size + 1)))) && (((n % size) == 0)))
			return (FALSE);
		else 
			i++;
		if (i == (*pos + size + 2))
			return (TRUE);
		n++;
	}
	if (i == (*pos + size + 2))
		return (TRUE);
	return (FALSE);
}

int f_15(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;
	int n;

	n = 0;
	i = 0;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{	
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 3)
			i = (*pos + size);
		else if (( (i == *pos || (i == (*pos + 1)))) && (((n % size) == 0)))
			return (FALSE);
		else 
			i++;
		if (i == (*pos + size + 1))
			return (TRUE);
		n++;
	}
	if (i == (*pos + size + 1))
		return (TRUE);
	return (FALSE);
}