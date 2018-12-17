/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:18:27 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:18:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         init_list_filler(t_coor *map, t_coor_piece *piece, int player)
{
    if (map && piece)
    {
        map->map = NULL;
        piece->piece = NULL;
        map->map_chaleur = NULL;
        map->me_list = NULL;
        map->ennemi_list = NULL;
        map->x_map = -1;
        map->y_map = -1;
        map->me = (player == 1) ? 'O' : 'X';
        map->ennemi = (player == 1) ? 'X' : 'O';
        piece->x_piece = -1;
        piece->y_piece = -1;
        piece->x_best_pos = -1;
        piece->y_best_pos = -1;
        piece->x_final_pos = -1;
        piece->y_final_pos = -1;
        return (1);
    }
    else
        return (0);
}

int         read_player(t_coor *map, t_coor_piece *piece, char *line)
{
    int     i;
    if ((i = get_next_line(0, &line)) > 0)
    {
        if (!(init_list_filler(map, piece, (ft_strstr(line, "p1")) ? 1 : 2)))
        {
            ft_fprintf("Bad player info\n", 2);
            exit(1);
        }
        if (line)
        {
            free(line);
            line = NULL;
        }
    }
    return (i);
}