/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/20 12:19:53 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void new_board(int size)
{
    int i;
    char *str;
    
    i = 0;
    str = (char *)malloc(size * size + size);
    while (str[i])
    {
        if (i % 6 == 0)
            str[i] = '\n';
        str[i] = '.';
        i++;
    }
    str[i] = '\0';
}
