/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/22 19:30:40 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *new_board(int size)
{
    int i;
    char *str;
    
    i = 0;
    str = ft_strnew(size*size);
    while (i < size * size) 
    {
        str[i] = '.';
        i++;
    }
    return (str);
}

int p_count(int *str)
{
    int i;

    i = 0;
    while (str[i] != -1)
    {
        i++;
    }
    return (i);
}

void print_board(char *board, int size)
{
    int i ;

    i = 0;
    while (board[i])
    {
        if (i%size == 0)
            ft_putchar('\n');
        ft_putchar(board[i]);
        i++; 
    }
}
