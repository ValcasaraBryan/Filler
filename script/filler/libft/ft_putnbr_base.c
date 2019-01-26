/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 03:25:44 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 14:19:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (base[i])
	{
		while (base[++j])
			if (base[i] == base[j] && i != j)
				return (0);
		j = -1;
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void			ft_putnbr_base(int nbr, char *base)
{
	int nbr_conv;
	int result[50];
	int i;

	nbr_conv = 0;
	i = 0;
	if (nbr == 0)
		ft_putchar('0');
	if (ft_base(base))
	{
		nbr < 0 ? ft_putchar('-') : (nbr = -nbr);
		while (nbr)
		{
			nbr_conv = -(nbr % ft_base(base));
			nbr = nbr / ft_base(base);
			result[i] = nbr_conv;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[result[i]]);
	}
}
