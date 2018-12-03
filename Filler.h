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

typedef struct          s_piece
{
    char                *piece;
    int                 x;
    int                 y;
    char                me;
    char                vs;
    struct s_piece      *next;
}                       t_piece;


#endif
