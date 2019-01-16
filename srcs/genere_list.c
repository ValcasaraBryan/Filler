/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genere_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:17:29 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:24:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**tab_char(size_t len)
{
	char	**tab;
	size_t i;

	i = 0;
	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	while (i < len)
		tab[i++] = NULL;
	return (tab);
}

int		check_tab(char **tab)
{
	int	i;

	if (!tab)
		return (-1);
	i = 0;
	while (i >= 0)
	{
		if (tab[i] == NULL)
			return (i);
		else
			i++;
	}
	return (i);
}

int		check_char_piece(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] != '.' && str[i] != '*')
			return (0);
	return (1);
}

int		check_char(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] != '.' && str[i] != 'O' && str[i] != 'X')
			return (0);
	return (1);
}

int		check_y_map(char *str, size_t len)
{
	int		i;
	int		tmp;
	int		val;

	if (!str)
		return (0);
	i = -1;
	val = 0;
	while (++i < (int)len)
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		val = str[i] - 48;
		tmp = i;
		while (tmp > 9)
			tmp = tmp % 10;
		if (val != tmp)
			return (0);
	}
	return (1);
}