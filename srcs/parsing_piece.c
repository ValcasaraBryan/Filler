/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:14:50 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:12:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int						parsing_piece(t_coor_piece *piece, char *line)
{
	char	**tab;
	int		i;

	if (ft_strstr(line, "Piece"))
	{
		tab = ft_strsplit(line, ' ');
		piece->x_piece = (tab[1]) ? ft_atoi(tab[1]) : 0;
		piece->y_piece = (tab[2]) ? ft_atoi(tab[2]) : 0;
		free_tab_str(&tab);
		if (piece->x_piece <= 0 || piece->y_piece <= 0)
			return (0);
		return (1);
	}
	if (!piece->piece)
		piece->piece = tab_char((size_t)piece->x_piece);
	if (check_char_piece(line) && piece->piece && (int)ft_strlen(line)
		== piece->y_piece && (i = check_tab(piece->piece)) >= 0
		&& i < piece->x_piece)
		piece->piece[i] = ft_strdup(line);
	else
	{
		perror("Error piece ---");
		return (0);
	}
	return (1);
}

int			alloc_first_step(t_coor *map)
{
	if (map->map_chaleur && map->me_list && map->ennemi_list)
		return (-1);
	if (!(map->map_chaleur = (int **)malloc(sizeof(int *) * map->x_map)))
		return (0);
	if (!(map->me_list = (int **)malloc(sizeof(int *) * map->x_map)))
		return (0);
	if (!(map->ennemi_list = (int **)malloc(sizeof(int *) * map->x_map)))
		return (0);
	return (1);
}

int			alloc_second_step(t_coor *map, t_coor_piece *piece)
{
	if (piece->pos_stars && piece->last_best_pos && piece->final_pos)
		return (-1);
	if (!(piece->pos_stars = (int **)malloc(sizeof(int *) * piece->x_piece)))
		return (0);
	if (!(piece->last_best_pos = (int **)malloc(sizeof(int *) * map->x_map)))
		return (0);
	if (!(piece->final_pos = (int **)malloc(sizeof(int *) * map->x_map)))
		return (0);
	return (1);
}
