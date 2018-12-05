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

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <stdio.h>

typedef struct          s_map
{
    char                *map;
    struct s_map        *next;
}                       t_map;

typedef struct          s_tailles
{
    int                 x_map;
    int                 y_map;
    struct  s_map       *map;
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
    struct s_piece      *piece;
}                       t_coor_piece;


#endif
