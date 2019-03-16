/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:47:23 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:00:03 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_digit_tables(short **mat, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			ft_putnbr(mat[i][j]);
			if (j < x - 1)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
