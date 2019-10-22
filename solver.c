/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:29:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/21 16:26:01 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void make_board(char *piece, t_board **board, int pos, int index)//This works I think
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (piece[n])
    {
		if (piece[n] == '\n')
		{
			pos += (*board)->size + 1;
			i = 0;
		}
		else if (piece[n] == '#')
        {
			(*board)->value[pos + i] = 'A' + index;
			i++;
        }
		else if (piece[n] == '.')
			i++;
        n++;
    }
}

int findspot(char *piece, char *board, int *pos, int size)//Works ''fin'e, but needs more tests.
{
    int i;
    int n;
    int len;

    len = ft_strlen(piece);
    while (board[*pos])
    {
        i = 0;
        n = 0;
       while (piece[n] && board[*pos + i])
        {
            if (piece[n] == '#' && ((board[*pos + i] >= 'A' && 
					(board[*pos + i] <= 'Z')) || (board[*pos + i] == '\n')))
				break ;
            else if (piece[n] == '\n')
                i += size;
            else if (n == len - 1)
                return (TRUE);
            else if (piece[n] == '#')
                i++;
            n++;
        }
        *pos += 1;
    }
    return (FALSE);
}

void clear_board(t_board **board, int index)//This works I think
{
    int i;

    i = 0;
    while ((*board)->value[i])
    {

		if ((*board)->value[i] == 'A' + index)
        {
			(*board)->value[i] = '.';
        }
        i++;
    }
}

int solver(int (*pieces_arr)[], t_board *board, char *m_pieces[], int i)
{
    int pos;

    pos = 0;
    if (!(findspot(m_pieces[(*pieces_arr)[i]], board->value, &pos, board->size)))
    {
        return (FALSE);
    }
    else
    {
        make_board(m_pieces[(*pieces_arr)[i]], &board, pos, i);
        if (i == 25 || (*pieces_arr)[i + 1] == -1)
            return (TRUE);
        else
        {
            while (!(solver(pieces_arr, board, m_pieces, i + 1)))
            {
                pos = 0;
                if(!(findspot(m_pieces[(*pieces_arr)[i]], board->value, &pos, board->size)))
                {
                    return (FALSE);
                }
                else
                {
                    clear_board(&board, i);
                    make_board(m_pieces[(*pieces_arr)[i]], &board, pos, i);
                    if (i == 25 || (*pieces_arr)[i + 1] == -1)
                        return (TRUE);
                }
            }
        }

    }
    return (TRUE);
}
