/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chaleur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:16:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:16:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         next_pos_stars(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;

    if (!(piece->pos_stars) || !(piece->final_pos))
        return (-1);
    x = -1;
    while (++x < piece->x_piece)
    {
        y = -1;
        while (++y < piece->y_piece)
            if (piece->pos_stars[x][y] != -1)
                if (piece->x_best_pos - x < map->x_map && piece->y_best_pos - y < map->y_map)
                    if (piece->x_best_pos - x >= 0 && piece->y_best_pos - y >= 0)
                        piece->final_pos[piece->x_best_pos - x][piece->y_best_pos - y] = piece->y_best_pos - y;
    }
    return (1);
}

int         check_chaleur_piece(t_coor *map, t_coor_piece *piece, int x, int y)
{
    int     x_piece;
    int     y_piece;
    int     val;
    int     tmp;

    if (!(map->map_chaleur) || !(piece->pos_stars))
        return (-1);
    x_piece = -1;
    val = map->x_map * map->y_map;
    while (++x_piece < piece->x_piece)
    {
        y_piece = -1;
        while (++y_piece < piece->y_piece)
        {
            if (piece->pos_stars[x_piece][y_piece] != -1)
            {
                if (map->map_chaleur[x + x_piece][y + y_piece] < val)
                   tmp = map->map_chaleur[x + x_piece][y + y_piece];
                if (tmp > 0 && tmp < val)
                   val = tmp;
                if (tmp == 0)
                    val = 0;
            }
        }
    }
    return (val);
}

int         check_pos_final(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;
    int     val;
    int     tmp;

    if (!(map->map_chaleur) || !(piece->final_pos) || !(map->me_list))
        return (-1);
    x = -1;
    val = map->x_map * map->y_map;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            if (piece->final_pos[x][y] != -1)
            {
                tmp = check_chaleur_piece(map, piece, x, y);
                if (tmp < val)
                {
                    val = tmp;
                    piece->x_final_pos = x;
                    piece->y_final_pos = y;
                }
            }
        }
    }
    return (1);
}
