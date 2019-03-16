/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:59:26 by oboutrol          #+#    #+#             */
/*   Updated: 2018/12/01 14:56:23 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

char	*ft_char(va_list ap)
{
	char	*a;

	if ((a = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	*a = (char)va_arg(ap, int);
	*(a + 1) = '\0';
	return (a);
}

char	*ft_char2(char c)
{
	char	*a;

	if ((a = (char*)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	*a = c;
	*(a + 1) = '\0';
	return (a);
}

char	*ft_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (str == NULL)
	{
		if ((str = (char*)malloc(sizeof(char) * 7)) == NULL)
			return (NULL);
		str[0] = '(';
		str[1] = 'n';
		str[2] = 'u';
		str[3] = 'l';
		str[4] = 'l';
		str[5] = ')';
		str[6] = '\0';
		return (str);
	}
	return (ft_strdup(str));
}
