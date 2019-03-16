/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:49:07 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:34:33 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ms;

	if (!s1 || !s2)
		return (NULL);
	if ((ms = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2)) + 1)) == NULL)
		return (0);
	ft_strcpy(ms, s1);
	ft_strcat(ms, s2);
	return (ms);
}
