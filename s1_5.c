/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s1_5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:12:08 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/23 17:33:07 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_1(char *board, int *pos,  int size)
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

int f_2(char *board, int *pos,  int size)
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