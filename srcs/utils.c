/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:22:43 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:09:18 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			erase_list(t_coor *map, t_coor_piece *piece)
{
	int		ret;

	ret = 0;
	ret += erase_map(map);
	ret += erase_piece(piece);
	return (ret);
}

int			nb_tab(t_coor *map, int **tab)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	i = 0;
	if (!tab)
		return (0);
	while (++x < map->x_map)
	{
		y = -1;
		while (++y < map->y_map)
			if (tab[x][y] != -1)
				i++;
	}
	return (i);
}

void		ft_print(int x, int y)
{
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}
