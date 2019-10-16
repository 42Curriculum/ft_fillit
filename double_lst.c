/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:41:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/13 17:00:43 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece *ft_double_lst_init(int size, char *piece)
{
    t_piece *list;

    list->piece = malloc(sizeof(piece)* ft_strlen(piece));
    list->piece = ft_strdup(piece);
    list->size = size;
    list->previous = NULL;
    list->previous = NULL;
    list->head = list;
    return (list);   
}

t_piece *ft_double_list_add(t_piece *prev, int size, char *str)
{
    t_piece *piece;
    
    piece = ft_double_lst_init(size, str);
    if (!(prev))
        piece->previous = NULL;
    else
    {
        piece->previous = prev;
        piece->head = prev->head;
    }
    return (piece);
}