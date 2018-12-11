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
# define ME             0;
# define ENNEMI         -1;
# define POS_NULL       -2;

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
    int                 **pos_stars;
    struct s_piece      *piece;
}                       t_coor_piece;


#endif
