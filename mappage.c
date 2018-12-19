/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:10:48 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 19:10:49 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"


int         val_around(t_coor *map, int val, int x, int y)
{
    int     tmp;

    tmp = 0;
    if (y - 1 >= 0)
        val = ((tmp = map->map_chaleur[x][y - 1]) > 0
            && tmp <= val) ? tmp : val;
    if (y + 1 < map->y_map)
        val = ((tmp = map->map_chaleur[x][y + 1]) > 0
            && tmp <= val) ? tmp : val;
    if (x - 1 >= 0)
        val = ((tmp = map->map_chaleur[x - 1][y]) > 0
            && tmp <= val) ? tmp : val;
    if (x + 1 < map->x_map)
        val = ((tmp = map->map_chaleur[x + 1][y]) > 0
            && tmp <= val) ? tmp : val;
    return (val);
}

int         check_position_right_down(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0 || map->map_chaleur[x][y] > 2)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}

int         check_position_left_up(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = map->x_map - 1;
    while (--x >= 0)
    {
        y = map->y_map - 1;
        while (--y >= 0)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0 || map->map_chaleur[x][y] > 2)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}

int         check_position_right_up(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = map->x_map - 1;
    while (--x >= 0)
    {
        y = -1;
        while (++y < map->y_map)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0 || map->map_chaleur[x][y] > 2)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}

int         check_position_left_down(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = map->y_map - 1;
        while (--y >= 0)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0 || map->map_chaleur[x][y] > 2)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}
