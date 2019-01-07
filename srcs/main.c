/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:25:13 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:32:00 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					erase_all_malloc(t_coor *map,
		t_coor_piece *piece, char **line)
{
	if (!(erase_list(map, piece)))
		return (0);
	if (!(free_tab_int(map->me_list, map->x_map)))
		return (0);
	if (!(free_tab_int(map->ennemi_list, map->x_map)))
		return (0);
	if (!(free_tab_int(piece->pos_stars, piece->x_piece)))
		return (0);
	if (!(free_tab_int(map->map_chaleur, map->x_map)))
		return (0);
	if (!(free_tab_int(piece->last_best_pos, map->x_map)))
		return (0);
	if (!(free_tab_int(piece->final_pos, map->x_map)))
		return (0);
	if (!(free_line(line)))
		return (0);
	return (1);
}

int					first_step(t_coor *map)
{
	if (!(tab_int(map, map->me)))
		return (0);
	if (!(tab_int(map, map->ennemi)))
		return (0);
	if (!(map_chaleur_horizontal(map)))
		return (0);
	if (!(map_chaleur_vertical(map)))
		return (0);
	if (!(check_position_right_down(map)))
		return (0);
	if (!(check_position_left_up(map)))
		return (0);
	if (!(check_position_right_up(map)))
		return (0);
	if (!(check_position_left_down(map)))
		return (0);
	if (!(after_mappage(map)))
		return (0);
	return (1);
}

int					second_step(t_coor *map, t_coor_piece *piece)
{
	if (!(pos_piece(piece)))
		return (0);
	if (!(init_last_best_pos(map, piece)))
		return (0);
	if (!(final_pos_piece(map, piece)))
		return (0);
	return (1);
}

int					main(void)
{
	char			*line;
	int				etapes;
	t_coor			map;
	t_coor_piece	piece;

	etapes = 0;
	if (!(read_player(&map, &piece, &line)))
		return (0);
	while (get_next_line(0, &line))
	{
		etapes += parsing_map(&map, &line);
		etapes += parsing_piece(&piece, &line);
		if (etapes == 1)
		{
			if (!(first_step(&map)))
			{
				erase_all_malloc(&map, &piece, &line);
				perror("Error map\n");
				return (0);
			}
		}
		else if (etapes == 2)
		{
			if (!(second_step(&map, &piece)))
			{
				erase_all_malloc(&map, &piece, &line);
				perror("Error piece\n");
				return (0);
			}
			while (piece.x_final_pos == -1 && piece.y_final_pos == -1)
			{
				if (!(check_around_pos(&map, &piece)))
					break ;
				next_pos_stars(&map, &piece);
				check_around_best_pos(&map, &piece);
				if (!nb_tab(&map, piece.final_pos))
					if (piece.y_best_pos >= 0 && piece.y_best_pos < map.y_map)
						if (piece.x_best_pos >= 0 && piece.x_best_pos < map.x_map)
							piece.last_best_pos[piece.x_best_pos][piece.y_best_pos] = piece.y_best_pos;
				check_pos_final(&map, &piece);
				if (nb_tab(&map, map.me_list) > ((map.x_map / 2) * map.y_map) + (map.x_map % 2))
					break ;
			}
			etapes = 0;
			erase_all_malloc(&map, &piece, &line);
			if (piece.x_final_pos >= 0 && piece.y_final_pos >= 0)
				ft_print(piece.x_final_pos, piece.y_final_pos);
			else
			{
				ft_print(0, 0);
				break ;
			}
			piece.y_final_pos = -1;
			piece.x_final_pos = -1;
		}
		else if (etapes < 0)
		{
			erase_all_malloc(&map, &piece, &line);
			perror("Error malloc\n");
			return (0);
		}
		free_line(&line);
	}
	free_line(&line);
	get_next_line(0, &line);
	return (0);
}
