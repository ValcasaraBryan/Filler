/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:18:27 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/16 19:35:33 by brvalcas         ###   ########.fr       */
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
	get_next_line(0, NULL);
	perror("Bad player info ");
	return (0);
}

t_file		*new_file(char *line)
{
	t_file	*new;

	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->file = (line && new) ? line : NULL;
	new->next = NULL;
	return (new);
}

t_file		*add_file(t_file *file, char *line)
{
	t_file *head;

	if (!file)
		return (new_file(ft_strdup(line)));
	else
	{
		head = file;
		while (head->next)
			head = head->next;
		head->next = new_file(ft_strdup(line));
		return (file);
	}
}

t_file		*read_fd(t_coor *map, t_coor_piece *piece)
{
	char	*line;
	int		part;
	t_file	*file;

	file = NULL;
	line = NULL;
	part = 0;
	while (get_next_line(0, &line) > 0)
	{
		file = add_file(file, line);
		part = part_init(line, part);
		if (part == 1)
			if (!(parsing_map(map, line)))
				return (free_init_map_piece(map, piece, &file, &line));
		if (part == 2)
			if (!(parsing_piece(piece, line)))
				return (free_init_map_piece(map, piece, &file, &line));
		if (part == 2 && valid_init(map, piece))
			return (norm_pars(file, &line));
		if ((part != 1 && part != 2) || (part == 2 && !map->map))
			return (free_init_map_piece(map, piece, &file, &line));
		free_line(&line);
	}
	return (free_init_val(map, piece, &file, &line));
}
