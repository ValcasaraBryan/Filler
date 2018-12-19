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

int         main(void)
{
    char    *line;
    int     etapes;
    t_coor          map;
    t_coor_piece    piece;

    etapes = 0;
    if (get_next_line(0, &line))
    {
        if (!(init_list_filler(&map, &piece, (ft_strstr(line, "p1")) ? 1 : 2)))
            ft_fprintf("error_init_list\n", 2);
        free_line(&line);
    }
    while (get_next_line(0, &line))
    {
        etapes += parsing_map(&map, &line);
        etapes += parsing_piece(&piece, &line);
        if (etapes == 1)
        {
            tab_int(&map, map.me);
            tab_int(&map, map.ennemi);
            if (!(map_chaleur_horizontal(&map)))
                ft_printf("error_horizontal\n");
            if (!(map_chaleur_vertical(&map)))
                ft_printf("error_vertical\n");
            if (!(check_position_right_down(&map)))
                ft_printf("error_right_down\n");
            if (!(check_position_left_up(&map)))
                ft_printf("error_left_up\n");
            if (!(check_position_right_up(&map)))
                ft_printf("error_right_up\n");
            if (!(check_position_left_down(&map)))
                ft_printf("error_left_down\n");
            after_mappage(&map);
        }
        else if (etapes == 2)
        {
            pos_piece(&piece);
            init_last_best_pos(&map, &piece);
            final_pos_piece(&map, &piece);
            while (piece.x_final_pos == -1 && piece.y_final_pos == -1)
            {
                if (!(check_around_pos(&map, &piece)))
                    break;
                next_pos_stars(&map, &piece);
                check_around_best_pos(&map, &piece);
                nb_tab(&map, piece.final_pos);
                if (!nb_tab(&map, piece.final_pos))
                    if (piece.y_best_pos >= 0 && piece.y_best_pos < map.y_map)
                        if (piece.x_best_pos >= 0 && piece.x_best_pos < map.x_map)
                            piece.last_best_pos[piece.x_best_pos][piece.y_best_pos] = piece.y_best_pos;
                check_pos_final(&map, &piece);
                if (nb_tab(&map, map.me_list) > ((map.x_map / 2) * map.y_map) + (map.x_map % 2))
                    break;
                else if (nb_tab(&map, map.me_list) == nb_tab(&map, piece.final_pos))
                    break;
            }
            etapes = 0;
            erase_list(&map, &piece);
            free_tab_int(map.me_list, map.x_map);
            free_tab_int(map.ennemi_list, map.x_map);
            free_tab_int(piece.pos_stars, piece.x_piece);
            free_tab_int(map.map_chaleur, map.x_map);
            free_tab_int(piece.last_best_pos, map.x_map);
            free_tab_int(piece.final_pos, map.x_map);
            if (piece.x_final_pos >= 0 && piece.y_final_pos >= 0)
                ft_print(piece.x_final_pos, piece.y_final_pos);
            else
            {
                ft_print(0, 0);
                break;
            }
            piece.y_final_pos = -1;
            piece.x_final_pos = -1;
        }
        free_line(&line);
    }
    free_line(&line);
    get_next_line(0, &line);
    return (0);
}
