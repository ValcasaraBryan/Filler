/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:10:36 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:10:39 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         best_position(t_coor *map, int x, int y, int val)
{
    int     tmp;

    if (!(map->map_chaleur))
        return (-1);
    tmp = -1;
    if (y + 1 < map->y_map)
        val = ((tmp = map->map_chaleur[x][y + 1]) >= 0 && val > tmp) ? tmp : val;
    if (y - 1 >= 0)
        val = ((tmp = map->map_chaleur[x][y - 1]) >= 0 && val > tmp) ? tmp : val;
    if (x + 1 < map->x_map)
        val = ((tmp = map->map_chaleur[x + 1][y]) >= 0 && val > tmp) ? tmp : val;
    if (x - 1 >= 0)
        val = ((tmp = map->map_chaleur[x - 1][y]) >= 0 && val > tmp) ? tmp : val;
    return (val);
}

int         check_around_pos(t_coor *map, t_coor_piece *piece)
{
    int     i;
    int     x;
    int     y;
    int     best_pos;

    if (!(map->map_chaleur) || !(piece->pos_stars))
        return (0);
    x = -1;
    best_pos = (map->x_map * map->y_map) + 1;
    i = best_pos;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
            if (map->me_list[x][y] != -1 && piece->last_best_pos[x][y] == -1)
            {
                piece->y_best_pos = ((i = best_position(map, x, y, best_pos))
                    < best_pos) ? y : piece->y_best_pos;
                piece->x_best_pos = ((i = best_position(map, x, y, best_pos))
                    < best_pos) ? x : piece->x_best_pos;
                best_pos = i;
            }
    }
    if (piece->y_best_pos >= 0 && piece->y_best_pos < map->y_map)
        if (piece->x_best_pos >= 0 && piece->x_best_pos < map->x_map)
            if (piece->y_best_pos == piece->last_best_pos[piece->x_best_pos][piece->y_best_pos])
                return (0);
    return (1);
}

int         check_arount_best_pos_piece(t_coor *map, t_coor_piece *piece,
            int x, int y)
{
    int     val_pos;
    int     x_stars;
    int     y_stars;

    val_pos = 0;
    x_stars = -1;
    while (++x_stars < piece->x_piece)
    {
        y_stars = -1;
        while (++y_stars < piece->y_piece)
        {
            if (piece->pos_stars[x_stars][y_stars] != -1)
            {
                if (x_stars + x >= map->x_map || y_stars + y >= map->y_map)
                    piece->final_pos[x][y] = -1;
                else if (map->map_chaleur[x_stars + x][y_stars + y] == -3)
                {
                    val_pos++;
                    if (val_pos > 1)
                        piece->final_pos[x][y] = -1;
                }
                else if (map->map_chaleur[x_stars + x][y_stars + y] == -2)
                    piece->final_pos[x][y] = -1;
            }
        }
    }
    return (1);
}

int         check_around_best_pos(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;

    if (!(piece->final_pos) || !(piece->pos_stars) || !(map->map_chaleur))
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
            if (piece->final_pos[x][y] != -1)
                check_arount_best_pos_piece(map, piece, x, y);
    }
    return (1);
}
