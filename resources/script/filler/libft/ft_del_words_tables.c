/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_words_tables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:40:30 by roliveir          #+#    #+#             */
/*   Updated: 2018/12/12 15:37:36 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_del_words_tables(char ***tab)
{
	char	**tmp;

	tmp = *tab;
	while (**tab)
	{
		ft_strdel(*tab);
		*tab += 1;
	}
	free(tmp);
}
