/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:25:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/11/30 22:25:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

t_map       *new_map(char *line)
{
    t_map *list;

    if (!(list = malloc(sizeof(t_map))))
        return (NULL);
    list->map = (!list) ? NULL : line;
    list->next = NULL;
    return (list);
}

t_map        *add_map(t_map *old, t_map *new)
{
    t_map    *head;

    if (!old)
        return (new);
    else if (!new)
        return (old);
    else
    {
        head = old;
        while (old->next)
            old = old->next;
        old->next = new;
        return (head);
    }
}

t_piece        *add_piece(t_piece *old, t_piece *new)
{
    t_piece    *head;

    if (!old)
        return (new);
    else if (!new)
        return (old);
    else
    {
        head = old;
            ft_fprintf("%s\n", 2, new->piece);
        while (old->next)
        {
            ft_fprintf("%s\n", 2, old->piece);
               // ft_fprintf("%p\n", 2, old);
               // ft_fprintf("%p\n", 2, old->next);
               // ft_fprintf("coucou\n", 2);
            old = old->next;
        }
        old->next = new;
        return (head);
    }
}

t_piece     *new_piece(char *line)
{
    t_piece *list;

    if (!(list = malloc(sizeof(t_piece))))
        return (NULL);
    list->piece = (!list) ? NULL : line;
    list->next = NULL;
    return (list);
}

int         main(int argc, char **argv)
{
    char    *line;
    static int     player = 0;
    char    me;
    t_coor          map;
    t_map          *tmp_map;
    t_coor_piece    piece;
    t_piece        *tmp_piece;

    map.map = NULL;
    piece.piece = NULL;
    if (player == 0 && get_next_line(0, &line))
    {
        player = (!(ft_strstr(line, argv[0]))) ? 2 : 1;
        free(line);
        ft_printf("$$$ exec p%d : [%s]\n", player, argv[0]);
    }
    me = (player == 1) ? 'O' : 'X';
    int fd;
    char    **tab;
    int i;
    fd = open("res", O_RDWR);
    /*
    **  Parsing Entree Standars
    */
    while (get_next_line(0, &line))
    {
        if (ft_strstr(line, "Plateau"))
        {
            i = 0;
            tab = ft_strsplit(line, ' ');
            map.x_map = ft_atoi(tab[1]);
            map.y_map = ft_atoi(tab[2]);
            get_next_line(0, &line);
            while (i < map.x_map && get_next_line(0, &line))
            {
                tab = ft_strsplit(line, ' ');
                map.map = add_map(map.map, new_map(tab[1]));
                i++;
            }
            free(tab);
        }
        if (ft_strstr(line, "Piece"))
        {
            i = 0;
            tab = ft_strsplit(line, ' ');
            piece.x_piece = ft_atoi(tab[1]);
            piece.y_piece = ft_atoi(tab[2]);
            while (i < piece.x_piece && get_next_line(0, &line))
            {
                piece.piece = add_piece(piece.piece, new_piece(line));
                i++;
            }
            free(tab);
        }
    }
    /*
    ** Affichage de list
    */
    tmp_map = map.map;
    ft_fprintf("x = %d, y = %d\n", fd, map.x_map, map.y_map);
    while (tmp_map)
    {
        ft_fprintf("%s\n", fd, tmp_map->map);
        tmp_map = tmp_map->next;
    }
    tmp_piece = piece.piece;
    ft_fprintf("x = %d, y = %d\n", fd, piece.x_piece, piece.y_piece);
    while (tmp_piece)
    {
        ft_fprintf("%s\n", fd, tmp_piece->piece);
        tmp_piece = tmp_piece->next;
    }
    /*
    ** 
    */
    return (0);
}
