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

int			parsing_map(t_coor *map, char *line)
{
	char	**tab;
	int		nb_of_line;

	nb_of_line = 0;
	tab = NULL;
	if (ft_strstr(line, "Plateau"))
	{
		tab = ft_strsplit(line, ' ');
		map->x_map = (tab[1]) ? ft_atoi(tab[1]) : 0;
		map->y_map = (tab[2]) ? ft_atoi(tab[2]) : 0;
		free_tab_str(&tab);
		if (map->x_map <= 0 || map->y_map <= 0)
			return (0);
		return (1);
	}
	tab = ft_strsplit(line, ' ');
	if (tab[0] && !tab[1] && !map->map && (int)ft_strlen(tab[0]) == map->y_map
		&& check_y_map(tab[0], map->y_map))
	{
		free_tab_str(&tab);
		return (1);
	}
	if (!map->map)
		map->map = tab_char((size_t)map->x_map);
	if (tab[0] && tab[1] && (nb_of_line = ft_atoi(tab[0])) >= 0
		&& nb_of_line < map->x_map && !map->map[nb_of_line]
		&& (int)ft_strlen(tab[1]) == map->y_map && check_char(tab[1])
		&& ((nb_of_line > 0 && map->map[nb_of_line - 1]) || nb_of_line == 0))
		map->map[nb_of_line] = ft_strdup(tab[1]);
	else
	{
		free_tab_str(&tab);
		perror("Error map");
		return (0);
	}
	free_tab_str(&tab);
	return (1);
}
