/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_mappage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:13:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 19:13:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         chaleur_down(t_coor *map, int y)
{
    int     x;

    if (!map->map || !map->ennemi_list || !map->map_chaleur)
        return (0);
    x = map->x_map - 1;
    while (--x >= 0)
        if (map->ennemi_list[x][y] == y)
            if (map->map_chaleur[x + 1][y] >= 0)
                    map->map_chaleur[x + 1][y] = 2;
    return (1);
}

int         chaleur_up(t_coor *map, int y)
{
    int     x;

    if (!map->map || !map->ennemi_list || !map->map_chaleur)
        return (0);
    x = 0;
    while (++x < map->x_map - 1)
        if (map->ennemi_list[x][y] == y)
            if (map->map_chaleur[x - 1][y] >= 0)
                map->map_chaleur[x - 1][y] = 2;
    return (1);
}

int         chaleur_right(t_coor *map, int x)
{
    int     y;

    if (!map->map || !map->ennemi_list || !map->map_chaleur)
        return (0);
    y = map->y_map - 1;
    while (y--)
        if (map->ennemi_list[x][y] == y)
            if (map->map_chaleur[x][y + 1] >= 0)
                map->map_chaleur[x][y + 1] = 2;
    return (1);
}

int         chaleur_left(t_coor *map, int x)
{
    int     y;

    if (!map->map || !map->ennemi_list || !map->map_chaleur)
        return (0);
    y = 0;
    while (++y < map->y_map - 1)
        if (map->ennemi_list[x][y] == y)
            if (map->map_chaleur[x][y - 1] >= 0)
                map->map_chaleur[x][y - 1] = 2;
    return (1);
}

int         after_mappage(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    val = map->x_map + map->y_map + 1;
    x = -1;
    while (++x < map->x_map - 1)
    {
        y = -1;
        while (++y < map->y_map - 1)
            if (map->map_chaleur[x][y] == 0)
                map->map_chaleur[x][y] = val;
    }
    return (1);
}
