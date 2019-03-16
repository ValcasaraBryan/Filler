/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:22:42 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 12:11:01 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int m;

	if (n < 0)
	{
		m = -n;
		ft_putchar('-');
	}
	else
		m = n;
	if (m > 9)
	{
		ft_putnbr(m / 10);
		ft_putnbr(m % 10);
	}
	else
		ft_putchar(m + '0');
}
