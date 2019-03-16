/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:52:54 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/13 22:23:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_digit(int *tab, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr(tab[i]);
		if (i + 1 != size)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
