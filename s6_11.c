/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s6_11.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:41:22 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/24 13:53:23 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int f_6(char *board, int *pos,  int size)//.#\n##\n#.
{
	int i;

	i = 1;
	while (board[*pos + i] && i <= (size * size))
	{
		
		if ((board[*pos + i] >= 'A' && board[*pos + i] <= 'Z'))
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
		else if (i == (*pos + size * 2))
			return (TRUE);
		else 
			i++;
	}
	if (i == (*pos + (size * 2) + 1))
			return (TRUE);
	return (FALSE);
}