/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:25:33 by oboutrol          #+#    #+#             */
/*   Updated: 2018/12/07 18:18:13 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <wchar.h>

static void	ft_write_4(wchar_t ch)
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;

	d = ch % 64 + 128;
	ch = ch / 64;
	c = ch % 64 + 128;
	ch = ch / 64;
	b = ch % 64 + 128;
	a = ch / 64 + 192 + 32 + 16;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

static void	ft_write_3(wchar_t ch)
{
	unsigned char a;
	unsigned char b;
	unsigned char c;

	c = ch % 64 + 128;
	ch = ch / 64;
	b = ch % 64 + 128;
	a = ch / 64 + 192 + 32;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

static void	ft_write_2(wchar_t ch)
{
	unsigned char a;
	unsigned char b;

	b = ch % 64 + 128;
	a = ch / 64 + 192;
	write(1, &a, 1);
	write(1, &b, 1);
}

int			ft_putchar_p(wchar_t ch, t_flag *flag)
{
	(flag->re)++;
	if (ch < 128)
	{
		write(1, &ch, 1);
		return (1);
	}
	if (ch < 2048)
	{
		ft_write_2(ch);
		return (2);
	}
	if (ch < 16777216)
	{
		ft_write_3(ch);
		return (3);
	}
	ft_write_4(ch);
	return (4);
}
