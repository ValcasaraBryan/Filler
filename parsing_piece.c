/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:14:50 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:14:51 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         parsing_piece(t_coor_piece *piece, char *line)
{
    int i;
    char **tab;

    tab = NULL;
    if (ft_strstr(line, "Piece"))
    {
        i = 0;
        tab = ft_strsplit(line, ' ');
        free(line);
        line = NULL;
        piece->x_piece = ft_atoi(tab[1]);
        piece->y_piece = ft_atoi(tab[2]);
        free_tab_str(tab);
        if (!(piece->pos_stars = (int **)malloc(sizeof (int *) * piece->x_piece)))
            return (-1);
        while (i < piece->x_piece && get_next_line(0, &line))
        {
            piece->piece = add_piece(piece->piece, new_piece(line));
            i++;
        }
        return (1);
    }
    else
        return (0);
}