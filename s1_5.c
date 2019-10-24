/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:12:08 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/24 13:40:04 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_1(char *board, int *pos,  int size)// #\n#\n#\n#
{
	int i;
	int n;
	
	i = 0;
	n = 0;
	while (board[*pos + i] &&  (i < (size * 4) - (size - *pos)))
	{
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
			n = 0;
		}
		n++;
		i += size;
		if ((i + size > (size * size)) == TRUE)
			return (FALSE);
	}
	if (i == ((size * 4) - (size - *pos)) && i <= (size* size))
		return (TRUE);
	return (FALSE);
}

int f_2(char *board, int *pos,  int size)//##\n##
{
	int i;
	int c;
	
	i = 0;
	while (board[*pos + i] && i < (c = (*pos + size + 1)) && (*pos + size + 1) <= (size*size)) 
	{
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if (i == 1)
			i += size - 1;
		else
			i++;		
	}
	if (i == (*pos + size + 1))
		return (TRUE);
	return (FALSE);
}
int f_3(char *board, int *pos,  int size)//####
{
	int i;
	
	i = 0;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z')|| (i > 0  && (i % size == 0)))
		{
			*pos += 1;
			i = 0;
		}
		i++;
	}
	if (i == 4)
		return (TRUE);
	return (FALSE);
}
int f_4(char *board, int *pos,  int size)//.#\n##\n#.
{
	int i;

	i = 1;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if ((i == 1 || i == (*pos + size + 1)))
		{
			if (i += size - 1 && (board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
			{
				*pos += 1;
				i = 0;
			}
		}
		else if (i == (*pos + size*2))
			return (TRUE);
		else 
			i++;
	}
	if (i == 4)
		return (TRUE);
	return (FALSE);
}
int f_5(char *board, int *pos,  int size)//#.\n##\n.#
{
	int i;

	i = 0;
	while (board[*pos + i])
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
		{
			*pos += 1;
			i = 0;
		}
		if ( i == 0 )
			i += size;
		else if (i == (*pos + size + 1))
			i += (size);
		else if (i == (*pos + (size * 2) + 1))
			return (TRUE);
		else 
			i++;
	}
	return (FALSE);
}