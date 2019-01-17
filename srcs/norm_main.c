/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:22:50 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/16 18:40:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		norm_main_alloc(t_coor *map, t_coor_piece *piece)
{
	if (!(alloc_first_step(map)))
	{
		perror("Error malloc map\n");
		return (0);
	}
	if (!(first_step(map)))
	{
		erase_all_malloc(map, piece);
		perror("Error map\n");
		return (0);
	}
	if (!(alloc_second_step(map, piece)))
	{
		perror("Error malloc piece\n");
		return (0);
	}
	if (!(second_step(map, piece)))
	{
		erase_all_malloc(map, piece);
		perror("Error piece\n");
		return (0);
	}
	return (1);
}

void	norm_main_while(t_coor *map, t_coor_piece *piece)
{
	while (piece->x_final_pos == -1 && piece->y_final_pos == -1)
	{
		if (!(check_around_pos(map, piece)))
			break ;
		next_pos_stars(map, piece);
		check_around_best_pos(map, piece);
		if (!nb_tab(map, piece->final_pos))
			if (piece->y_best_pos >= 0 && piece->y_best_pos < map->y_map
			&& piece->x_best_pos >= 0 && piece->x_best_pos < map->x_map)
				piece->last_best_pos[piece->x_best_pos]
				[piece->y_best_pos] = piece->y_best_pos;
		check_pos_final(map, piece);
		if (nb_tab(map, map->me_list) > ((map->x_map * map->y_map) * 7) / 10)
			break ;
	}
}

int		put_solve(t_coor *map, t_coor_piece *piece)
{
	erase_all_malloc(map, piece);
	if (piece->x_final_pos >= 0 && piece->y_final_pos >= 0)
		ft_print(piece->x_final_pos, piece->y_final_pos);
	else
		return (ft_print(0, 0));
	piece->y_final_pos = -1;
	piece->x_final_pos = -1;
	return (1);
}
