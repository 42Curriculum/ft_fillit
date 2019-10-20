/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/20 12:51:28 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *new_board(int size)
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
    return (str);
}