/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:20:37 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:22:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			free_tab_int(int **tab, int size)
{
	int		x;

	x = -1;
	if (!tab || size < 0)
		return (0);
	while (++x < size)
		free(tab[x]);
	free(tab);
	return (1);
}

int			free_line(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	else
		return (0);
}

int			free_tab_str(char **str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	else
	{
		while (str[++i])
		{
			free(str[i]);
			str[i] = NULL;
		}
		free(str);
	}
	return (i);
}

int			erase_map(t_coor *map)
{
	t_map	*head_map;

	head_map = NULL;
	if (map->map)
	{
		while (map->map)
		{
			head_map = map->map->next;
			free(map->map->map);
			map->map->map = NULL;
			free(map->map);
			map->map = head_map;
		}
		return (1);
	}
	return (0);
}

int			erase_piece(t_coor_piece *piece)
{
	t_piece	*head_piece;

	head_piece = NULL;
	if (piece->piece)
	{
		while (piece->piece)
		{
			head_piece = piece->piece->next;
			free(piece->piece->piece);
			piece->piece->piece = NULL;
			free(piece->piece);
			piece->piece = head_piece;
		}
		return (1);
	}
	return (0);
}
