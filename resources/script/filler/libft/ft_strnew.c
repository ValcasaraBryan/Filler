/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:18:25 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:33:09 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if ((mem = (char*)malloc(size + 1)) == NULL)
		return (NULL);
	ft_bzero(mem, size);
	mem[size] = '\0';
	return (mem);
}
