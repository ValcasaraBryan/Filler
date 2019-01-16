/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:19:24 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:30:09 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			tab_int(t_coor *map, char char_of_player)
{
	int		**tab;
	int		i;
	int		j;

	if (!map->map || !map->me_list || !map->ennemi_list)
		return (0);
	tab = (char_of_player == map->me) ? map->me_list : map->ennemi_list;
	j = 0;
	while (map->map[j])
	{
		if (!(tab[j] = (int *)malloc(sizeof(int) * map->y_map)))
			return (0);
		i = -1;
		while (map->map[j][++i])
			tab[j][i] = (map->map[j][i] == char_of_player) ? i : -1;
		j++;
	}
	return (1);
}

int			init_last_best_pos(t_coor *map, t_coor_piece *piece)
{
	int		x;
	int		y;

	if (!(map->map_chaleur) || !(piece->pos_stars))
		return (0);
	x = -1;
	while (++x < map->x_map)
	{
		y = -1;
		if (!(piece->last_best_pos[x] =
			(int *)malloc(sizeof(int) * map->y_map)))
			return (0);
		while (++y < map->y_map)
			piece->last_best_pos[x][y] = -1;
	}
	return (1);
}

int			final_pos_piece(t_coor *map, t_coor_piece *piece)
{
	int		x;
	int		y;

	x = -1;
	while (++x < map->x_map)
	{
		y = -1;
		if (!(piece->final_pos[x] = (int *)malloc(sizeof(int) * map->y_map)))
			return (0);
		while (++y < map->y_map)
			piece->final_pos[x][y] = -1;
	}
	return (1);
}

int			pos_piece(t_coor_piece *piece)
{
	int		y;
	int		x;

	if (!piece->piece)
		return (0);
	x = 0;
	while (piece->piece[x])
	{
		y = -1;
		if (!(piece->pos_stars[x] =
				(int *)malloc(sizeof(int) * piece->y_piece)))
			return (0);
		while (piece->piece[x][++y])
			piece->pos_stars[x][y] = (piece->piece[x][y] == '*') ? y : -1;
		x++;
	}
	return (1);
}
