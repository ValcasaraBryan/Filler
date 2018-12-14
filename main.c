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

int         free_tab_int(int **tab)
{
    int     i;

    i = -1;
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
    return (1);
}

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
        free_tab_str(tab);
        if (!(map->map_chaleur = (int **)malloc(sizeof (int *) * map->x_map)))
            return (-1);
        if (!(map->me_list = (int **)malloc(sizeof(int *) * map->x_map)))
            return (-1);
        if (!(map->ennemi_list = (int **)malloc(sizeof(int *) * map->x_map)))
            return (-1);
        get_next_line(0, &line);
        free(line);
            line = NULL;
        while (i < map->x_map && get_next_line(0, &line))
        {
            tab = ft_strsplit(line, ' ');
            free(line);
            free(tab[0]);
            tab[0] = NULL;
            line = NULL;
            map->map = add_map(map->map, new_map(tab[1]));
            i++;
        }
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
        free_tab_str(tab);
        if (!(piece->pos_stars = (int **)malloc(sizeof (int *) * piece->x_piece)))
            return (-1);
        while (i < piece->x_piece && get_next_line(0, &line))
        {
            piece->piece = add_piece(piece->piece, new_piece(line));
            i++;
        }
        return (1);
    }
    else
        return (0);
}

int         tab_int(t_coor *map, char char_of_player)
{
    t_map   *head;
    int     **tab;
    int     i;
    int     j;

    if (!map->map || !map->me_list || !map->ennemi_list)
        return (-1);
    head = map->map;
    tab = (char_of_player == map->me) ? map->me_list : map->ennemi_list;
    j = 0;
    while (head)
    {
        if (!(tab[j] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        i = -1;
        while (head->map[++i])
        {
            tab[j][i] = (head->map[i] == char_of_player) ? i : -1;
            tab[j][i] = (head->map[i] == char_of_player + 32) ? -4 : tab[j][i];
        }
        j++;
        head = head->next;
    }
    return (1);
}

int         val_around(t_coor *map, int val, int x, int y)
{
    int     tmp;

    
    val = (y - 1 >= 0 && (tmp = map->map_chaleur[x][y - 1]) > 0 && tmp <= val) ? tmp : val;
    val = (y + 1 < map->y_map && (tmp = map->map_chaleur[x][y + 1]) > 0 && tmp <= val) ? tmp : val;
    val = (x - 1 >= 0 && (tmp = map->map_chaleur[x - 1][y]) > 0 && tmp <= val) ? tmp : val;
    val = (x + 1 < map->x_map && (tmp = map->map_chaleur[x + 1][y]) > 0 && tmp <= val) ? tmp : val;
    return (val);
}

int         check_position_right_down(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}

int         check_position_left_up(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = map->x_map;
    while (--x >= 0)
    {
        y = map->y_map;
        while (--y >= 0)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}


int         check_position_right_up(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = map->x_map;
    while (--x >= 0)
    {
        y = -1;
        while (++y < map->y_map)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}

int         check_position_left_down(t_coor *map)
{
    int     x;
    int     y;
    int     val;

    if (!map->map_chaleur)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = map->y_map;
        while (--y >= 0)
        {
            val = map->y_map * map->x_map;
            if (map->map_chaleur[x][y] == 0)
            {
                val = val_around(map, val, x, y);
                if (val > 0 && val < map->y_map * map->x_map)
                    map->map_chaleur[x][y] = val + 1;
            }
        }
    }
    return (1);
}


int         chaleur_down(t_coor *map, int y)
{
    int     i;
    int     x;

    if (!map->map || !map->ennemi_list || !map->map_chaleur)
        return (0);
    i = map->x_map;
    while (--i >= 0)
    {
        if (map->ennemi_list[i][y] == y)
        {
            x = i;
            while (++i < map->x_map)
                if (map->map_chaleur[i][y] == 0)
                {
                    map->map_chaleur[i][y] = i - x + 1;
                    break;
                }
            break;
        }
        else if (map->ennemi_list[i][y] == -4)
        {
            x = i;
            while (++i < map->x_map)
                if (map->map_chaleur[i][y] == 0)
                {
                    map->map_chaleur[i][y] = 1;
                    break;
                }
            break;
        }
    }
    return (1);
}

int         chaleur_up(t_coor *map, int y)
{
    int     i;
    int     x;

    if (!map->map)
        return (0);
    i = -1;
    while (++i < map->x_map)
        if (map->ennemi_list[i][y] == y)
        {
            x = i;
            while (--i >= 0)
                if (map->map_chaleur[i][y] == 0)
                {
                    map->map_chaleur[i][y] = x - i + 1;
                    break;
                }
            break;
        }
        else if (map->ennemi_list[i][y] == -4)
        {
            x = i;
            while (--i >= 0)
                if (map->map_chaleur[i][y] == 0)
                {
                    map->map_chaleur[i][y] = 1;
                    break;
                }
            break;
        }
    return (1);
}

int         chaleur_right(t_coor *map, int x)
{
    int     i;
    int     y;

    if (!map->map)
        return (0);
    i = map->y_map;
    while (i--)
        if (map->ennemi_list[x][i] == i)
        {
            y = i;
            while (i++ < map->y_map)
                if (map->map_chaleur[x][i] == 0)
                {
                    map->map_chaleur[x][i] = i - y + 1;
                    break;
                }
            break;
        }
        else if (map->ennemi_list[x][i] == -4)
        {
            y = i;
            while (i++ < map->y_map)
                if (map->map_chaleur[x][i] == 0)
                {
                    map->map_chaleur[x][i] = 1;
                    break;
                }
            break;
        }
    return (1);
}

int         chaleur_left(t_coor *map, int x)
{
    int     i;
    int     y;

    if (!map->map)
        return (0);
    i = -1;
    while (++i < map->y_map)
        if (map->ennemi_list[x][i] == i)
        {
            y = i;
            while (i-- > 0)
                if (map->map_chaleur[x][i] == 0)
                {
                    map->map_chaleur[x][i] = y - i + 1;
                    break;
                }
            break;
        }
        else if (map->ennemi_list[x][i] == -4)
        {
            y = i;
            while (i-- > 0)
                if (map->map_chaleur[x][i] == 0)
                {
                    map->map_chaleur[x][i] = 1;
                    break;
                }
            break;
        }
    return (1);
}

int         val_player_fct(t_coor *map, int x, int y)
{
    if (!map->map)
        return (-1);
    if (map->me_list[x][y] == y)
        return (-3);
    else if (map->ennemi_list[x][y] == y)
        return (-2);
    else if (map->ennemi_list[x][y] == -4)
        return (-4);
    else
        return (0);
}

int         map_chaleur_horizontal(t_coor *map)
{
    int     x;
    int     y;
    int     val_player;

    if (!map->map || !map->x_map)
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        if (!(map->map_chaleur[x] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        ft_bzero(map->map_chaleur[x], map->y_map);
        chaleur_left(map, x);
        chaleur_right(map, x);
        while (++y < map->y_map)
            if (map->me_list[x][y] == y || map->ennemi_list[x][y] == y || map->ennemi_list[x][y] == -4)
                map->map_chaleur[x][y] = val_player_fct(map, x, y);
    }
    return (1);
}

int         map_chaleur_vertical(t_coor *map)
{
    int     y;

    if (!map->map_chaleur || !map->y_map || !map->x_map)
        return (0);
    y = -1;
    while (++y < map->y_map)
    {
        chaleur_up(map, y);
        chaleur_down(map, y);
    }
    return (1);
}

int         best_position(t_coor *map, int x, int y, int val)
{
    int     tmp;

    if (!(map->map_chaleur))
        return (-1);
    val = (y + 1 < map->y_map && (tmp = map->map_chaleur[x][y + 1]) && tmp > 0 && val > tmp) ? tmp : val;
    val = (y - 1 >= 0 && (tmp = map->map_chaleur[x][y - 1]) && tmp > 0 && val > tmp) ? tmp : val;
    val = (x + 1 < map->x_map && (tmp = map->map_chaleur[x + 1][y]) && tmp > 0 && val > tmp) ? tmp : val;
    val = (x - 1 >= 0 && (tmp = map->map_chaleur[x - 1][y]) && tmp > 0 && val > tmp) ? tmp : val;
    return (val);
}

int         check_around_pos(t_coor *map, t_coor_piece *piece)
{
    int     i;
    int     x;
    int     y;
    int     best_pos;

    if (!(map->map_chaleur) || !(piece->pos_stars))
        return (0);
    x = -1;
    best_pos = map->x_map * map->y_map;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
            if (map->me_list[x][y] != -1 && piece->last_best_pos[x][y] == -1)
            {
                piece->y_best_pos = ((i = best_position(map, x, y, best_pos))
                    < best_pos) ? y : piece->y_best_pos;
                piece->x_best_pos = ((i = best_position(map, x, y, best_pos))
                    < best_pos) ? x : piece->x_best_pos;
                best_pos = i;
            }
    }
    return (1);
}

int         nb_tab(t_coor *map, t_coor_piece *piece, int **tab)
{
    int     x;
    int     y;
    int     i;

    x = -1;
    i = 0;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            if (tab[x][y] != -1)
                i++;
        }
    }
    return (i);
}

int         check_around_best_pos(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     x_stars;
    int     y;
    int     y_stars;
    int     val_pos;

    if (!(piece->final_pos) || !(piece->pos_stars) || !(map->map_chaleur))
        return (0);
    x = -1;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map) // check la position final_pos en fonction de la best_pos_me
        {
            if (piece->final_pos[x][y] != -1)
            {
                x_stars = -1;
                val_pos = 0;
                while (++x_stars < piece->x_piece) // check tout les position de stars en fonction des final_pos
                {
                    y_stars = -1;
                    while (++y_stars < piece->y_piece)
                    {
                        if (piece->pos_stars[x_stars][y_stars] != -1)
                        {
                            if (x_stars + x >= map->x_map || y_stars + y >= map->y_map)
                                piece->final_pos[x][y] = -1;
                            else if (map->map_chaleur[x_stars + x][y_stars + y] == -3)
                            {
                                val_pos++;
                                if (val_pos > 1)    // si il y a plus d'une position "me" la position n'est pas valide
                                    piece->final_pos[x][y] = -1;
                            }
                            else if (map->map_chaleur[x_stars + x][y_stars + y] == -2)
                                piece->final_pos[x][y] = -1;    // si il y a une seul position "ennemi" la position n'est pas valide
                        }
                    } 
                }
            }
        }
    }
    return (1);
}
int         next_pos_stars(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;

    if (!(piece->pos_stars) || !(piece->final_pos))
        return (-1);
    x = -1;
    while (++x < piece->x_piece)
    {
        y = -1;
        while (++y < piece->y_piece)
            if (piece->pos_stars[x][y] != -1 && piece->last_best_pos[x][y] == -1)
                if (piece->x_best_pos - x < map->x_map && piece->y_best_pos - y < map->y_map)
                    if (piece->x_best_pos - x >= 0 && piece->y_best_pos - y >= 0)
                        piece->final_pos[piece->x_best_pos - x][piece->y_best_pos - y] = piece->y_best_pos - y;
    }
    return (1);
}

