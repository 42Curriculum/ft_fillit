/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:29:54 by jjosephi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/10/17 15:13:32 by jjosephi         ###   ########.fr       */
=======
/*   Updated: 2019/10/16 18:15:01 by asultanb         ###   ########.fr       */
>>>>>>> ae02d7a000a973837ccdff9f1022aa03b6fb1b6e
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

<<<<<<< HEAD
void make_board(char *piece, t_board **board, int pos, int size)//This works I think
=======
void make_board(char *piece, t_board **board, int pos)//Works fine
>>>>>>> ae02d7a000a973837ccdff9f1022aa03b6fb1b6e
{
    int i;
    int n;

    i = 0;
    n = 0;
    size +=0;
    while (piece[n])
    {
		if (piece[n] == '\n')
		{
			pos += (*board)->size + 1;
			i = 0;
		}
		else if (piece[n] == '#')
        {
			(*board)->str[pos + i] = '#';
			i++;
        }
		else if (piece[n] == '.')
			i++;
        n++;
    }
}

int findspot(t_piece *piece, char *board, int *pos, int size)//Works ''fin'e, but needs more tests.
{
    int i;
    int n;
    int len;

    len = ft_strlen(piece->value);
    while (board[*pos])
    {
        i = 0;
        n = 0;
       while (piece->value[n] && board[*pos + i])
        {
            if (piece->value[n] == '#' && board[*pos + i] == '0')
				 break ;
            else if (piece->value[n] == '\n')
            {
                i += size;
            }
            else if (n == len - 1)
<<<<<<< HEAD
			{
				ft_putnbr(*pos);
				ft_putchar('\n');
=======
>>>>>>> ae02d7a000a973837ccdff9f1022aa03b6fb1b6e
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
    board_tmp = ft_strdup((board)->value);
    if (findspot(p_list, board_tmp, &pos, board->size) == TRUE)
        make_board(p_list->value, &board, pos, (p_list->size));
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
<<<<<<< HEAD
    board->value = ft_strdup("0...\n0...\n0...\n0...");
=======
    board->str = ft_strdup("0...\n0...\n0...\n0...");
>>>>>>> ae02d7a000a973837ccdff9f1022aa03b6fb1b6e
    piece->size = 4;
    piece->value = ft_strdup(P17);
    piece->prev = NULL;
    printf("%s\n",board->value);
    piece->next = NULL;
    solver(piece, board);
    printf("%s",board->value);
}
