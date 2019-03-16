/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:23:31 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 15:23:38 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_base(char *base, char *str)
{
	int i;
	int j;

	i = 0;
	j = -1;
	if (str == NULL || base == NULL)
		return (0);
	while (base[i])
	{
		while (base[++j])
			if (base[i] == base[j] && i != j)
				return (0);
		j = -1;
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int		ft_check(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(char *str, char *base)
{
	int i;
	int nb;
	int is_negative;
	int lenght;

	i = 0;
	nb = 0;
	is_negative = 1;
	lenght = ft_base(base, str);
	if (lenght <= 1)
		return (0);
	if (str[i] == 45)
		is_negative = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i])
	{
		if (ft_check(str[i], base) == -1)
			return (0);
		nb = nb * lenght + ft_check(str[i], base);
		i++;
	}
	return (nb * is_negative);
}
