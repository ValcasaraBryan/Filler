/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:20:37 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 20:20:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

int         free_tab_int(int **tab, int size)
{
    int     x;

    x = -1;
    if (!tab)
        return (0);
    while (++x < size - 1)
        free(tab[x]);
    free(tab);
    return (1);
}

int         free_tab_str(char **str)
{
    int     i;

    i = -1;
    if (!str)
        return (-1);
    else
    {
        while (str[++i])
        {
            free(str[i]);
            str[i] = NULL;
        }
        free(str);
    }
    return (i);
}

int         erase_list(t_coor *map, t_coor_piece *piece)
{
    int     ret;
    t_map   *head_map;
    t_piece   *head_piece;

    ret = 0;
    if (map->map)
    {
        while (map->map)
        {
            head_map = map->map;
            free(map->map->map);
            map->map->map = NULL;
            free(map->map);
            map->map = head_map->next;
        }
        ret++;
    }
    if (piece->piece)
    {
        while (piece->piece)
        {
            head_piece = piece->piece->next;
            free(piece->piece->piece);
            piece->piece->piece = NULL;
            free(piece->piece);
            piece->piece = head_piece;
        }
        ret++;
    }
    return (ret);
}