int         check_chaleur_piece(t_coor *map, t_coor_piece *piece, int x, int y)
{
    int     x_piece;
    int     y_piece;
    int     val;
    int     tmp;

    if (!(map->map_chaleur) || !(piece->pos_stars))
        return (-1);
    x_piece = -1;
    val = map->x_map * map->y_map;
    while (++x_piece < piece->x_piece)
    {
        y_piece = -1;
        while (++y_piece < piece->y_piece)
        {
            if (piece->pos_stars[x_piece][y_piece] != -1)
            {
                if (map->map_chaleur[x + x_piece][y + y_piece] < val)
                   tmp = map->map_chaleur[x + x_piece][y + y_piece];
                if (tmp >= 0 && tmp < val)
                   val = tmp;
            }
        }
    }
    return (val);
}

int         check_pos_final(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;
    int     val;
    int     tmp;

    if (!(map->map_chaleur) || !(piece->final_pos) || !(map->me_list))
        return (-1);
    x = -1;
    val = map->x_map * map->y_map;
    while (++x < map->x_map)
    {
        y = -1;
        while (++y < map->y_map)
        {
            if (piece->final_pos[x][y] != -1)
            {
                tmp = check_chaleur_piece(map, piece, x, y);
                if (tmp < val)
                {
                    val = tmp;
                    piece->x_final_pos = x;
                    piece->y_final_pos = y;
                }
            }
        }
    }
    return (1);
}

