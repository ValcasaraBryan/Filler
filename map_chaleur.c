/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chaleur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:15:51 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 19:15:52 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         val_player_fct(t_coor *map, int x, int y)
{
    if (!map->map)
        return (-1);
    if (map->me_list[x][y] == y)
        return (-3);
    else if (map->ennemi_list[x][y] == y)
        return (-2);
    else if (map->ennemi_list[x][y] == -4)
        return (-4);
    else
        return (0);
}

int         map_chaleur_horizontal(t_coor *map)
{
    int     x;
    int     y;

    if (!map->map || !map->x_map)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        if (!(map->map_chaleur[x] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        ft_bzero(map->map_chaleur[x], map->y_map);
        chaleur_left(map, x);
        chaleur_right(map, x);
        while (++y < map->y_map)
            if (map->me_list[x][y] == y || map->ennemi_list[x][y] == y || map->ennemi_list[x][y] == -4)
                map->map_chaleur[x][y] = val_player_fct(map, x, y);
    }
    return (1);
}

int         map_chaleur_vertical(t_coor *map)
{
    int     y;

    if (!map->map_chaleur || !map->y_map || !map->x_map)
        return (0);
    y = -1;
    while (++y < map->y_map)
    {
        chaleur_up(map, y);
        chaleur_down(map, y);
    }
    return (1);
}
