/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:22:12 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:34:17 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ms;

	i = 0;
	if (!s)
		return (NULL);
	if ((ms = (char*)malloc(sizeof(char) * (len - i + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		ms[i] = s[i + start];
		i++;
	}
	ms[i] = '\0';
	return (ms);
}
