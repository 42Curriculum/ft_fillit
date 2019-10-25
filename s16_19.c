/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s16_19.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:42:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/24 19:00:50 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_16(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 0;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{	
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z') || ((*pos > 0) && *pos % i == 0))
		{
			*pos += 1;
			i = 0;
		}
		if (i == *pos || i == *pos * size + 1)
			i = (*pos + size);
		else 
			i++;
		if (i == (*pos + size * 2))
			return (TRUE);
	}
	if (i == (*pos + size * 2))
		return (TRUE);
	return (FALSE);
}

int f_19(char *board, int *pos,  int size)/* .#\n.#\n## */
{
	int i;

	i = 1;
	if (size == 2)
		return (FALSE);
	while (i <= (size * size) && board[*pos + i])
	{	
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z') || ((*pos > 0) && *pos % i == 0))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 1)
			i += size;
		else if (i == (*pos + size))
			i += size + 1;
		else
			i--;
		if (i == ((*pos + 1)+ size * 2))
			return (TRUE);
	}
	if (i == ((*pos + 1) + size * 2))
		return (TRUE);
	return (FALSE);
}