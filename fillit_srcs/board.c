/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/11/01 16:31:30 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_board(int size, t_board **b)
{
	int		i;
	char	*str;

	i = 0;
	free((*b)->value);
	str = ft_strnew(size * size);
	while (i < size * size)
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	print_n_free(t_board **b)
{
	int i;

	i = 0;
	while ((*b)->value[i])
	{
		if (i % (*b)->size == 0 && i > 0)
			ft_putchar('\n');
		ft_putchar((*b)->value[i]);
		i++;
	}
	ft_putchar('\n');
	free((*b)->value);
	free(*b);
}

void	clear_board(t_board **board)
{
	int		i;
	char	max_letter;

	i = 0;
	max_letter = '.';
	while ((*board)->value[i])
	{
		if ((*board)->value[i] > max_letter)
			max_letter = (*board)->value[i];
		i++;
	}
	i = 0;
	while ((*board)->value[i])
	{
		if ((*board)->value[i] == max_letter)
			(*board)->value[i] = '.';
		i++;
	}
}
