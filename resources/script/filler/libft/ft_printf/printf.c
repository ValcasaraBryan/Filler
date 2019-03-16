/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:35:50 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:30:02 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_match(char **str, char c)
{
	if (**str != c)
		return (0);
	(*str)++;
	return (1);
}

void	init_zero(t_flag *flag)
{
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->l_maj = 0;
	flag->hash = 0;
	flag->plus = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->space = 0;
	flag->size = 0;
	flag->prec = 0;
}

int		ft_parse(char **str, t_flag *flag)
{
	init_zero(flag);
	while (**str != '%' && **str)
	{
		ft_putchar_p(**str, flag);
		(*str)++;
	}
	if (ft_match(str, '%'))
		return (find_conv(str, flag));
	return (0);
}

int		ft_printf(char *arg0, ...)
{
	va_list		ap;
	t_flag		flag;
	char		ret;
	char		*str;

	flag.re = 0;
	if (arg0 == NULL)
		return (1);
	va_start(ap, arg0);
	while ((ret = ft_parse(&arg0, &flag)))
	{
		arg0++;
		if ((str = ft_manager(flag, ap, ret)) == NULL)
			return (1);
		ft_choose(str, &flag, ret);
		ft_strdel(&str);
	}
	va_end(ap);
	return (flag.re);
}
