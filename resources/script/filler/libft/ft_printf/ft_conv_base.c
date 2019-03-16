/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:09:27 by oboutrol          #+#    #+#             */
/*   Updated: 2018/11/27 12:05:07 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static int	ft_nb_ascii_base(unsigned long long int nbr, int base)
{
	int nb;

	nb = 1;
	if (nbr == 0)
		return (2);
	while (nbr != 0)
	{
		nb++;
		nbr = nbr / base;
	}
	return (nb);
}

char		*ft_conv_base(unsigned long long int nbr, int base, char id)
{
	char	*str;
	int		nbasc;
	int		sign;
	char	c;

	sign = 1;
	nbasc = ft_nb_ascii_base(nbr, base);
	if ((str = (char*)malloc(sizeof(char) * nbasc)) == NULL)
		return (NULL);
	str[nbasc - 1] = 0;
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		c = nbr % base * sign;
		if (c <= 9)
			c = c + '0';
		else
			c = c - 10 + id - 'x' + 'a';
		str[nbasc - 2] = c;
		nbr = nbr / base;
		nbasc--;
	}
	return (str);
}

char		*ft_conv_adrtohex(va_list ap)
{
	void					*str;
	unsigned long long int	nbr;
	char					*hex;
	char					*ret;

	str = va_arg(ap, void*);
	nbr = (unsigned long long int)str;
	hex = ft_conv_base(nbr, 16, 'x');
	ret = ft_strjoin("0x", hex);
	free(hex);
	return (ret);
}
