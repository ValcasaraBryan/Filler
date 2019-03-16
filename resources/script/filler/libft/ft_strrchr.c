/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:42:36 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 17:36:20 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ms;
	unsigned char	mc;
	int				i;

	ms = (char*)s;
	mc = (unsigned char)c;
	i = 0;
	while (ms[i])
		i++;
	while (i >= 0)
	{
		if (ms[i] == mc)
			return (ms + i);
		i--;
	}
	return (NULL);
}
