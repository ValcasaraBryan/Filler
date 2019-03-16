/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:03:11 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/27 11:56:15 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_cdiouxxb(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'b')
		return (1);
	return (0);
}

int		is_sp(char c)
{
	if (c == 's' || c == 'p')
		return (1);
	return (0);
}

int		is_pf(char c)
{
	if (c == 'f' || c == '%')
		return (1);
	return (0);
}

int		is_modifier(char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	return (0);
}

int		is_flag(char c)
{
	if (c == '#' || c == '+' || c == '-' || c == '0' || c == ' ')
		return (1);
	return (0);
}
