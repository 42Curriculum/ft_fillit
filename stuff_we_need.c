/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff_we_need.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:55:17 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/20 20:22:11 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char *new_board(int size)
{
    int i;
    char *str;
    
    i = 1;
    str = ft_strnew(size*size + size);
    while (i <= (size*size + size + 1)) 
    {
        str[i - 1] = '.';
        i++;
        if ((i % (size + 1) == 0 && i > 0))
        {   str[i - 1] = '\n';
            i++;
        }
    }
    str[i - 3] = '\0';
    return (str);
}
