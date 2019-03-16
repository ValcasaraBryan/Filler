/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:19:47 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 17:41:51 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*my_dst;
	char	*my_src;
	size_t	i;

	my_dst = (char*)dst;
	my_src = (char*)src;
	i = 0;
	while (i < n)
	{
		my_dst[i] = my_src[i];
		i++;
	}
	return (dst);
}
