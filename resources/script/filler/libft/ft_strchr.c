/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:11:28 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 17:39:48 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	mc;
	char			*ms;
	int				i;

	mc = (unsigned char)c;
	ms = (char*)s;
	i = 0;
	while (ms[i])
	{
		if (ms[i] == mc)
			return (ms + i);
		i++;
	}
	if (mc == '\0')
		return (ms + i);
	return (NULL);
}
