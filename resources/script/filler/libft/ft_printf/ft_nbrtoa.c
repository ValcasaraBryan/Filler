/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:45:04 by oboutrol          #+#    #+#             */
/*   Updated: 2018/11/26 12:20:35 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static int	ft_nbr_ascii(long long int nbr)
{
	int	nb;

	nb = 1;
	if (nbr == 0)
		return (2);
	if (nbr < 0)
		nb++;
	while (nbr != 0)
	{
		nb++;
		nbr = nbr / 10;
	}
	return (nb);
}

static int	ft_unbr_ascii(unsigned long long nbr)
{
	int nb;

	nb = 1;
	if (nbr == 0)
		return (2);
	while (nbr != 0)
	{
		nb++;
		nbr = nbr / 10;
	}
	return (nb);
}

char		*ft_nbrtoa(long long int nbr)
{
	char	*str;
	int		nbasc;
	int		sign;

	sign = 1;
	nbasc = ft_nbr_ascii(nbr);
	if ((str = (char*)malloc(sizeof(char) * nbasc)) == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	str[nbasc - 1] = 0;
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[nbasc - 2] = nbr % 10 * sign + '0';
		nbr = nbr / 10;
		nbasc--;
	}
	return (str);
}

char		*ft_unbrtoa(unsigned long long int nbr)
{
	char	*str;
	int		nbasc;

	nbasc = ft_unbr_ascii(nbr);
	if ((str = (char*)malloc(sizeof(char) * nbasc)) == NULL)
		return (NULL);
	str[nbasc - 1] = 0;
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[nbasc - 2] = nbr % 10 + '0';
		nbr = nbr / 10;
		nbasc--;
	}
	return (str);
}
