/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:22:43 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:22:44 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         nb_tab(t_coor *map, int **tab)
{
    int     x;
    int     y;
    int     i;

    x = -1;
    i = 0;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            if (tab[x][y] != -1)
                i++;
        }
    }
    return (i);
}

void        ft_print(int x, int y)
{
    ft_putnbr(x);
    ft_putchar(' ');
    ft_putnbr(y);
    ft_putchar('\n');
}
