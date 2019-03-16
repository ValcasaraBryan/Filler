/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:13:25 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 11:33:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*mdst;
	char	*msrc;

	mdst = (char*)dst;
	msrc = (char*)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			mdst[len] = msrc[len];
	return (dst);
}
