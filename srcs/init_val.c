/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:18:27 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:23:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			init_list_filler(t_coor *map, t_coor_piece *piece, int player)
{
	if (map && piece && player > 0)
	{
		map->map = NULL;
		map->map_chaleur = NULL;
		map->me_list = NULL;
		map->ennemi_list = NULL;
		piece->piece = NULL;
		piece->last_best_pos = NULL;
		piece->pos_stars = NULL;
		piece->final_pos = NULL;
		map->x_map = -1;
		map->y_map = -1;
		map->me = (player == 1) ? 'O' : 'X';
		map->ennemi = (player == 1) ? 'X' : 'O';
		piece->x_piece = -1;
		piece->y_piece = -1;
		piece->x_best_pos = -1;
		piece->y_best_pos = -1;
		piece->x_final_pos = -1;
		piece->y_final_pos = -1;
		return (1);
	}
	else
		return (0);
}

int			error(char **line)
{
	free_line(line);
	perror("Bad player info ");
	return (0);
}

int			read_player(t_coor *map, t_coor_piece *piece, char **line)
{
	int		i;
	int		player;

	player = 0;
	if ((i = get_next_line(0, line)) > 0)
	{
		if (!ft_strstr(*line, "$$$ exec p")
			&& !ft_strstr(*line, "brvalcas.filler"))
			return (error(line));
		if (ft_strstr(*line, "p1"))
			player = 1;
		else if (ft_strstr(*line, "p2"))
			player = 2;
		if (!(init_list_filler(map, piece, player)))
			return (error(line));
		free_line(line);
	}
	return (i);
}
