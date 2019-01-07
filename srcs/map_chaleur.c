/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chaleur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:15:51 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:21:11 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int			val_player_fct(t_coor *map, int x, int y)
{
	if (map->me_list[x][y] == y)
		return (-3);
	else if (map->ennemi_list[x][y] == y)
		return (-2);
	else
		return (0);
}

int			map_chaleur_horizontal(t_coor *map)
{
	int		x;
	int		y;

	if (!map->me_list || !map->ennemi_list || map->y_map < 0 || map->x_map < 0)
		return (0);
	x = -1;
	while (++x < map->x_map)
	{
		y = -1;
		if (!(map->map_chaleur[x] = (int *)malloc(sizeof(int) * map->y_map)))
			return (0);
		while (++y < map->y_map)
			map->map_chaleur[x][y] = (map->me_list[x][y] == y
				|| map->ennemi_list[x][y] == y) ? val_player_fct(map, x, y) : 0;
		if (!(chaleur_left(map, x)))
			return (0);
		if (!(chaleur_right(map, x)))
			return (0);
	}
	return (1);
}

int			map_chaleur_vertical(t_coor *map)
{
	int		y;

	if (!map->map_chaleur || map->y_map < 0 || map->x_map < 0)
		return (-1);
	y = -1;
	while (++y < map->y_map)
	{
		if (!(chaleur_up(map, y)))
			return (0);
		if (!(chaleur_down(map, y)))
			return (0);
	}
	return (1);
}
