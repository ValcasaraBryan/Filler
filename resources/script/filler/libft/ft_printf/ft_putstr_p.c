/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:15:49 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/07 18:29:36 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_p(char const *s, t_flag *flag)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_p(*s, flag);
			s++;
		}
	}
}
