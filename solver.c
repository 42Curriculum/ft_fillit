/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:29:54 by jjosephi          #+#    #+#             */
/*   Updated: 2019/10/20 18:47:01 by asultanb         ###   ########.fr       */
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
            if (piece[n] == '#' && board[*pos + i] == '0')
				 break ;
            else if (piece[n] == '\n')
            {
                i += size;
            }
            else if (n == len - 1)
			{
				ft_putnbr(*pos);
				ft_putchar('\n');
                return (TRUE);
            }
            else if (piece[n] == '#')
                i++;
            n++;
        }
        *pos += 1;
    }
    return (FALSE);
}

int solver(int (*pieces_arr)[], t_board *board, char *m_pieces[], int i)
{
    char *board_tmp;
    int pos;

    pos = 0;
    board_tmp = (char *)malloc((sizeof(char *)* (board)->size + 1));
    board_tmp = ft_strdup((board)->value);
    if (!(findspot(m_pieces[(*pieces_arr)[i]], board_tmp, &pos, board->size)))
    {
		if (i == 0)
		{
			board->value = new_board(board->size + 1);
			solver(pieces_arr, board, m_pieces, 0);
		}
        else
            solver(pieces_arr, board, m_pieces, i - 1);
    }
    else
    {
        make_board(m_pieces[(*pieces_arr)[i]], &board, pos, i);
        if (i == 25 || (*pieces_arr)[i + 1] == -1)
            return (TRUE);
        else
            if(solver(pieces_arr, board, m_pieces, i + 1))
                return (TRUE);   
    }
    ft_strdel(&board_tmp);
    return (TRUE);
}
