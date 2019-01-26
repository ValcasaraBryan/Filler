/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:26:45 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/27 12:16:43 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoip(char **str)
{
	unsigned char	**mstr;
	int				is_neg;
	int				final;

	mstr = (unsigned char**)str;
	final = 0;
	is_neg = 1;
	while ((**mstr >= 9 && **mstr <= 13) || **mstr == 32)
		(*mstr)++;
	if (**mstr == '-')
		is_neg = -1;
	if (**mstr == '-' || **mstr == '+')
		(*mstr)++;
	while (**mstr >= '0' && **mstr <= '9')
	{
		final *= 10;
		final += ((**mstr) - '0');
		(*mstr)++;
	}
	return (is_neg * final);
}

void	find_modifier(char **str, t_flag *flag)
{
	while (is_modifier(**str))
	{
		if (ft_match(str, 'h'))
			flag->h = 1;
		if (ft_match(str, 'l'))
			flag->l = 1;
		if (ft_match(str, 'h') && flag->h == 1)
			flag->hh = 1;
		if (ft_match(str, 'l') && flag->l == 1)
			flag->ll = 1;
		if (ft_match(str, 'L'))
			flag->l_maj = 1;
	}
}

void	find_flag(char **str, t_flag *flag)
{
	while (is_flag(**str))
	{
		if (ft_match(str, '#'))
			flag->hash = 1;
		else if (ft_match(str, '+'))
			flag->plus = 1;
		else if (ft_match(str, '-'))
			flag->minus = 1;
		else if (ft_match(str, '0'))
			flag->zero = 1;
		else if (ft_match(str, ' '))
			flag->space = 1;
	}
}

int		find_precision(char **str)
{
	int i;

	if (ft_match(str, '.'))
	{
		if ((i = ft_atoip(str)) == 0)
			return (-1);
		return (i);
	}
	return (0);
}

int		find_conv(char **str, t_flag *flag)
{
	find_flag(str, flag);
	flag->size = ft_atoip(str);
	flag->prec = find_precision(str);
	find_modifier(str, flag);
	if (is_cdiouxxb(**str) || is_sp(**str)
			|| is_pf(**str))
		return (**str);
	return (0);
}
