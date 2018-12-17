/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:51:59 by brvalcas          #+#    #+#             */
/*   Updated: 2018/12/03 14:52:04 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>

typedef struct          s_map
{
    char                *map;
    struct s_map        *next;
}                       t_map;

typedef struct          s_tailles_map
{
    int                 x_map;
    int                 y_map;
    int                 **map_chaleur;
    char                me;
    char                ennemi;
    struct  s_map       *map;
    int                 **me_list;
    int                 **ennemi_list;
}                       t_coor;

typedef struct          s_piece
{
    char                *piece;
    struct s_piece      *next;
}                       t_piece;

typedef struct          s_tailles_piece
{
    int                 x_piece;
    int                 y_piece;
    int                 x_best_pos;
    int                 y_best_pos;
    int                 x_final_pos;
    int                 y_final_pos;
    int                 **last_best_pos;
    int                 **pos_stars;
    int                 **final_pos;
    struct s_piece      *piece;
}                       t_coor_piece;

int         val_around(t_coor *map, int val, int x, int y);
int         check_position_right_down(t_coor *map);
int         check_position_left_up(t_coor *map);
int         check_position_right_up(t_coor *map);
int         check_position_left_down(t_coor *map);

int         chaleur_down(t_coor *map, int y);
int         chaleur_up(t_coor *map, int y);
int         chaleur_right(t_coor *map, int x);
int         chaleur_left(t_coor *map, int x);
int         after_mappage(t_coor *map);

int         val_player_fct(t_coor *map, int x, int y);
int         map_chaleur_vertical(t_coor *map);
int         map_chaleur_horizontal(t_coor *map);

t_map       *new_map(char *line);
t_map       *add_map(t_map *old, t_map *new);
t_piece     *add_piece(t_piece *old, t_piece *new);
t_piece     *new_piece(char *line);


#endif
