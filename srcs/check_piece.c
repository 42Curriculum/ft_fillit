/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:13:50 by asultanb          #+#    #+#             */
/*   Updated: 2019/10/29 15:30:08 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fillit.h"

static void		dfs_checker(int arr[4][4], int row, int col)
{
	arr[row][col] = 2;
	if (row > 1 && arr[row - 1][col] && arr[row - 1][col] != 2)
	{
		arr[row - 1][col] = 2;
		dfs_checker(arr, row - 1, col);
	}
	if (col > 0 && arr[row][col - 1] && arr[row][col - 1] != 2)
	{
		arr[row][col - 1] = 2;
		dfs_checker(arr, row, col - 1);
	}
	if (row < 3 && arr[row + 1][col] && arr[row + 1][col] != 2)
	{
		arr[row + 1][col] = 2;
		dfs_checker(arr, row + 1, col);
	}
	if (col < 3 && arr[row][col + 1] && arr[row][col + 1] != 2)
	{
		arr[row][col + 1] = 2;
		dfs_checker(arr, row, col + 1);
	}
}

static int		graph_check(int arr[4][4], int found_block)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] != 2 && arr[i][j] == 1)
			{
				if (found_block)
					return (0);
				else
				{
					dfs_checker(arr, i, j);
					found_block = 1;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int				check_hashes(char *buff)
{
	int	i;
	int k;
	int	j;
	int	arr[4][4];

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4 && buff[k])
		{
			if (buff[k] == '#')
				arr[i][j++] = 1;
			else if (buff[k] == '.')
				arr[i][j++] = 0;
			k++;
		}
		i++;
	}
	return (graph_check(arr, 0));
}
