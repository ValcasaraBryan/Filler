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

int         erase_list(t_coor *map, t_coor_piece *piece)
{
    int     ret;

    ret = 0;
    if (map->map)
    {
        while (map->map)
        {
            free(map->map->map);
            map->map->map = NULL;
            map->map = map->map->next;
        }
        ret++;
    }
    if (piece->piece)
    {
        while (piece->piece)
        {
            free(piece->piece->piece);
            piece->piece->piece = NULL;
            piece->piece = piece->piece->next;
        }
        ret++;
    }
    return (ret);
}

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
        map->map_chaleur = (int **)malloc(sizeof (int *) * map->x_map);
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
        piece->pos_stars = (int **)malloc(sizeof (int *) * piece->x_piece);
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

int         tab_int_me(t_coor *map)
{
    t_map  *head;
    int     i;
    int     j;

    if (!map->map)
        return (0);
    head = map->map;
    map->me_list = (int **)malloc(sizeof(int *) * map->x_map);
    j = 0;
    while (head)
    {
        map->me_list[j] = (int *)malloc(sizeof(int) * map->y_map);
        i = 0;
        while (head->map[i])
        {
            if (head->map[i] == map->me || head->map[i] == map->me + 32)
                map->me_list[j][i] = i;
            else
                map->me_list[j][i] = -1;
            i++;
        }
        j++;
        head = head->next;
    }
    return (1);
}

int         tab_int_ennemi(t_coor *map)
{
    t_map  *head;
    int     i;
    int     j;

    if (!map->map)
        return (0);
    head = map->map;
    map->ennemi_list = (int **)malloc(sizeof(int *) * map->x_map);
    j = 0;
    while (head)
    {
        map->ennemi_list[j] = (int *)malloc(sizeof(int) * map->y_map);
        i = 0;
        while (head->map[i])
        {
            if (head->map[i] == map->ennemi || head->map[i] == map->ennemi + 32)
                map->ennemi_list[j][i] = i;
            else
                map->ennemi_list[j][i] = -1;
            i++;
        }
        j++;
        head = head->next;
    }
    return (1);
}

int         map_chaleur(t_coor *map)
{
    t_map   *head;
    int     x;
    int     y;

    if (!map->map)
        return (0);
    head = map->map;
    x = 0;
    while (head)
    {
        y = -1;
        map->map_chaleur[x] = (int *)malloc(sizeof(int) * map->y_map);
        while (head->map[++y])
        {
            if (head->map[y] == map->me || head->map[y] == map->me + 32)
                map->map_chaleur[x][y] = 0;
            else if (head->map[y] == map->ennemi || head->map[y] == map->ennemi + 32)
                map->map_chaleur[x][y] = -1;
            else
                map->map_chaleur[x][y] = -2;
        }
        head = head->next;
        x++;
    }
    return (1);
}

int         pos_piece(t_coor_piece *piece)
{
    t_piece *head;
    int     y;
    int     x;

    if (!piece->piece)
        return (0);
    head = piece->piece;
    x = 0;
    while (head)
    {
        y = -1;
        piece->pos_stars[x] = (int *)malloc(sizeof(int) * piece->y_piece);
        while (head->piece[++y])
            piece->pos_stars[x][y] = (head->piece[y] == '*') ? y: -1;
        head = head->next;
        x++;
    }
    return (1);
}

int         init_list_filler(t_coor *map, t_coor_piece *piece, int player)
{
    if (map && piece)
    {
        map->map = NULL;
        piece->piece = NULL;
        map->x_map = 0;
        map->y_map = 0;
        map->me = (player == 1) ? 'O' : 'X';
        map->ennemi = (player == 1) ? 'X' : 'O';
        piece->x_piece = 0;
        piece->y_piece = 0;
        return (1);
    }
    else
        return (0);
}

void    print_fd(int fd, t_coor map, t_coor_piece piece)
{
        int x;
        int y;

        x = 0;
        ft_fprintf("map_chaleur    = x = %d, y = %d\n", fd, map.x_map, map.y_map);
        ft_fprintf("\n", fd);
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                if (map.me_list[x][y] != -1)
                    ft_fprintf("me_list     = x = %d, y = %d\n", fd, x, map.me_list[x][y]);
                y++;
            }
            x++;
        }
        x = 0;
        ft_fprintf("\n", fd);
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                if (map.ennemi_list[x][y] != -1)
                    ft_fprintf("ennemi_list     = x = %d, y = %d\n", fd, x, map.ennemi_list[x][y]);
                y++;
            }
            x++;
        }
        x = 0;
        ft_fprintf("\n", fd);
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                ft_fprintf("%d", fd, map.map_chaleur[x][y]);
                if (y == map.y_map - 1)
                    ft_fprintf("\n", fd);
                y++;
            }
            x++;
        }
        ft_fprintf("\n", fd);
        while (map.map)
        {
            ft_fprintf("%s\n", fd, map.map->map);
            map.map = map.map->next;
        }
        ft_fprintf("\n", fd);
        ft_fprintf("pos_piece    = x = %d, y = %d\n", fd, piece.x_piece, piece.y_piece);
        ft_fprintf("\n", fd);
        while (piece.piece)
        {
            ft_fprintf("%s\n", fd, piece.piece->piece);
            piece.piece = piece.piece->next;
        }
        ft_fprintf("\n", fd);
        x = 0;
        while (x < piece.x_piece)
        {
            y = 0;
            while (y < piece.y_piece)
            {
                if (piece.pos_stars[x][y] != -1)
                    ft_fprintf("pos_stars    = x = %d, y = %d\n", fd, x, piece.pos_stars[x][y]);
                y++;
            }
            x++;
        }
}

int         main(int argc, char **argv)
{
    char    *line;
    int     etapes;
    int fd;
    t_coor          map;
    t_coor_piece    piece;

    fd = open("res", O_RDWR);   
    etapes = 0;
    if (get_next_line(0, &line))
    {
        init_list_filler(&map, &piece, (ft_strstr(line, "p1")) ? 1 : 2);
        free(line);
    }
    while (get_next_line(0, &line))
    {
        etapes += parsing_map(&map, line);
        etapes += parsing_piece(&piece, line);
        if (etapes == 1)
        {
            tab_int_me(&map);
            tab_int_ennemi(&map);
            map_chaleur(&map);
        }
        else if (etapes == 2)
        {
            pos_piece(&piece);
            print_fd(fd, map, piece);
            // ft_fprintf("<got (O): [%d, %d]\n\n", fd, map.x_pos_me - piece.x_pos_stars, map.y_pos_me - piece.y_pos_stars);
            // ft_printf("%d %d\n",  map.x_pos_me - piece.x_pos_stars, map.y_pos_me - piece.y_pos_stars);
            etapes = 0;
            erase_list(&map, &piece);
        }
    }
    close(fd);
    return (0);
}
