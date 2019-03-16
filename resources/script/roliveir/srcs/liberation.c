/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:20:37 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/07 15:22:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			free_tab_int(int ***tab, int size)
{
	int		**tmp;
	int		x;

	x = -1;
	tmp = *tab;
	if (!tmp || size <= 0)
		return (0);
	while (++x < size)
		if (tmp[x])
		{
			free(tmp[x]);
		}
	free(tmp);
	tmp = NULL;
	*tab = tmp;
	return (1);
}

int			free_line(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
		return (1);
	}
	else
		return (0);
}

int			free_tab_str(char ***str)
{
	char	**tab;
	int		i;

	i = -1;
	tab = *str;
	if (!tab)
		return (0);
	else
	{
		while (tab[++i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		free(tab);
		tab = NULL;
		*str = tab;
	}
	return (i);
}

int			erase_file(t_file *file)
{
	t_file	*head_file;

	head_file = NULL;
	if (file)
	{
		while (file)
		{
			head_file = file->next;
			free(file->file);
			file->file = NULL;
			free(file);
			file = NULL;
			file = head_file;
		}
		return (1);
	}
	return (0);
}
