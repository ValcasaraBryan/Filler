/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:02:34 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/11 16:14:54 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;
	char	*m_haystack;
	char	*m_needle;

	i = 0;
	k = 0;
	m_haystack = (char*)haystack;
	m_needle = (char*)needle;
	if (m_needle[0] == '\0')
		return (m_haystack);
	while (m_haystack[i])
	{
		k = 0;
		while (m_haystack[i + k] == m_needle[k])
		{
			if (m_needle[k + 1] == '\0')
				return (m_haystack + i);
			k++;
		}
		i++;
	}
	return (0);
}
