/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:51:02 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/17 19:51:05 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filler.h"

void    print_fd(int fd, t_coor map, t_coor_piece piece)
{
        int x;
        int y;

        x = 0;
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
        x = 0;
        ft_fprintf("\n", fd);
        while (x < map.x_map - 1)
        {
            y = 0;
            while (y < map.y_map - 1)
            {
                if (map.ennemi_list[x][y] > -1)
                    ft_fprintf("ennemi_list     = x = %d, y = %d\n", fd, x, map.ennemi_list[x][y]);
                else if (map.ennemi_list[x][y] == -4)
                    ft_fprintf("ennemi_list     = x = %d, y = %d = %d\n", fd, x, y, map.ennemi_list[x][y]);
                y++;
            }
            x++;
        }
        x = 0;
        ft_fprintf("\n", fd);
        while (x < map.x_map - 1)
        {
            y = 0;
            while (y < map.y_map - 1)
            {
                ft_fprintf("%3d", fd, map.map_chaleur[x][y]);
                y++;
                if (y == map.y_map - 1)
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
        x = -1;
        ft_fprintf("\n", fd);
        ft_fprintf("best_pos_me    = x = %d, y = %d\n", fd, piece.x_best_pos, piece.y_best_pos);
        ft_fprintf("\n", fd);
        while (++x < map.x_map - 1)
        {
            y = -1;
            while (++y < map.y_map - 1)
            {
                if (piece.final_pos[x][y] != -1)
                    ft_fprintf("final_pos[x][y]  = x = %d, y = %d | %d\n", fd, x, y, map.map_chaleur[x][y]);
            }
        }
        ft_fprintf("\n", fd);
        x = 0;
        while (x < map.x_map - 1)
        {
            y = 0;
            while (y < map.y_map - 1)
            {
                if (piece.last_best_pos[x][y] != -1)
                    ft_fprintf("last_best_pos = x = %d, y = %d\n", fd, x, y);
                y++;
            }
            x++;
        }
        ft_fprintf("<got (%c): [%d, %d]\n", fd, map.me, piece.x_final_pos, piece.y_final_pos);
    
}