/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_init_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:44:25 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/17 17:16:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_file		*free_init_map_piece(t_coor *map, t_coor_piece *piece,
			t_file **file, char **line)
{
	erase_file(*file);
	free_tab_str(&map->map);
	free_tab_str(&piece->piece);
	free_line(line);
	get_next_line(0, NULL);
	return (NULL);
}

t_file		*free_init_val(t_coor *map, t_coor_piece *piece,
			t_file **file, char **line)
{
	erase_file(*file);
	free_tab_str(&map->map);
	free_tab_str(&piece->piece);
	free_line(line);
	perror("Error file");
	return (NULL);
}

t_file		*norm_pars(t_file *file, char **line)
{
	free_line(line);
	return (file);
}

int			part_init(char *line, int part)
{
	part = (line && ft_strstr(line, "Plateau")) ? 1 : part;
	part = (line && ft_strstr(line, "Piece")) ? 2 : part;
	return (part);
}

int			valid_init(t_coor *map, t_coor_piece *piece)
{
	if (nb_tab_str(map->map) == map->x_map
		&& nb_tab_str(piece->piece) == piece->x_piece)
		return (1);
	else
		return (0);
}
