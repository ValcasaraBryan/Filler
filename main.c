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
        while (old->next)
            old = old->next;
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

int         parsing_map(t_coor *map, char *line)
{
    int i;
    char **tab;

    tab = NULL;
    if (ft_strstr(line, "Plateau"))
    {
        i = 0;
        tab = ft_strsplit(line, ' ');
        map->x_map = ft_atoi(tab[1]);
        map->y_map = ft_atoi(tab[2]);
        get_next_line(0, &line);
        while (i < map->x_map && get_next_line(0, &line))
        {
            tab = ft_strsplit(line, ' ');
            map->map = add_map(map->map, new_map(tab[1]));
            i++;
        }
        // free(tab[0])
        // free(tab[2])
        // free(tab[3])
        free(tab);
        return (1);
    }
    else
        return (0);
}

int         parsing_piece(t_coor_piece *piece, char *line)
{
    int i;
    char **tab;

    tab = NULL;
    if (ft_strstr(line, "Piece"))
    {
        i = 0;
        tab = ft_strsplit(line, ' ');
        piece->x_piece = ft_atoi(tab[1]);
        piece->y_piece = ft_atoi(tab[2]);
        while (i < piece->x_piece && get_next_line(0, &line))
        {
            piece->piece = add_piece(piece->piece, new_piece(line));
            i++;
        }
        // free(tab[0])
        // free(tab[2])
        // free(tab[3])
        free(tab);
        return (1);
    }
    else
        return (0);
}

int         valid_pos(t_coor *map, t_map *head, char ennemi, int x)
{
    int     y;

    if ((y = ft_strnchr(head->map, ennemi, map->y_map)) >= 0)
    {
        map->x_pos_ennemi = x;
        map->y_pos_ennemi = y;
        return (1);
    }
    else
        return (0);
}

int         pos_ennemi(t_coor *map, char ennemi)
{
    t_map           *head;
    int             prev_pos;
    unsigned int    boucle;
    int             x;

    if (!&(map->map))
        return (0);
    boucle = 2;
    while (boucle--)
    {
        x = 0;
        head = map->map;
        prev_pos = (boucle < 1) ? 0 : 32;
        while (head)
        {
            if (valid_pos(map, head, ennemi + prev_pos, x) == 1)
                return (1);
            head = head->next;
            x++;
        }
    }
    return (0);
}

int         pos_piece(t_coor_piece *piece)
{
    t_piece *head;
    int     y;
    int     x;

    if (!&(piece->piece))
        return (0);
    head = piece->piece;
    x = 0;
    while (head)
    {
        if ((y = ft_strnchr(head->piece, '*', piece->y_piece)) >= 0)
        {
            piece->y_pos_stars = y;
            piece->x_pos_stars = x;
            return (1);
        }
        head = head->next;
        x++;
    }
    return (1);
}


int         main(int argc, char **argv)
{
    char    *line;
    static int     player = 0;
    char    me;
    t_coor          map;
    t_coor_piece    piece;

//    t_map          *tmp_map;
//    t_piece        *tmp_piece;

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
    fd = open("res", O_RDWR);
    /*
    **  Parsing Entree Standars
    */
    while (get_next_line(0, &line))
    {
        parsing_map(&map, line);
        parsing_piece(&piece, line);
    }
    pos_ennemi(&map, (me == 'O') ? 'X' : 'O');
    pos_piece(&piece);
    ft_fprintf("poss_map   = x = %d, y = %d\n", fd, map.x_pos_ennemi, map.y_pos_ennemi);
    ft_fprintf("poss_piece = x = %d, y = %d\n", fd, piece.x_pos_stars, piece.y_pos_stars);
    /*
    ** Affichage de list
    */
    //tmp_map = map.map;
    //ft_fprintf("x = %d, y = %d\n", fd, map.x_map, map.y_map);
    //while (tmp_map)
    //{
    //    ft_fprintf("%s\n", fd, tmp_map->map);
    //    tmp_map = tmp_map->next;
    //}
    //tmp_piece = piece.piece;
    //ft_fprintf("x = %d, y = %d\n", fd, piece.x_piece, piece.y_piece);
    //while (tmp_piece)
    //{
    //    ft_fprintf("%s\n", fd, tmp_piece->piece);
    //    tmp_piece = tmp_piece->next;
    //}
    close(fd);
    /*
    ** 
    */
    return (0);
}
