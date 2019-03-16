/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:04:39 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 10:32:55 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		k;
	size_t		j;
	size_t		lneed;
	char		*m_haystack;

	m_haystack = (char*)haystack;
	lneed = ft_strlen(needle);
	k = 0;
	if (lneed == 0)
		return (m_haystack);
	while (m_haystack[k] && k <= len)
	{
		j = 0;
		while (m_haystack[j + k] == needle[j] && k + j <= len)
		{
			j++;
			if (needle[j] == '\0' && k + j <= len)
				return (m_haystack + k);
		}
		k++;
	}
	return (NULL);
}
