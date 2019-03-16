/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:29:37 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/01 15:09:10 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static long long int	ft_pow(int k, int j)
{
	if (j == 1)
		return (k);
	else if (j == 0 || j == -1)
		return (1);
	else if (j < 0)
		return (0);
	else
		return (k * ft_pow(k, j - 1));
}

static int				ft_nbr_ascii(t_flag flag, long double flt)
{
	short count;

	count = 2;
	if (flt < 0)
		count++;
	while (flt >= 1 || flt <= -1)
	{
		count++;
		flt = flt / 10;
	}
	flt = flt < 0 ? -flt : flt;
	if (flag.prec == -1)
		return (count);
	if (!flag.prec)
		count += 6;
	else
		count += flag.prec;
	return (count);
}

static	char			ft_string(t_float *mf, char *str, int *len)
{
	mf->point--;
	if (mf->point == -1)
	{
		str[(*len) - 2] = '.';
		(*len)--;
	}
	else
	{
		str[(*len) - 2] = mf->stock % 10 * mf->sign + '0';
		mf->stock = mf->stock / 10;
		(*len)--;
	}
	return (str[(*len) - 1]);
}

char					*ft_float(t_flag flag, long double flt)
{
	char			*str;
	int				len;
	t_float			mf;

	mf.sign = 1;
	len = ft_nbr_ascii(flag, flt);
	mf.point = flag.prec == 0 ? 6 : flag.prec;
	if (flag.prec == 0)
		mf.stock = flt * ft_pow(10, 7);
	else
		mf.stock = flt * ft_pow(10, flag.prec + 2);
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	if (mf.stock < 0)
	{
		str[0] = '-';
		mf.sign = -1;
	}
	str[len - 1] = '\0';
	mf.stock = mf.stock % 10 > 4 ? mf.stock / 10 + 1 : mf.stock / 10;
	while (mf.stock)
		str[len - 2] = ft_string(&mf, str, &len);
	return (str);
}
