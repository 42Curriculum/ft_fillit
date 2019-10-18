/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/17 15:12:38 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *ft_double_lst_init(int size, int value, char letter)
{
    t_piece *list;

    list->value = value;
    list->letter = letter; 
    list->size = size;
    list->prev = NULL;
    list->prev = NULL;
    return (list);   
}

t_piece *ft_double_list_add(t_piece *prev, int size, char *str)
{
    t_piece *piece;
    
    piece = ft_double_lst_init(size, str);
    if (!(prev))
        piece->prev = NULL;
    else
    {
        piece->prev = prev;
    }
    return (piece);
}