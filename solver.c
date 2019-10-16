/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:29:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/15 20:00:07 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void make_board(char *piece, t_board **board, int pos)//This works I think
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (piece[n])
    {
        if (piece[n] == '\n')
            {
                i++;
                n++;
            }
        if ((*board)->str[pos + i] == '#' || (*board)->str[pos + i] == '\n')
            i++;
            //i += (pos + i) % 4;
            //i += (*board)->size;
        else if (piece[n] == '#')
        {
            (*board)->str[pos + i] = '#';
            i++;
        }
        n++;
    }
}

int findspot(t_piece *piece, char *board, int *pos, int size)//This works but only sometimes
{
    int i;
    int n;
    int len;

    len = ft_strlen(piece->value);
    while (board[*pos])
    {
        i = 0;
        n = 0;
        if (board[*pos] == '\n')
            *pos +=1;
       while (piece->value[n] && board[*pos + i])
        {
            if (piece->value[n] == '#' && board[*pos + i] == '#')
                break ;
            else if (piece->value[n] == '\n')
                i += size;
            else if (n == len - 1)
                return (TRUE);
            else if (piece->value[n] == '#')
                i++;
            n++;
        }
        *pos += 1;
    }
    return (FALSE);
}

int solver(t_piece *p_list, t_board *board)
{
    char *board_tmp;
    int pos;

    pos = 0;
    board_tmp = (char *)malloc((sizeof(char *)* (board)->size + 1));
    board_tmp = ft_strdup((board)->str);
    if (findspot(p_list, board_tmp, &pos, board->size) == TRUE)
        make_board(p_list->value, &board, pos);
/*     else if (findspot(p_list, board_tmp, &pos, board->size) == FALSE &&  !(p_list->next))
        return (FALSE); */
 /*    while (p_list->next && (solver(p_list->next, board) == FALSE))// not work when last
    {
        if (findspot(p_list, board_tmp, &pos, (board)->size) == TRUE)
            make_board(p_list->piece, &board, pos);
        else 
        { 
            ft_strdel(&board_tmp);
            return (FALSE);
        }
    }
    ft_strdel(&board_tmp); */
    return (TRUE);
}

int main()
{
    t_board *board;
    t_piece *piece;

    board = (t_board *)malloc(sizeof(t_board));
    piece = (t_piece *)malloc(sizeof(t_piece));
    board->size = 4;
    board->str = ft_strdup("#...\n#...\n#...\n#...");
    piece->size = 4;
    piece->value = ft_strdup(P12);
    piece->previous = NULL;
    piece->next = NULL;
    solver(piece, board);
    printf("%s",board->str);
}