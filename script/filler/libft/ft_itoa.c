/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:20:49 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:35:34 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	lenint(int n)
{
	int				count;
	unsigned int	m;

	if (n <= 0)
	{
		count = 1;
		m = -n;
	}
	else
	{
		count = 0;
		m = n;
	}
	while (m)
	{
		m = m / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*tab;
	unsigned int	m;
	int				k;

	k = lenint(n);
	m = n < 0 ? -n : n;
	if ((tab = (char*)malloc(sizeof(char) * k + 1)) == NULL)
		return (NULL);
	tab[k] = '\0';
	while (k)
	{
		k--;
		tab[k] = m % 10 + '0';
		m = m / 10;
	}
	if (n < 0)
		tab[k] = '-';
	return (tab);
}
