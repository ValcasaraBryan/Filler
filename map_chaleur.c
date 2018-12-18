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
    if (map->me_list[x][y] == y)
        return (-3);
    else if (map->ennemi_list[x][y] == y)
        return (-2);
    else
        return (0);
}

int         map_chaleur_horizontal(t_coor *map)
{
    int     x;
    int     y;

    if (!map->me_list || !map->ennemi_list)
        return (0);
    x = -1;
    while (++x < map->x_map - 1)
    {
        y = -1;
        if (!(map->map_chaleur[x] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        while (++y < map->y_map - 1)
            map->map_chaleur[x][y] = (map->me_list[x][y] == y || map->ennemi_list[x][y] == y) ? val_player_fct(map, x, y) : 0;
        if (!(chaleur_left(map, x)))
            ft_fprintf("error chaleur_left = %d\n", 2);
        if (!(chaleur_right(map, x)))
            ft_fprintf("error chaleur_right = %d\n", 2);
    }
    return (1);
}

int         map_chaleur_vertical(t_coor *map)
{
    int     y;

    if (!map->map_chaleur || !map->y_map || !map->x_map)
        return (0);
    y = -1;
    while (++y < map->y_map - 1)
    {
        if (!(chaleur_up(map, y)))
            ft_fprintf("error chaleur_up = %d\n", 2);
        if (!(chaleur_down(map, y)))
            ft_fprintf("error chaleur_down = %d\n", 2);
    }
    return (1);
}
