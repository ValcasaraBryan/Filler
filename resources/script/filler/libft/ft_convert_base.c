/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 01:50:18 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:37:16 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_base(char *base, char c, int b)
{
	int i;
	int j;

	i = -1;
	if (b)
	{
		j = -1;
		while (base[++i])
		{
			while (base[++j])
				if (base[i] == base[j] && i != j)
					return (0);
			j = -1;
			if (base[i] == '-' || base[i] == '+' || base[i] < 32)
				return (0);
		}
		return (i < 2 ? 0 : i);
	}
	else
	{
		while (base[++i])
			if (base[i] == c)
				return (i);
		return (-1);
	}
}

static int		ft_atoi_base2(char *str, char *base)
{
	int i;
	int nb;
	int is_negative;
	int lenght;

	i = 0;
	nb = 0;
	is_negative = 1;
	lenght = ft_base(base, str[i], 1);
	if (lenght <= 1)
		return (0);
	if (str[i] == 45)
		is_negative = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0')
	{
		if (ft_base(base, str[i], 0) == -1 || str[i] == 43 || str[i] == 45)
			return (0);
		nb = nb * lenght + ft_base(base, str[i], 0);
		i++;
	}
	return (nb * is_negative);
}

static int		ft_strlen2(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		str++;
		i++;
	}
	return (i);
}

static char		*ft_put2(int nbr, char *base)
{
	int		n;
	int		result[50];
	int		i;
	char	*t;
	int		neg;

	n = 0;
	i = 0;
	neg = nbr > 0 ? 1 : -1;
	nbr = nbr > 0 ? nbr : -nbr;
	while (nbr)
	{
		n = nbr % ft_base(base, base[0], 1);
		nbr = nbr / ft_base(base, base[0], 1);
		result[i] = n;
		i++;
	}
	i = (neg == 1 ? i : i + 1);
	t = malloc(sizeof(int) * i);
	n = -1;
	t[i] = '\0';
	t[0] = '-';
	while (--i >= (neg == 1 ? 0 : 1) && ++n > -3)
		t[(neg == 1 ? n : n + 1)] = base[result[(neg == 1 ? i : i - 1)]];
	return (t);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*t;
	int		length;

	if (base_from == 0 || base_to == 0)
		return (0);
	if (ft_base(base_from, nbr[1], 1) == 0 || ft_base(base_to, nbr[1], 1) == 0)
		return (0);
	length = ft_strlen2(ft_put2(ft_atoi_base2(nbr, base_from), base_to));
	t = malloc(sizeof(char) * length + 1);
	if (nbr[0] == '0' && nbr[1] == 0)
	{
		t[0] = base_to[0];
		return (t);
	}
	t = ft_put2(ft_atoi_base2(nbr, base_from), base_to);
	return (ft_atoi_base2(nbr, base_from) ? t : 0);
}
