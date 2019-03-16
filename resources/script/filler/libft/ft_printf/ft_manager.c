/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:46:28 by oboutrol          #+#    #+#             */
/*   Updated: 2018/11/27 12:16:41 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long double			ft_modifier_float(va_list ap, t_flag flag)
{
	if (flag.l_maj)
		return (va_arg(ap, long double));
	else if (flag.l)
		return ((long double)va_arg(ap, double));
	return ((long double)(float)va_arg(ap, double));
}

long long int		ft_modifier_nbr(va_list ap, t_flag flag)
{
	if (flag.ll)
		return (va_arg(ap, long long int));
	else if (flag.l)
		return ((long long int)va_arg(ap, long int));
	if (flag.hh)
		return ((long long int)(char)va_arg(ap, int));
	else if (flag.h)
		return ((long long int)(short)va_arg(ap, int));
	return ((long long int)va_arg(ap, int));
}

unsigned long long	ft_modifier_unbr(va_list ap, t_flag flag)
{
	unsigned long long k;

	if (flag.hh)
	{
		k = (unsigned long long)va_arg(ap, int);
		if (k > 255)
			k = 0;
		return (k);
	}
	else if (flag.h)
	{
		k = (unsigned long long)va_arg(ap, int);
		if (k > 65535)
			k = 0;
		return (k);
	}
	else if (flag.ll)
		return (va_arg(ap, unsigned long long));
	else if (flag.l)
		return ((unsigned long long)va_arg(ap, unsigned long));
	k = (unsigned long long)va_arg(ap, unsigned int);
	if (k > 4294967295)
		k = 0;
	return (k);
}

char				*ft_manager(t_flag flag, va_list ap, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_nbrtoa(ft_modifier_nbr(ap, flag)));
	else if (c == 'c')
		return (ft_char(ap));
	else if (c == 'o')
		return (ft_conv_base(ft_modifier_unbr(ap, flag), 8, '0'));
	else if (c == 'u')
		return (ft_unbrtoa(ft_modifier_unbr(ap, flag)));
	else if (c == 'x' || c == 'X')
		return (ft_conv_base(ft_modifier_unbr(ap, flag), 16, c));
	else if (c == 's')
		return (ft_str(ap));
	else if (c == 'p')
		return (ft_conv_adrtohex(ap));
	else if (c == 'f')
		return (ft_float(flag, ft_modifier_float(ap, flag)));
	else if (c == '%')
		return (ft_char2(c));
	else if (c == 'b')
		return (ft_conv_base(ft_modifier_unbr(ap, flag), 2, '0'));
	return (NULL);
}
