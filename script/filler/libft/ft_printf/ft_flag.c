/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:17:55 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:27:30 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_precision(char *str, t_flag *flag, char c)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = -1;
	if (c == 's')
	{
		while (++i < flag->prec && str[i])
			ft_putchar_p(str[i], flag);
	}
	else
	{
		if ((c == 'd' || c == 'i') && str[0] == '-' && !flag->zero)
		{
			ft_putchar_p('-', flag);
			len--;
		}
		while (len < flag->prec && c != 'f')
		{
			ft_putchar_p('0', flag);
			len++;
		}
	}
}

void	ft_len_ext(char *str, t_flag flag, int *len, char c)
{
	if (c == 'o' || c == 'b')
	{
		if (flag.hash && *str != '0')
			(*len)++;
		else if (*str == '0')
			(*len)--;
	}
	else if (c == 'x' || c == 'X')
	{
		if (flag.hash && *str != '0')
			(*len) += 2;
		else if (*str == '0')
			(*len)--;
	}
}

int		ft_len(char *str, t_flag flag, char c)
{
	int		len;

	len = ft_strlen(str);
	if (c == 's' && flag.prec)
		len = len > flag.prec ? flag.prec : len;
	if (!(c == 'c' || c == 's' || c == 'p'))
		if (len < flag.prec)
			len = flag.prec;
	if (c == 'd' || c == 'i' || c == 'f')
	{
		if (flag.plus && str[0] != '-')
			len++;
		if (*str == '0')
			len--;
	}
	ft_len_ext(str, flag, &len, c);
	if (c == 'c' && *str == '\0')
		len++;
	return (len);
}

void	ft_choose(char *str, t_flag *flag, char c)
{
	int len;

	len = ft_len(str, *flag, c);
	if (c == 'd' || c == 'i' || c == 'f' || c == '%')
		ft_print_dif(str, flag, &len, c);
	else if (c == 'c' || c == 's' || c == 'p')
		ft_print_csp(str, flag, &len, c);
	else if (c == 'o' || c == 'x' || c == 'X' || c == 'b')
		ft_print_oxxb(str, flag, c, &len);
	else if (c == 'u')
		ft_print_u(str, flag, &len);
}
