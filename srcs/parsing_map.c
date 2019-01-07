/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:14:40 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 17:41:10 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			read_map(t_coor *map, char **line)
{
	char	**tab;
	int		i;

	i = -1;
	while (++i < map->x_map && get_next_line(0, line))
	{
		tab = ft_strsplit(*line, ' ');
		free_line(line);
		if (tab[1])
			map->map = add_map(map->map, new_map(ft_strdup(tab[1])));
		free_tab_str(tab);
	}
	return (1);
}

int			parsing_map(t_coor *map, char **line)
{
	char	**tab;

	if (!(*line))
		return (0);
	if (ft_strstr(*line, "Plateau"))
	{
		tab = ft_strsplit(*line, ' ');
		free_line(line);
		map->x_map = ft_atoi(tab[1]);
		map->y_map = ft_atoi(tab[2]);
		free_tab_str(tab);
		if (!(map->map_chaleur = (int **)malloc(sizeof(int *) * map->x_map)))
			return (0);
		if (!(map->me_list = (int **)malloc(sizeof(int *) * map->x_map)))
			return (0);
		if (!(map->ennemi_list = (int **)malloc(sizeof(int *) * map->x_map)))
			return (0);
		get_next_line(0, line);
		free_line(line);
		read_map(map, line);
		return (1);
	}
	return (0);
}
