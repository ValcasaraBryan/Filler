/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 11:09:26 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:29:27 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

void	ft_print_dif(char *str, t_flag *flag, int *len, char c)
{
	if (flag->space && str[0] != '-' && !flag->plus && c != '%')
		ft_space(len, flag);
	if (flag->zero && !flag->minus)
		ft_zero(str, flag, len, c);
	else if (flag->size > 0 && !flag->minus)
		ft_field(flag, len);
	if (flag->plus && str[0] != '-' && !flag->zero)
		ft_putchar_p('+', flag);
	if (flag->prec)
		ft_precision(str, flag, c);
	if ((flag->zero || flag->prec) && !flag->minus && str[0] == '-')
		ft_putstr_p(str + 1, flag);
	else if (flag->prec > -1 || *str != '0')
		ft_putstr_p(str, flag);
	if (flag->minus)
		ft_minus(flag, len);
}

void	ft_print_csp(char *str, t_flag *flag, int *len, char c)
{
	int i;

	i = 0;
	if (flag->size > 0 && !flag->minus)
		ft_field(flag, len);
	if (flag->prec && c == 's')
		ft_precision(str, flag, c);
	else
		ft_putstr_p(str, flag);
	if (c == 'c' && *str == '\0')
		ft_putchar_p('\0', flag);
	if (flag->minus)
		ft_minus(flag, len);
}

void	ft_print_oxxb(char *str, t_flag *flag, char c, int *len)
{
	if (flag->size > 0 && !flag->minus && !flag->zero)
		ft_field(flag, len);
	if (flag->hash && *str != '0' && c != 'b')
		ft_hash(c, flag);
	if (flag->zero && !flag->minus)
		ft_zero(NULL, flag, len, 0);
	if (flag->prec > 0)
		ft_precision(str, flag, 0);
	if (!(flag->prec < 0 && *str != 0))
		ft_putstr_p(str, flag);
	if (flag->prec == -1 && *str == '0' && c == 'o' && flag->hash)
		ft_putstr_p(str, flag);
	if (flag->minus)
		ft_minus(flag, len);
}

void	ft_print_u(char *str, t_flag *flag, int *len)
{
	if (flag->zero && !flag->minus)
		ft_zero(NULL, flag, len, 0);
	else if (flag->size > 0 && !flag->minus)
		ft_field(flag, len);
	if (flag->prec)
		ft_precision(str, flag, 0);
	ft_putstr_p(str, flag);
	if (flag->minus)
		ft_minus(flag, len);
}