int         init_last_best_pos(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;

    if (!(map->map_chaleur) || !(piece->pos_stars))
        return (0);
    x = -1;
    if (!(piece->last_best_pos = (int **)malloc(sizeof(int *) * map->x_map)))
        return (-1);
    while (++x < map->x_map)
    {
        y = -1;
        if (!(piece->last_best_pos[x] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        while (++y < map->y_map)
            piece->last_best_pos[x][y] = -1;
    }
    return (1);
}

int         final_pos_piece(t_coor *map, t_coor_piece *piece)
{
    int     x;
    int     y;

    x = -1;
    if (!(piece->final_pos = (int **)malloc(sizeof(int *) * map->x_map)))
        return (-1);
    while (++x < map->x_map)
    {
        y = -1;
        if (!(piece->final_pos[x] = (int *)malloc(sizeof(int) * map->y_map)))
            return (-1);
        while (++y < map->y_map)
            piece->final_pos[x][y] = -1;
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
        if (!(piece->pos_stars[x] = (int *)malloc(sizeof(int) * piece->y_piece)))
            return (-1);
        while (head->piece[++y])
            piece->pos_stars[x][y] = (head->piece[y] == '*') ? y : -1;
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
        map->map_chaleur = NULL;
        map->me_list = NULL;
        map->ennemi_list = NULL;
        map->x_map = -1;
        map->y_map = -1;
        map->me = (player == 1) ? 'O' : 'X';
        map->ennemi = (player == 1) ? 'X' : 'O';
        piece->x_piece = -1;
        piece->y_piece = -1;
        piece->x_best_pos = -1;
        piece->y_best_pos = -1;
        piece->x_final_pos = -1;
        piece->y_final_pos = -1;
        return (1);
    }
    else
        return (0);
}

void    print_fd(int fd, t_coor map, t_coor_piece piece)
{
        int x;
        int y;

        // x = 0;
        // ft_fprintf("map_chaleur     = x = %d, y = %d\n", fd, map.x_map, map.y_map);
        // ft_fprintf("\n", fd);
        // while (x < map.x_map)
        // {
            // y = 0;
            // while (y < map.y_map)
            // {
                // if (map.me_list[x][y] != -1)
                    // ft_fprintf("me_list         = x = %d, y = %d\n", fd, x, map.me_list[x][y]);
                // y++;
            // }
            // x++;
        // }
        // x = 0;
        // ft_fprintf("\n", fd);
        // while (x < map.x_map)
        // {
            // y = 0;
            // while (y < map.y_map)
            // {
                // if (map.ennemi_list[x][y] > -1)
                    // ft_fprintf("ennemi_list     = x = %d, y = %d\n", fd, x, map.ennemi_list[x][y]);
                // else if (map.ennemi_list[x][y] == -4)
                    // ft_fprintf("ennemi_list     = x = %d, y = %d = %d\n", fd, x, y, map.ennemi_list[x][y]);
                // y++;
            // }
            // x++;
        // }
        x = 0;
        ft_fprintf("\n", fd);
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                ft_fprintf("%3d", fd, map.map_chaleur[x][y]);
                y++;
                if (y == map.y_map)
                    ft_fprintf("\n", fd);
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
        x = 0;
        ft_fprintf("\n", fd);
        ft_fprintf("best_pos_me    = x = %d, y = %d\n", fd, piece.x_best_pos, piece.y_best_pos);
        ft_fprintf("\n", fd);
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                if (piece.final_pos[x][y] != -1)
                    ft_fprintf("final_pos[x][y]  = x = %d, y = %d | %d\n", fd, x, piece.final_pos[x][y], map.map_chaleur[x][y]);
                y++;
            }
            x++;
        }
        ft_fprintf("\n", fd);
        x = 0;
        while (x < map.x_map)
        {
            y = 0;
            while (y < map.y_map)
            {
                if (piece.last_best_pos[x][y] != -1)
                    ft_fprintf("last_best_pos = x = %d, y = %d\n", fd, x, y);
                y++;
            }
            x++;
        }

        ft_fprintf("<got (%c): [%d, %d]\n", fd, map.me, piece.x_final_pos, piece.y_final_pos);
    
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
       if (!(init_list_filler(&map, &piece, (ft_strstr(line, "p1")) ? 1 : 2)))
            ft_fprintf("error_init_list\n", 2);
        free(line);
        line = NULL;
    }
    while (get_next_line(0, &line))
    {
        etapes += parsing_map(&map, line);
        etapes += parsing_piece(&piece, line);
        if (etapes == 1)
        {
            tab_int(&map, map.me);
            tab_int(&map, map.ennemi);
            if (!(map_chaleur_horizontal(&map)))
                ft_fprintf("error_horizontal\n", 2);
            if (!(map_chaleur_vertical(&map)))
                ft_fprintf("error_vertical\n", 2);
            if (!(check_position_right_down(&map)))
                ft_fprintf("error_right_down\n", 2);
            if (!(check_position_left_up(&map)))
                ft_fprintf("error_left_up\n", 2);
            if (!(check_position_right_up(&map)))
                ft_fprintf("error_right_up\n", 2);
            if (!(check_position_left_down(&map)))
                ft_fprintf("error_left_down\n", 2);
        }
        else if (etapes == 2)
        {
            pos_piece(&piece);
            init_last_best_pos(&map, &piece);
            while (piece.x_final_pos == -1 && piece.y_final_pos == -1)
            {
                ft_fprintf("\n%d ", fd, check_around_pos(&map, &piece));
                ft_fprintf("%d ", fd, final_pos_piece(&map, &piece));                
                ft_fprintf("%d ", fd, next_pos_stars(&map, &piece));
                ft_fprintf("%d ", fd, check_around_best_pos(&map, &piece));
                ft_fprintf("%d ", fd, nb_tab(&map, &piece, piece.final_pos));
                if (!nb_tab(&map, &piece, piece.final_pos))
                    piece.last_best_pos[piece.x_best_pos][piece.y_best_pos] = piece.y_best_pos;
                ft_fprintf("%d\n", fd, check_pos_final(&map, &piece));
                if (nb_tab(&map, &piece, map.me_list) == nb_tab(&map, &piece, piece.final_pos))
                    break;
                print_fd(fd, map, piece);
                free_tab_int(piece.final_pos);
            }
            if (piece.x_final_pos >= 0 && piece.y_final_pos >= 0)
            {
                ft_printf("%d %d\n", piece.x_final_pos, piece.y_final_pos);
                ft_fprintf("%d %d\n", fd, piece.x_final_pos, piece.y_final_pos);
            }
            else 
                ft_printf("%d %d\n", 0, 0);
            etapes = 0;
            erase_list(&map, &piece);
            free_tab_int(map.me_list);
            free_tab_int(map.ennemi_list);
            free_tab_int(map.map_chaleur);
            free_tab_int(piece.last_best_pos);
            free_tab_int(piece.pos_stars);
            piece.x_final_pos = -1;
            piece.y_final_pos = -1;
        }
        if (etapes < 0)
            exit(1);
    }
    // close(fd);
    return (0);
}
