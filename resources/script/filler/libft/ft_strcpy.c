/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:12:34 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 17:39:18 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;
	char	*m_src;

	i = -1;
	m_src = (char*)src;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
