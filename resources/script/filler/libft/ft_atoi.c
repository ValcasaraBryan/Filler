/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:50:04 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 17:44:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned char	*mstr;
	int				is_neg;
	int				final;
	int				i;

	i = 0;
	mstr = (unsigned char*)str;
	final = 0;
	is_neg = 1;
	while ((mstr[i] >= 9 && mstr[i] <= 13) || mstr[i] == 32)
		i++;
	if (mstr[i] == '-')
		is_neg = -1;
	if (mstr[i] == '-' || mstr[i] == '+')
		i++;
	while (mstr[i] >= '0' && mstr[i] <= '9')
	{
		final *= 10;
		final += (mstr[i] - '0');
		i++;
	}
	return (is_neg * final);
}
