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
    int     i;

    if (!map->map)
        return (0);
    i = map->x_map - 1;
    while (--i >= 0)
        if (map->ennemi_list[i][y] == y)
            if (map->map_chaleur[i + 1][y] >= 0)
                    map->map_chaleur[i + 1][y] = 2;
    return (1);
}

int         chaleur_up(t_coor *map, int y)
{
    int     i;

    if (!map->map)
        return (0);
    i = 0;
    while (++i < map->x_map)
        if (map->ennemi_list[i][y] == y)
            if (map->map_chaleur[i - 1][y] >= 0)
                map->map_chaleur[i - 1][y] = 2;
    return (1);
}

int         chaleur_right(t_coor *map, int x)
{
    int     i;

    if (!map->map)
        return (0);
    i = map->y_map - 1;
    while (i--)
        if (map->ennemi_list[x][i] == i)
            if (map->map_chaleur[x][i + 1] >= 0)
                map->map_chaleur[x][i + 1] = 2;
    return (1);
}

int         chaleur_left(t_coor *map, int x)
{
    int     i;

    if (!map->map)
        return (0);
    i = 0;
    while (++i < map->y_map)
        if (map->ennemi_list[x][i] == i)
            if (map->map_chaleur[x][i - 1] >= 0)
                map->map_chaleur[x][i - 1] = 2;
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
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
            if (map->map_chaleur[x][y] == 0)
                map->map_chaleur[x][y] = val;
    }
    return (1);
}
