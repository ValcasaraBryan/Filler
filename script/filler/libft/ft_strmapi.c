/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:44:26 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 11:58:42 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ms;
	char			*map;
	unsigned int	i;
	size_t			len;

	if (!s || !s)
		return (NULL);
	ms = (char*)s;
	i = 0;
	len = ft_strlen(ms);
	if ((map = ft_strnew(len)) == NULL)
		return (NULL);
	map[len] = '\0';
	while (ms[i])
	{
		map[i] = f(i, ms[i]);
		i++;
	}
	return (map);
}
