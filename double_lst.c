/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/18 19:43:26 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *ft_double_lst_init(int size, int value)
{
    t_piece *list;
    static char letter;

    if (letter > 'A' && letter > 'Z')
        letter = 'A';
    
    list->value = value;
    list->letter = letter; 
    list->size = size;
    list->prev = NULL;
    list->prev = NULL;
    letter++;
    return (list);   
}

t_piece *ft_double_list_add(t_piece *prev, int size, int value)
{
    t_piece *piece;
    
    piece = ft_double_lst_init(size, value);
    if (!(prev))
        piece->prev = NULL;
    else
    {
        piece->prev = prev;
    }
    return (piece);
}