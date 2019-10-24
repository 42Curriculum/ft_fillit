/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:12:08 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/23 19:56:17 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_1(char *board, int *pos,  int size)// #\n#\n#\n#
{
	int i;
	int n;
	int c;
	
	i = 0;
	n = 0;
	while (board[*pos + i] &&  (i < (c  = ((size * 4) - (size - *pos)))))
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
	
	i = 0;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z')
		|| (i > 0  && (i % size == 0)))
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
int f_3(char *board, int *pos,  int size)
{
	int i;
	
	i = 0;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z')
		|| (i > 0  && (i % size == 0)))
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
int f_4(char *board, int *pos,  int size)
{
	int i;
	
	i = 0;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z')
		|| (i > 0  && (i % size == 0)))
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
int f_5(char *board, int *pos,  int size)
{
	int i;
	
	i = 0;
	while (board[*pos + i] && i < 4)
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z')
		|| (i > 0  && (i % size == 0)))
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