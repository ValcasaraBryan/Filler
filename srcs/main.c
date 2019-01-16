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
		t_coor_piece *piece)
{
	free_tab_str(&map->map);
	free_tab_str(&piece->piece);
	free_tab_int(&map->map_chaleur, map->x_map);
	free_tab_int(&map->me_list, map->x_map);
	free_tab_int(&map->ennemi_list, map->x_map);
	free_tab_int(&piece->pos_stars, piece->x_piece);
	free_tab_int(&piece->last_best_pos, map->x_map);
	free_tab_int(&piece->final_pos, map->x_map);
	get_next_line(0, NULL);
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

int					read_player(t_coor *map, t_coor_piece *piece,
					char *argv)
{
	int				player;
	char			*line;

	player = 0;
	if (!argv)
		return (0);
	if (get_next_line(0, &line) > 0)
	{
		if (!ft_strstr(line, "$$$ exec p")
			&& !ft_strstr(argv, "brvalcas.filler"))
			return (error(&line));
		if (ft_strstr(line, "p1"))
			player = 1;
		else if (ft_strstr(line, "p2"))
			player = 2;
		if (!(init_list_filler(map, piece, player)))
			return (error(&line));
	}
	free_line(&line);
	return (1);
}

int					main(int argc, char **argv)
{
	int				etapes;
	t_file			*file;
	t_coor			map;
	t_coor_piece	piece;

	etapes = 0;
	file = NULL;
	(void)argc;
	if (!(read_player(&map, &piece, argv[0])))
		return (0);
	while (1)
	{
		if (!(file = read_fd(&map, &piece)))
			break ;
		else
		{
			if (!(alloc_first_step(&map)))
			{
				perror("Error malloc map\n");
				return (0);
			}
			if (!(first_step(&map)))
			{
				erase_all_malloc(&map, &piece);
				perror("Error map\n");
				return (0);
			}
			if (!(alloc_second_step(&map, &piece)))
			{
				perror("Error malloc piece\n");
				return (0);
			}
			if (!(second_step(&map, &piece)))
			{
				erase_all_malloc(&map, &piece);
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
					if (piece.y_best_pos >= 0 && piece.y_best_pos < map.y_map
					&& piece.x_best_pos >= 0 && piece.x_best_pos < map.x_map)
						piece.last_best_pos[piece.x_best_pos]
						[piece.y_best_pos] = piece.y_best_pos;
				check_pos_final(&map, &piece);
				if (nb_tab(&map, map.me_list) > ((map.x_map / 2)
					* map.y_map) + (map.x_map % 2))
					break ;
			}
			etapes = 0;
			erase_file(file);
			erase_all_malloc(&map, &piece);
			if (piece.x_final_pos >= 0 && piece.y_final_pos >= 0)
				ft_print(piece.x_final_pos, piece.y_final_pos);
			else
				return (ft_print(0, 0));
			piece.y_final_pos = -1;
			piece.x_final_pos = -1;
		}
	}
	erase_file(file);
	return (0);
}
