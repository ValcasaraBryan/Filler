/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:16:43 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:33:50 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;
	size_t	len;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if ((map = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	map[len] = '\0';
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
