/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:04:21 by roliveir          #+#    #+#             */
/*   Updated: 2018/11/12 12:01:00 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start]
				== '\t') && s[start])
		start++;
	if (s[start] == '\0')
		return (ft_strsub(s, 0, 0));
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len)
		len--;
	return (ft_strsub(s, start, len - start + 1));
}
