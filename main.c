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
        // ft_fprintf("entree_parsing_map\n", 2);
        etapes += parsing_map(&map, line);
        // ft_fprintf("sorti_parsing_map\n", 2);
        // ft_fprintf("entree_parsing_piece\n", 2);
        etapes += parsing_piece(&piece, line);
        // ft_fprintf("sorti_parsing_piece\n", 2);
        if (etapes == 1)
        {
            tab_int(&map, map.me);
            tab_int(&map, map.ennemi);
            if (!(map_chaleur_horizontal(&map)))
                ft_printf("error_horizontal\n");
            if (!(map_chaleur_vertical(&map)))
                ft_printf("error_vertical\n");
            // ft_fprintf("entree_right_down\n", 2);
            if (!(check_position_right_down(&map)))
                ft_printf("error_right_down\n");
            // ft_fprintf("sorti_right_down\n", 2);
            // ft_fprintf("entree_left_up\n", 2);
            if (!(check_position_left_up(&map)))
                ft_printf("error_left_up\n");
            // ft_fprintf("sorti_left_up\n", 2);
            // ft_fprintf("entree_right_up\n", 2);
            if (!(check_position_right_up(&map)))
                ft_printf("error_right_up\n");
            // ft_fprintf("sorti_right_up\n", 2);
            // ft_fprintf("entree_left_down\n", 2);
            if (!(check_position_left_down(&map)))
                ft_printf("error_left_down\n");
            // ft_fprintf("sorti_left_down\n", 2);
            // ft_fprintf("entree_after_mappage\n", 2);
            after_mappage(&map);
            // ft_fprintf("sorti_after_mappage\n", 2);
        }
        else if (etapes == 2)
        {
            // ft_fprintf("entree_pos_piece\n", 2);
            pos_piece(&piece);
            // ft_fprintf("sorti_pos_piece\n", 2);
            // ft_fprintf("entree_init_last_best_pos\n", 2);
            init_last_best_pos(&map, &piece);
            // ft_fprintf("sorti_init_last_best_pos\n", 2);
            // ft_fprintf("entree_final_pos_piece\n", 2);
            final_pos_piece(&map, &piece);
            // ft_fprintf("sorti_final_pos_piece\n", 2);
            while (piece.x_final_pos == -1 && piece.y_final_pos == -1)
            {
                // ft_fprintf("entree_check_around_pos\n", 2);
                if (!(check_around_pos(&map, &piece)))
                    break;
                // ft_fprintf("sorti_check_around_pos\n", 2);
                // ft_fprintf("entree_next_pos_stars\n", 2);
                next_pos_stars(&map, &piece);
                // ft_fprintf("sorti_next_pos_stars\n", 2);
                // ft_fprintf("entree_check_around_best_pos\n", 2);
                check_around_best_pos(&map, &piece);
                // ft_fprintf("sorti_check_around_best_pos\n", 2);
                // ft_fprintf("entree_nb_tab\n", 2);
                nb_tab(&map, piece.final_pos);
                // ft_fprintf("sorti_nb_tab\n", 2);
                if (!nb_tab(&map, piece.final_pos))
                    piece.last_best_pos[piece.x_best_pos][piece.y_best_pos] = piece.y_best_pos;
                // ft_fprintf("entree_check_pos_final\n", 2);
                check_pos_final(&map, &piece);
                // ft_fprintf("sorti_check_pos_final\n", 2);
                if (nb_tab(&map, map.me_list) > ((map.x_map / 2) * map.y_map) + (map.x_map % 2))
                    ft_print(0, 0);
                if (nb_tab(&map, map.me_list) == nb_tab(&map, piece.final_pos))
                    break;
                print_fd(fd, map, piece);
            }
            if (piece.x_final_pos >= 0 && piece.y_final_pos >= 0)
                ft_print(piece.x_final_pos, piece.y_final_pos);
            else 
                ft_print(0, 0);
            etapes = 0;
            // ft_fprintf("entree_erase_list\n", 2);
            erase_list(&map, &piece);
            // ft_fprintf("sorti_erase_list\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(map.me_list, map.x_map);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(map.ennemi_list, map.x_map);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(piece.pos_stars, piece.x_piece);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(map.map_chaleur, map.x_map);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(piece.last_best_pos, map.x_map);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            // ft_fprintf("entree_free_tab_int\n", 2);
            free_tab_int(piece.final_pos, map.x_map);
            // ft_fprintf("sorti_free_tab_int\n", 2);
            piece.y_final_pos = -1;
            piece.x_final_pos = -1;
        }
        // free(line);
    }
    // free(line);
    close(fd);
    return (0);
}
