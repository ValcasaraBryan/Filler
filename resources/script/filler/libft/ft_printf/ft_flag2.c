/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:12:18 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:28:33 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"

void	ft_minus(t_flag *flag, int *len)
{
	while ((*len) < flag->size)
	{
		ft_putchar_p(' ', flag);
		(*len)++;
	}
}

void	ft_hash(char c, t_flag *flag)
{
	if (c == 'o')
		ft_putchar_p('0', flag);
	else if (c == 'x')
		ft_putstr_p("0x", flag);
	else if (c == 'X')
		ft_putstr_p("0X", flag);
}

void	ft_zero(char *str, t_flag *flag, int *len, char c)
{
	if ((c == 'i' || c == 'd') && str[0] == '-')
		ft_putchar_p('-', flag);
	else if ((c == 'i' || c == 'd') && flag->plus)
		ft_putchar_p('+', flag);
	if (flag->prec != 0 && *str == '0')
		(*len)++;
	while ((*len) < flag->size)
	{
		if (flag->prec != 0 && str[0] != '-')
			ft_putchar_p(' ', flag);
		else
			ft_putchar_p('0', flag);
		(*len)++;
	}
}

void	ft_space(int *len, t_flag *flag)
{
	ft_putchar_p(' ', flag);
	(*len)++;
}

void	ft_field(t_flag *flag, int *len)
{
	while ((*len) < flag->size)
	{
		ft_putchar_p(' ', flag);
		(*len)++;
	}
}
